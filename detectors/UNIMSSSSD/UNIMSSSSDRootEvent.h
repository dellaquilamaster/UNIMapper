#ifndef UNIMSSSSDROOTEVENT_H
#define UNIMSSSSDROOTEVENT_H

#include <TROOT.h>

class UNIMSSSSDData
{
public:
  Int_t    fmulti;
  Int_t    *fnumstrip;       //[fmulti]
  Short_t  *fEnergy;         //[fmulti]
  Short_t  *fTime;           //[fmulti]
  double   *fEnergyCal;      //[fmulti]

  UNIMSSSSDData(int);
  virtual ~UNIMSSSSDData();

  ClassDef(UNIMSSSSDData,1);
};

class UNIMSSSSDRootEvent
{
 private:
 int fNumDetectors;

 public:
 UNIMSSSSDData fSSSSD;

 UNIMSSSSDRootEvent(int);
 virtual ~UNIMSSSSDRootEvent();

 ClassDef(UNIMSSSSDRootEvent,1);
};

#endif
