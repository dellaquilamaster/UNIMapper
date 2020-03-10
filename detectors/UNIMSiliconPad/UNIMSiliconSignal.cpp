#include <UNIMSiliconSignal.h>

//________________________________________________
UNIMSiliconSignal::UNIMSiliconSignal() :
fEnergy(-9999),
fTime(-9999),
fEnergyCal(-9999)
{}

//________________________________________________
UNIMSiliconSignal::~UNIMSiliconSignal()
{}

//________________________________________________
void UNIMSiliconSignal::Clear()
{
  fEnergy=-9999;
  fTime=-9999;
  fEnergyCal=-9999;
}

//________________________________________________
void UNIMSiliconSignal::SetEnergy(Short_t value)
{
  fEnergy=value;
}

//________________________________________________
void UNIMSiliconSignal::SetTime(Short_t value)
{
  fTime=value;
}

//________________________________________________
void UNIMSiliconSignal::SetEnergyCal(double value)
{
  fEnergyCal=value;
}

//________________________________________________
Short_t UNIMSiliconSignal::GetEnergy() const
{
  return fEnergy;
}

//________________________________________________
Short_t UNIMSiliconSignal::GetTime() const
{
  return fTime;
}

//________________________________________________
double UNIMSiliconSignal::GetEnergyCal() const
{
  return fEnergyCal;
}
