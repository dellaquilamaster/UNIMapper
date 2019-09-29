#ifndef UNIMMAPELEMENT_H
#define UNIMMAPELEMENT_H

#include <string>
#include <UNIMDetector.h>

class UNIMMapElement
{
public :
  void SetDetector(UNIMDetector *);
  void SetUnit(int);
  void SetQuantity(const char *);
  
  UNIMDetector * GetDetector();
  int GetUnit();
  const char * GetQuantity();
  
private :
  UNIMDetector * fTheDetector;
  int fTheUnit;
  std::string fTheQuantity;
};

#endif
