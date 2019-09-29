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
  
  void SetQuantity(const char *, int numstrip, Short_t value);
  void SetEnergyFrontCal(int numstrip, double value);
  void SetEnergyBackCal(int numstrip, double value);
  
  Short_t GetQuantity(const char *, int numstrip) const;

  Short_t GetEnergyFront(int numstrip) const;
  Short_t GetEnergyBack(int numstrip) const;
  double GetEnergyFrontCal(int numstrip) const;
  double GetEnergyBackCal(int numstrip) const;
  Short_t GetTimeFront(int numstrip) const;
  Short_t GetTimeBack(int numstrip) const;
  
private :
  int fNumStrips;
  std::map<std::string, Short_t> * fQuantities;
  std::map<std::string, double> * fQuantitiesCal;
};

#endif
