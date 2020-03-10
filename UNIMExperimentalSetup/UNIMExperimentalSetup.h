#ifndef UNIMEXPERIMENTALSETUP_H
#define UNIMEXPERIMENTALSETUP_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <UNIMDetector.h>
#include <UNIMDSSSD.h>
#include <UNIMSSSSD.h>
#include <UNIMLampWedge.h>
#include <UNIMSiliconPad.h>
#include <UNIMSpare.h>
#include <UNIMDetectorMap.h>
#include <UNIMRunInfo.h>
#include <UNIMShared.h>

class UNIMExperimentalSetup
{
public :
  UNIMExperimentalSetup();                                           //!Constructor
  ~UNIMExperimentalSetup();                                          //!Destructor

  int BuildElectronicModules();                                      //!Called by UNIMMapper::BuildExperimentalSetup()
  int BuildDetectors();                                              //!Called by UNIMMapper::BuildExperimentalSetup()
  int BuildDetectorMaps();                                           //!Called by UNIMMapper::BuildExperimentalSetup()
  void InitDetectorBranches(TTree *);                                //!Called by UNIMMapper::InitRootOutput()

  std::map<std::string, UNIMDetector *> * GetDetectors() const;      //!Get a std::map<std::string, UNIMDetector *> pointer to the defined modules
  UNIMDetector * GetDetector(std::string) const;                     //!Get a detector by name
  UNIMDetector * GetDetector(const char *) const;                    //!Get a detector by name
  int GetNDetectors() const;                                         //!Get the number of defined detectors
  UNIMDetectorMap * GetMapping();                                    //!Get a pointer to the detector map

private :
  std::map<std::string, UNIMDetector *> *fDetectors;
  UNIMDetectorMap *fDetectorMaps;

  int ParseDefineMappingLine(const char *);                          //!Parse a define line in .map file. Returns 1 if a detector is add, otherwise 0.
};

#endif
