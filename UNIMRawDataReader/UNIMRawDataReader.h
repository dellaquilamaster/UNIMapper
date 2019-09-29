#ifndef UNIMRAWDATAREADER_H
#define UNIMRAWDATAREADER_H

#include <iostream>
#include <UNIMShared.h>
#include <UNIMMapper.h>
#include <TTreeReader.h>
#include <TTreeReaderArray.h>
#include <TTree.h>
#include <TChain.h>
#include <ctime>
#include <map>
#include <UNIMExperimentalSetup.h>

class UNIMRawDataReader
{
public :
  UNIMRawDataReader();                //!Constructor
  ~UNIMRawDataReader();               //!Destructor

  int InitReader();                   //!Called after mapper and input tree are set to initialize input tree branches. Returns -1 if failed to create TTreeReader. -2 failed to retrieve Root input file(s)
  int InitRootInput();                //!Initialize ROOT TTree and TFile for input, returns the number of files retrieved
  void SetMapper(UNIMMapper *);       //!Called at the beginning of the unpacking process to set the Mapper
  void ProcessRawTree();              //!Executes event-by-event UNIMMapper::MapDetectors() and UNIMMapper::FillMappedEvent()
  void EndProcess();                  //!Called at the end of the mapping process. It calls UNIMMapper::EndMapping()
  void PrintSummary();                //!Print Mapping summary

private :
  UNIMMapper * fDataMapper;           //!the mapper
  TChain * fDataTree;                 //!tree with raw data
  int fNEvtFiles;                     //!Number of evt files in the run
  TTreeReader *fDataReader;           //!TTreeReader object to read data from fDataTree
  UNIMMidasModule * fTheEvent;        //!UNIMMidasModule object containing the event
  unsigned long long fTotalEvents;    //!Total events to map
  unsigned long long fCurrEvent;      //!Current Event to map
  clock_t fStartTime;                 //!number of clocks since the start of the program when the ProcessRawTree begins
  double fTimeElapsed;                //!Total elapsed time for Raw tree process

};

#endif
