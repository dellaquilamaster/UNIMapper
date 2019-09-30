#include <UNIMExperimentalSetup.h>

//________________________________________________
UNIMExperimentalSetup::UNIMExperimentalSetup() :
fDetectors(new std::map<std::string, UNIMDetector *>),
fDetectorMaps(new UNIMDetectorMap())
{}

//________________________________________________
UNIMExperimentalSetup::~UNIMExperimentalSetup()
{
  printf("distruggo il setuppe\n");
  
  for(std::map<std::string, UNIMDetector *>::iterator TheModule=fDetectors->begin(); TheModule!=fDetectors->end(); TheModule++) {
      delete (*TheModule).second;
  }
  delete fDetectors;
  delete fDetectorMaps;
  
  printf("finito di distrurre il setuppe\n");
}

//________________________________________________
int UNIMExperimentalSetup::BuildDetectors()
{
  std::ifstream FileIn(gRun->GetMappingFile());
  if(!FileIn.is_open()) {
    printf("UNIMExperimentalSetup: Failed to build detectors, error while opening %s file\n", gRun->GetMappingFile());
    return -1;
  }

  while (!FileIn.eof())
  {
    std::string LineRead;
    std::getline(FileIn, LineRead);
    std::string LineReadCommentLess(LineRead.substr(0,LineRead.find("*")));

    if(LineReadCommentLess.empty()) continue;

    if(LineReadCommentLess.find_first_not_of(' ') == std::string::npos) continue;

    if(LineReadCommentLess.find("define ")!=std::string::npos) {
      ParseDefineMappingLine(LineReadCommentLess.c_str());
    }
  }
  FileIn.close();

  printf("UNIMExperimentalSetup: Built %lu detectors from file %s\n", fDetectors->size(), gRun->GetMappingFile());
  return fDetectors->size();
}

//________________________________________________
int UNIMExperimentalSetup::ParseDefineMappingLine(const char * line_to_parse)
{
  std::string LineReadCommentLess(line_to_parse);

  int NDets=fDetectors->size();

  if(LineReadCommentLess.find("detector ")!=std::string::npos) {
    LineReadCommentLess.assign(LineReadCommentLess.substr(LineReadCommentLess.find("detector ")+9));
    std::istringstream LineStream(LineReadCommentLess);
    std::string DetectorType;
    std::string DetectorName;
    LineStream>>DetectorType>>DetectorName;

    DetectorName.assign(DetectorName.substr(DetectorName.find("\"")+1,DetectorName.find_last_of("\"")-(DetectorName.find("\"")+1)));

    if(DetectorType.compare("DSSSD")==0) {
      int NumStrips;
      LineStream>>NumStrips;
      UNIMDSSSD * newDetector = new UNIMDSSSD(DetectorName.c_str(), NumStrips);
      (*fDetectors)[DetectorName]=newDetector;
    } if(DetectorType.compare("SSSSD")==0) {
      int NumStrips;
      LineStream>>NumStrips;
      UNIMSSSD * newDetector = new UNIMSSSD(DetectorName.c_str(), NumStrips);
      (*fDetectors)[DetectorName]=newDetector;
    } if(DetectorType.compare("LampWedge")==0) {
      int NumStrips;
      LineStream>>NumStrips;
      UNIMLampWedge * newDetector = new UNIMLampWedge(DetectorName.c_str(), NumStrips);
      (*fDetectors)[DetectorName]=newDetector;
    }
  }

  return fDetectors->size()-NDets;
}

//________________________________________________
int UNIMExperimentalSetup::BuildDetectorMaps()
{
  // We build here the UNIMDetectorMap object that will 
  // contain the mapping for each individual detector
  
  //Setting detectors to the detector map object
  fDetectorMaps->SetDetectors(fDetectors);
  
  //Loading the detector mapping from file
  return fDetectorMaps->LoadMapping(gRun->GetMappingFile());
}

//________________________________________________
std::map<std::string, UNIMDetector *> * UNIMExperimentalSetup::GetDetectors() const
{
  return fDetectors;
}

//________________________________________________
UNIMDetector * UNIMExperimentalSetup::GetDetector(const char * name) const
{
  return (*fDetectors)[name];
}

//________________________________________________
UNIMDetectorMap * UNIMExperimentalSetup::GetMapping()
{
  return fDetectorMaps;
}

//________________________________________________
UNIMDetector * UNIMExperimentalSetup::GetDetector(std::string name) const
{
  return (*fDetectors)[name];
}

//________________________________________________
int UNIMExperimentalSetup::GetNDetectors() const
{
  return fDetectors->size();
}

//________________________________________________
void UNIMExperimentalSetup::InitDetectorBranches(TTree * theTree)
{
  //Loop over all the define detectors to call their individual InitTTreeBranch(TTree *)
  if(fDetectors) {
    for(std::map<std::string, UNIMDetector *>::iterator TheDetector=fDetectors->begin(); TheDetector!=fDetectors->end(); TheDetector++) {
      (*TheDetector).second->InitTTreeBranch(theTree);
    }
  }
}
