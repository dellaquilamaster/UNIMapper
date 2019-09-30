#include <UNIMCalibrationElement.h>

//________________________________________________
UNIMCalibrationElement::UNIMCalibrationElement() :
fNumParameters(0),
fTheParameters(0),
fTheFormula(0)
{}

//________________________________________________
UNIMCalibrationElement::~UNIMCalibrationElement()
{
  if(fTheParameters) delete [] fTheParameters;
}

//________________________________________________
void UNIMCalibrationElement::SetNumParameters(int num_parameters)
{
  fNumParameters=num_parameters;
  fTheParameters=new double[fNumParameters];
}

//________________________________________________
void UNIMCalibrationElement::SetParameter(int par, double value)
{
  fTheParameters[par]=value;
}

//________________________________________________
void UNIMCalibrationElement::InitCalibration(const char * formula)
{
  fTheFormula = new TF1 ("TheCalibration", formula, 0, 10000);
  fTheFormula->SetParameters(fTheParameters);
}

//________________________________________________
double UNIMCalibrationElement::GetCalibrated(double val) const
{
  return fTheFormula->Eval(val); 
}
