#ifndef UNIMSTRIPARRAY_H
#define UNIMSTRIPARRAY_H

#include <string>
#include <map>
#include <TROOT.h>

class UNIMStripArray
{
public :
  UNIMStripArray(int);
  ~UNIMStripArray();
  
  void Init();
  void Clear();
  
  void SetEnergy(int numstrip, Short_t);
  void SetTime(int numstrip, Short_t);
  void SetEnergyCal(int numstrip, double);
  
  Short_t GetEnergy(int numstrip) const;
  Short_t GetTime(int numstrip) const;
  double GetEnergyCal(int numstrip) const;
  
private :
  int fNumStrips;
  Short_t * fEnergy;
  Short_t * fTime;
  double * fEnergyCal;
};

#endif
