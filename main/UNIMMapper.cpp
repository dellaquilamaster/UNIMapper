#include <UNIMMapper.h>

//________________________________________________
UNIMMapper::UNIMMapper() :
fMappedTree(0),
fFileOut(0),
fRunNumber(-1),
fEnergyCalibration(new UNIMCalibration())
{}

//________________________________________________
UNIMMapper::~UNIMMapper()
{}

//________________________________________________
int UNIMMapper::PassArguments(int argc, char** argv)
{
  // Find the --run cmd argument and extract run number
  for(int i=1; i<argc; i++)
  {
    std::string Argument(argv[i]);
    if(Argument.find("--run=")!=std::string::npos) {
      fRunNumber=std::stoi(Argument.substr(Argument.find("--run=")+6));
    }
  }

  if(fRunNumber<0) return -1;
  return 0;
}

//________________________________________________
int UNIMMapper::InitializeMapper(const char * file_config_name)
{
  //Loading configuration file and building RunInfo
  if(LoadExperimentInfo(file_config_name)!=0) return -3;

  //Building Experimental Setup
  if(BuildExperimentalSetup()!=0) return -1;
  
  //Initializing Calibrations
  if(fEnergyCalibration->LoadCalibration(gRun->GetEnergyCalibrationFile())<=0) {
    printf("UNIMMapper> WARNING: Failed to load calibrations from file %s, skipping calibrations!\n", gRun->GetEnergyCalibrationFile());
  } else {
    printf("UNIMMapper: Energy calibrations sucessfully loaded from file %s\n", gRun->GetEnergyCalibrationFile());
  }
  
  //Initializing output TFile and TTree
  if(InitRootOutput()!=0) return -2;

  return 0;
}

//________________________________________________
int UNIMMapper::LoadExperimentInfo(const char * file_name)
{
  //Initialization of RBRunInfo class
  std::cout << "** Initializing Run Info **\n";
  gRun = new UNIMRunInfo(fRunNumber);
  if(gRun->InitClass("config/UNIMapper.conf")<=0) {
    std::cout << "Error while reading configuration file.\n";
    exit (-1);
  }
  std::cout << "** Run Info correctly initialized **\n";

  return 0;
}

//________________________________________________
int UNIMMapper::BuildExperimentalSetup()
{
  gExpSetup=new UNIMExperimentalSetup();

  if(gExpSetup==0) return -1;

  if(gExpSetup->BuildDetectors()<=0) return -2;

  if(gExpSetup->BuildDetectorMaps()<=0) return -3;

  return 0;
}

//________________________________________________
int UNIMMapper::InitRootOutput()
{
  // Opening a new TFile for output
  fFileOut = new TFile(Form("%srun-%04d.root", gRun->GetUNIMapperROOTFilePath(), fRunNumber), "RECREATE");
  if(fFileOut->IsZombie()) return -1; //failed to open TFile

  // Creating output TTree
  fMappedTree = new TTree(Form("%s",gRun->GetName()), gRun->GetTitle(),2);
  fMappedTree->SetAutoSave(50000000);

  //call individual detectors InitTTreeBranch
  gExpSetup->InitDetectorBranches(fMappedTree);

  printf("UNIMMapper: Opened ROOT file %s\n", Form("%srun-%04d.root", gRun->GetUNIMapperROOTFilePath(), fRunNumber));

  return 0;
}

//________________________________________________
TTree * UNIMMapper::GetMappedTree() const
{
  return fMappedTree;
}

//________________________________________________
void UNIMMapper::EndMapping()
{
  //Writing TTree to file and close file
  fMappedTree->AutoSave();
  fMappedTree->GetCurrentFile()->Close();
  
  printf("\nUNIMMapper: Produced ROOT file %s\n", Form("%srun-%04d.root", gRun->GetUNIMapperROOTFilePath(), fRunNumber));

  return;
}

//________________________________________________
void UNIMMapper::MapDetectors(UNIMMidasModule * TheEvent)
{
  //List of defined detectors
  std::map<std::string, UNIMDetector *> * DefinedDetectors = gExpSetup->GetDetectors();
  
  //Loop over the defined detectors to call their individual UNIMDetector::Clear() methods
  for(std::map<std::string, UNIMDetector *>::iterator TheDetector=DefinedDetectors->begin(); TheDetector!=DefinedDetectors->end(); TheDetector++)
  {
    (TheDetector)->second->Clear();
  }
  
  //Loop over the event multiplicity to store data in specific detector channels
  for(int i=0; i<TheEvent->GetMulti(); i++) {
    UNIMMapElement * TheMapAssociation = gExpSetup->GetMapping()->GetAssociation(TheEvent->GetGid(i),TheEvent->GetCh(i));
    if(TheMapAssociation==0) {
      //Mapping is missing for this channel
      if(gRun->GetEmptyMappingWarning()) printf("\nUNIMMapper> WARNING: Detector mapping missing for gid=%d ch=%d -> skipping this entry!\n", TheEvent->GetGid(i),TheEvent->GetCh(i));
      continue; 
    }
    TheMapAssociation->GetDetector()->SetQuantity(TheMapAssociation->GetQuantity(), TheMapAssociation->GetUnit(), TheEvent->GetAmpl(i));    
  }
  
  //Loop over the defined detectors to call their individual UNIMDetector::BuildEvent() methods
  for(std::map<std::string, UNIMDetector *>::iterator TheDetector=DefinedDetectors->begin(); TheDetector!=DefinedDetectors->end(); TheDetector++)
  {
    (TheDetector)->second->BuildEvent(fEnergyCalibration);
  }
  
  return;
}

//________________________________________________
void UNIMMapper::FillMappedEvent()
{
  //Calling TTree::Fill() with mapped data
  fMappedTree->Fill();

  return;
}
