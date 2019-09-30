#include <UNIMRawDataReader.h>

//________________________________________________
UNIMRawDataReader::UNIMRawDataReader() :
fDataMapper(0),
fDataTree(0),
fNEvtFiles(0),
fDataReader(0),
fTheEvent(0),
fTotalEvents(0),
fCurrEvent(0),
fTimeElapsed(0)
{}

//________________________________________________
UNIMRawDataReader::~UNIMRawDataReader()
{
  if(fTheEvent) delete fTheEvent;
  if(fDataReader) delete fDataReader;
}

//________________________________________________
int UNIMRawDataReader::InitReader()
{
  //Opening input TFile and TTree to read data
  if(InitRootInput()<=0) return -2;
  printf("** Correctly retrieved %d file(s) for mapping from folder %s **\n", fNEvtFiles, gRun->GetMidasROOTFilePath());

  //Setting TTreeReader to the opened TChain
  fDataReader=new TTreeReader(fDataTree);
  if(!fDataTree) return -1;
  
  //Configuring Midas event reader
  fTheEvent=new UNIMMidasModule (fDataReader);

  return 0;
}

//________________________________________________
int UNIMRawDataReader::InitRootInput()
{
  // Opening a new TFile for input
  fDataTree = new TChain("Midas");
  fNEvtFiles = fDataTree->Add(Form("%sR%d_*.root", gRun->GetMidasROOTFilePath(), gRun->GetRunNumber()));
  fTotalEvents=fDataTree->GetEntries();
  return fNEvtFiles;
}

//________________________________________________
void UNIMRawDataReader::SetMapper(UNIMMapper * theMapper)
{
  fDataMapper=theMapper;
}

//________________________________________________
void UNIMRawDataReader::ProcessRawTree()
{
  fStartTime = clock(); // initializing start time

  while(fDataReader->Next())
  {
    //Display progress
    if(fCurrEvent%10000==0) {
      double time_elapsed = (double)(clock() - fStartTime)/CLOCKS_PER_SEC;
      std::cout << "  Percentage = " << std::fixed << std::setprecision(1) << std::setw(5) << (100*double(fCurrEvent)/fTotalEvents) << " %";
      std::cout << "   [";
      int printindex=0;
      for(; printindex<int(100*double(fCurrEvent)/fTotalEvents); printindex+=5) std::cout << "=";
      for(; printindex<100; printindex+=5) std::cout << " ";
      std::cout << "]   " << "elapsed time " << std::setprecision(1) <<
      (time_elapsed<60 ? time_elapsed : (time_elapsed<3600 ? time_elapsed/60 : time_elapsed/3600)) <<
      (time_elapsed<60 ? " s; " : (time_elapsed<3600 ? " m; " : " h; "));
      if(fCurrEvent>0) {
        double time_remaining = (time_elapsed/fCurrEvent)*(fTotalEvents-fCurrEvent);
        std::cout << " estimated remaining time " << std::setprecision(1) <<
        (time_remaining<60 ? time_remaining : (time_remaining<3600 ? time_remaining/60 : time_remaining/3600)) <<
        (time_remaining<60 ? " s      " : (time_remaining<3600 ? " m      " : " h      "));
      }
      std::cout << "\r";
      std::cout.flush();
    }

    //Map all the detectors
    fDataMapper->MapDetectors(fTheEvent);

    //Fill the mapped tree entry
    fDataMapper->FillMappedEvent();

    fCurrEvent++;
  }
}

//________________________________________________
void UNIMRawDataReader::EndProcess()
{
  if(fDataTree) delete fDataTree;
  fDataMapper->EndMapping();
  PrintSummary();
}

//________________________________________________
void UNIMRawDataReader::PrintSummary()
{
  // -- This method print a general final summary of the mapping procedure
  std::cout << "\n\n--Mapping summary--" << std::endl;
  printf("Mapping time : %.0f s\n", fTimeElapsed);
  printf("%llu events mapped\n", fCurrEvent);
  printf("--End of Mapping--\n\n");
}
