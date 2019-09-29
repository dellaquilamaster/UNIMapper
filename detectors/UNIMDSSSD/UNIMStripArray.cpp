#include <UNIMStripArray.h>

//________________________________________________
UNIMStripArray::UNIMStripArray(int numstrips) :
fNumStrips(numstrips),
fQuantities(new std::map<std::string, Short_t>[fNumStrips])
{}

//________________________________________________
UNIMStripArray::~UNIMStripArray()
{
  delete [] fQuantities;
}

//________________________________________________
void UNIMStripArray::Init()
{
  for(int i=0; i<fNumStrips; i++) {
    (fQuantities[i])[std::string("ENERGYFRONT")]=-9999;
    (fQuantities[i])[std::string("ENERGYBACK")]=-9999;
    (fQuantities[i])[std::string("TIMEFRONT")]=-9999;
    (fQuantities[i])[std::string("TIMEBACK")]=-9999;
    (fQuantitiesCal[i])[std::string("ENERGYFRONTCAL")]=-9999;
    (fQuantitiesCal[i])[std::string("ENERGYBACKCAL")]=-9999;
  }
}

//________________________________________________
void UNIMStripArray::Clear()
{
  for(int i=0; i<fNumStrips; i++) {
    for(std::map<std::string, Short_t>::iterator it; it!=fQuantities[i].end(); it++) {
      it->second=-9999;
    }
    for(std::map<std::string, double>::iterator it; it!=fQuantitiesCal[i].end(); it++) {
      it->second=-9999;
    }
  }
}

//________________________________________________
void UNIMStripArray::SetQuantity(const char * quantity, int numstrip, Short_t value)
{
  (fQuantities[numstrip])[quantity]=value;
}

//________________________________________________
void UNIMStripArray::SetEnergyFrontCal(int numstrip, double value)
{
  (fQuantitiesCal[numstrip])[std::string("ENERGYFRONTCAL")]=value;
}

//________________________________________________
void UNIMStripArray::SetEnergyBackCal(int numstrip, double value)
{
  (fQuantitiesCal[numstrip])[std::string("ENERGYBACKCAL")]=value;
}

//________________________________________________
Short_t UNIMStripArray::GetQuantity(const char * quantity, int numstrip) const
{
  return (fQuantities[numstrip])[quantity];
}

//________________________________________________
Short_t UNIMStripArray::GetEnergyFront(int numstrip) const
{
  return (fQuantities[numstrip])["ENERGYFRONT"];
}

//________________________________________________
Short_t UNIMStripArray::GetEnergyBack(int numstrip) const
{
  return (fQuantities[numstrip])["ENERGYBACK"];
}

//________________________________________________
double UNIMStripArray::GetEnergyFrontCal(int numstrip) const
{
  return (fQuantitiesCal[numstrip])["ENERGYFRONTCAL"];
}

//________________________________________________
double UNIMStripArray::GetEnergyBackCal(int numstrip) const
{
  return (fQuantitiesCal[numstrip])["ENERGYBACKCAL"];
}

//________________________________________________
Short_t UNIMStripArray::GetTimeFront(int numstrip) const
{
  return (fQuantities[numstrip])["TIMEFRONT"];
}

//________________________________________________
Short_t UNIMStripArray::GetTimeBack(int numstrip) const
{
  return (fQuantities[numstrip])["TIMEBACK"];
}

