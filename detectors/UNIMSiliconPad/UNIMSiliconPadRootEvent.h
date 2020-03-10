#ifndef UNIMSILICONPADROOTEVENT_H
#define UNIMSILICONPADROOTEVENT_H

#include <TROOT.h>

class UNIMSiliconPadData
{
public:
  Short_t  fEnergy;         //
  Short_t  fTime;           //
  double   fEnergyCal;      //

  UNIMSiliconPadData();
  virtual ~UNIMSiliconPadData();

  ClassDef(UNIMSiliconPadData,1);
};

class UNIMSiliconPadRootEvent
{
 private:

 public:
 UNIMSiliconPadData fSiliconPad;

 UNIMSiliconPadRootEvent();
 virtual ~UNIMSiliconPadRootEvent();

 ClassDef(UNIMSiliconPadRootEvent,1);
};

#endif
