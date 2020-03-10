#ifndef UNIMSILICONSIGNAL_H
#define UNIMSILICONSIGNAL_H

#include <string>
#include <map>
#include <TROOT.h>

class UNIMSiliconSignal
{
public :
  UNIMSiliconSignal();
  ~UNIMSiliconSignal();
  
  void Init();
  void Clear();
  
  void SetEnergy(Short_t);
  void SetTime(Short_t);
  void SetEnergyCal(double);
  
  Short_t GetEnergy() const;
  Short_t GetTime() const;
  double GetEnergyCal() const;
  
private :
  Short_t  fEnergy;
  Short_t  fTime;
  double  fEnergyCal;
};

#endif
