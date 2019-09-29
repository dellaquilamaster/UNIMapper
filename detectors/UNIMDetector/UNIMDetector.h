#ifndef UNIMDETECTOR_H
#define UNIMDETECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <TTree.h>

class UNIMDetector
{
public :
  UNIMDetector(const char *, int num_detectors=0);       //!Constructor
  virtual ~UNIMDetector();                               //!Destructor

  virtual void Clear();                                  //!Clear detector data to -9999

  const char * GetName() const;                          //!Returns detector name
  const char * GetType() const;                          //!Returns detector type
  int GetNumDetectors() const;                           //!Get number of individual detection objects (e.g. strips)
  
  virtual void SetQuantity(const char *, int, Short_t);  //!Individually implemented in specific detector classes 

  virtual void InitTTreeBranch(TTree *);                 //!Individually implemented in specific detector classes
  virtual void BuildEvent();                             //!Individually implemented in specific detector classes
  virtual void FillMappedData();                         //!Individually implemented in specific detector classes

protected :
  std::string fName;                                     //!Detector Name
  std::string fType;                                     //!Detector Type
  int fNumDetectors;                                     //!Number of individual detection objects (e.g. strips)
};

#endif
