#include <UNIMDetector.h>

//________________________________________________
UNIMDetector::UNIMDetector(const char * name, int num_detectors) :
fName(name),
fNumDetectors(num_detectors)
{}

//________________________________________________
UNIMDetector::~UNIMDetector()
{}

//________________________________________________
void UNIMDetector::Clear()
{
  return;
}

//________________________________________________
const char * UNIMDetector::GetName() const
{
  return fName.c_str();
}

//________________________________________________
const char * UNIMDetector::GetType() const
{
  return fType.c_str();
}

//________________________________________________
int UNIMDetector::GetNumDetectors() const
{
  return fNumDetectors;
}

//________________________________________________
void UNIMDetector::SetQuantity(unsigned long quantity_id, int det_unit, Short_t value)
{
  return;
}

//________________________________________________
void UNIMDetector::InitTTreeBranch(TTree * theTree)
{
  return;
}

//________________________________________________
void UNIMDetector::BuildEvent()
{
  return;
}

//________________________________________________
void UNIMDetector::BuildEvent(UNIMCalibration*)
{
  return;
}

//________________________________________________
void UNIMDetector::FillMappedData()
{
  return;
}

//________________________________________________
void UNIMDetector::BuildCalibratedQuantities(UNIMCalibration * TheCalibrations)
{
  return;
}
