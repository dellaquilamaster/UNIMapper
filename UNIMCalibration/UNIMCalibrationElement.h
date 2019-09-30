#ifndef UNIMCALIBRATIONELEMENT
#define UNIMCALIBRATIONELEMENT

#include <TF1.h>

class UNIMCalibrationElement
{
public :
  UNIMCalibrationElement();
  ~UNIMCalibrationElement();
  
  void SetNumParameters(int);
  void SetParameter(int, double);
  void InitCalibration(const char *);
  
  double GetCalibrated(double) const;
  
private :
  int fNumParameters;
  double * fTheParameters;
  TF1 * fTheFormula;
};

#endif
