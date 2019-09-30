#ifndef UNIMLAMPWEDGEROOTEVENT_H
#define UNIMLAMPWEDGEROOTEVENT_H

#include <TROOT.h>

class UNIMLampWedgeData
{
public:
  Int_t    fmulti;
  Int_t    *fnumstrip;       //[fmulti]
  Short_t  *fEnergy;         //[fmulti]
  Short_t  *fTime;           //[fmulti]
  double   *fEnergyCal;      //[fmulti]

  UNIMLampWedgeData(int);
  virtual ~UNIMLampWedgeData();

  ClassDef(UNIMLampWedgeData,1);
};

class UNIMLampWedgeRootEvent
{
 private:
 int fNumDetectors;

 public:
 UNIMLampWedgeData fLampWedge;

 UNIMLampWedgeRootEvent(int);
 virtual ~UNIMLampWedgeRootEvent();

 ClassDef(UNIMLampWedgeRootEvent,1);
};

#endif
