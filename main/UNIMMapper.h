#ifndef UNIMMAPPER_H
#define UNIMMAPPER_H

/* 
 * class UNIMMapper
 * created by Daniele Dell'Aquila (daniele.dellaquila@irb.hr)
 */

#include <TTree.h>
#include <TFile.h>
#include <UNIMRunInfo.h>
#include <UNIMMidasModule.h>
#include <UNIMExperimentalSetup.h>
#include <UNIMShared.h>

class UNIMMapper
{
public :
  UNIMMapper();                                //! Constructor
  ~UNIMMapper();                               //! Destructor

  int PassArguments(int, char **);             //! Retrieves run number to analyze. Returns -1 if run number is not found

  TTree * GetRawTree() const;                  //! Returns a pointer to the TTree containing data to map
  TTree * GetMappedTree() const;               //! Returns a pointer to the TTree containing mapped data

  int InitializeMapper(const char *);          //! Called at the beginning of the entire mapping process. Returns -1 if failed to build experimental setup, returns -2 if failed to open output file, returns -3 if failed to load experiment info
  int LoadExperimentInfo(const char *);        //! Initialize experiment info
  int BuildExperimentalSetup();                //! Initialize ExperimentalSetup. Returns -1 if failed to allocate experimental setup, -2 failed to build detectors, -3 failed to build detector map.
  int InitCalibrationModule();                 //! Intialize the UNIMCalibration object. Returns -1 if failed to Initialize the module (e.g. missing calibration)
  int InitRootOutput();                        //! Initialize ROOT TTree and TFile for output

  void MapDetectors(UNIMMidasModule *);        //! Called Event-by-event by UNIMRawDataReader
  void FillMappedEvent();                      //! Called Event-by-event after mapping detectors by UNIMDataReader
  void EndMapping();                           //! Called at the end of the entire mapping process by UNIMDataReader

private :
  TTree * fMappedTree;                         //! TTree with mapped data
  TFile * fFileOut;                            //! TFile for output
  int fRunNumber;                              //! Run number to analyze
  UNIMCalibration * fEnergyCalibration;        //! The calibration module (energy calibration)

};

#endif
