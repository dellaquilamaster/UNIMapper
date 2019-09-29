#ifndef UNIMDSSSDROOTEVENT_H
#define UNIMDSSSDROOTEVENT_H

#include <TROOT.h>

class UNIMDSSSDData
{
public:
  Int_t    fmultif;
  Int_t    *fnumstripf;       //[fmultif]
  Short_t  *fEnergyFront;    //[fmultif]
  Short_t  *fTimeFront;      //[fmultif]
  double   *fEnergyFrontCal; //[fmultif]
  Int_t    fmultib;
  Int_t    *fnumstripb;       //[fmultif]
  Short_t  *fEnergyBack;     //[fmultib]
  Short_t  *fTimeBack;       //[fmultib]
  double   *fEnergyBackCal;  //[fmultib]

  UNIMDSSSDData(int);
  virtual ~UNIMDSSSDData();

  ClassDef(UNIMDSSSDData,1);
};

class UNIMDSSSDRootEvent
{
 private:
 int fNumDetectors;

 public:
 UNIMDSSSDData fDSSSD;

 UNIMDSSSDRootEvent(int);
 virtual ~UNIMDSSSDRootEvent();

 ClassDef(UNIMDSSSDRootEvent,1);
};

#endif
