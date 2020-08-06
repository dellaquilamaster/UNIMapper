#ifndef UNIMSILICONHODOSCOPEROOTEVENT_H
#define UNIMSILICONHODOSCOPEROOTEVENT_H

#include <TROOT.h>

class UNIMSiliconHodoscopeData
{
public:
  Int_t    fmulti;
  Int_t    *fnumpad;         //[fmulti]
  Short_t  *fEnergy;         //[fmulti]
  Short_t  *fTime;           //[fmulti]
  double   *fEnergyCal;      //[fmulti]

  UNIMSiliconHodoscopeData(int);
  UNIMSiliconHodoscopeData();
  virtual ~UNIMSiliconHodoscopeData();

  ClassDef(UNIMSiliconHodoscopeData,1);
};

class UNIMSiliconHodoscopeRootEvent
{
 private:
   int fNumDetectors;

 public:
 UNIMSiliconHodoscopeData fSiliconHodoscope;

 UNIMSiliconHodoscopeRootEvent(int);
 virtual ~UNIMSiliconHodoscopeRootEvent();

 ClassDef(UNIMSiliconHodoscopeRootEvent,1);
};

#endif
