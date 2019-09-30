#ifndef UNIMMAPELEMENT_H
#define UNIMMAPELEMENT_H

/*
 * class UNIMMapElement
 * created by Daniele Dell'Aquila (daniele.dellaquila@irb.hr)
 * 
 * This is a mapping element i.e. an identifier of the following quantities: Detector, quantity, unit
 * The detector is stored as the pointer of the corresponding UNIMDetector object
 * The quantity (e.g. ENERGY, TIME, ENERGYFRONT, ...) is stored as a unique integer obtained as atoi(quantity)
 * The unit is an integer and correspond to the individual detection unit in the detector 
 * 
 */

#include <string>
#include <UNIMDetector.h>

class UNIMMapElement
{
public :
  UNIMMapElement();
  ~UNIMMapElement();
  
  void SetDetector(UNIMDetector *);
  void SetUnit(int);
  void SetQuantity(const char *);
  
  UNIMDetector * GetDetector();
  int GetUnit();
  int GetQuantity();
  
private :
  UNIMDetector * fTheDetector;
  int fTheUnit;
  int fTheQuantity;
};

#endif
