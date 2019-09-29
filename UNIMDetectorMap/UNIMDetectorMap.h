#ifndef UNIMDETECTORMAP_H
#define UNIMDETECTORMAP_H

#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <UNIMMapElement.h>
#include <UNIMDetector.h>
#include <UNIMShared.h>

class UNIMDetectorMap
{
public :
  UNIMDetectorMap();                                              //! Constructor
  virtual ~UNIMDetectorMap();                                     //! Destructor

  void SetDetectors(std::map<std::string, UNIMDetector *> *);     //! Called by UNIMExperimentalSetup::BuildDetectorMaps
  int LoadMapping(const char *);                                  //! Loads detector mapping. Calls individual ParseAssignLine and ParseMapLine of the specific detector mappings
  
  UNIMMapElement * GetAssociation(int gid, int ch);               //! Get mapping for a certain gid and ch
  void SetMapping(int gid, int ch, UNIMMapElement *);             //! Set the mapping element to a certain gid and ch
  bool IsMapped(int gid, int ch);                                 //! false if the ch is not mapped, otherwise true

private :
  std::map<int, std::map<int, UNIMMapElement *> *> fTheMapping;   //! The Mapping information gid, ch -> UNIMMapElement
  std::map<std::string, UNIMDetector *> * fTheDetectors;          //! The Detectors as constructed by UNIMExperimentalSetup::BuildDetectors

  int ParseMapLine(const char *);                                 //! Parse Detector map line, these lines associate detector quantiites to each individual gd, ch pair

};

#endif
