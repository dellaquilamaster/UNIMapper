#ifndef UNIMCALIBRATION_H
#define UNIMCALIBRATION_H

/*
 * UNIMCalibration class
 * created by Daniele Dell'Aquila (daniele.dellaquila@irb.hr)
 * 
 * This class is used to manage energy calibrations for all detectors and quantities.
 * Quantities are defined by an index obtained by applying the atoi() function to 
 * the following strings:
 * ENERGYFRONT
 * ENERGYBACK
 * ENERGY
 * 
 * 
 */

#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <UNIMCalibrationElement.h>

class UNIMCalibration
{
public :
  UNIMCalibration();
  ~UNIMCalibration();
  
  int LoadCalibration(const char *);
  bool IsPresent() const;
  
  UNIMCalibrationElement * GetCalibration(const char * det, unsigned long quantity_id, int unit=0);
  
private :
  bool fIsLoaded;
  std::map<std::string, std::map<unsigned long, std::map<int, UNIMCalibrationElement *> *> *> fTheCalibrations;  //!A map containing all the calibrations indexed in the following way: det_name -> quantity_id ->  unit
};

#endif
