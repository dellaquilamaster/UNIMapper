#include <UNIMStripArray.h>

//________________________________________________
UNIMStripArray::UNIMStripArray(int numstrips) :
fNumStrips(numstrips),
fEnergy(new Short_t[fNumStrips]),
fTime(new Short_t[fNumStrips]),
fEnergyCal(new double[fNumStrips])
{}

//________________________________________________
UNIMStripArray::~UNIMStripArray()
{
  delete [] fEnergy;
  delete [] fTime;
  delete [] fEnergyCal;
}

//________________________________________________
void UNIMStripArray::Clear()
{
  for(int i=0; i<fNumStrips; i++) {
    fEnergy[i]=-9999;
    fTime[i]=-9999;
    fEnergyCal[i]=-9999;
  }
}

//________________________________________________
void UNIMStripArray::SetEnergy(int numstrip, Short_t value)
{
  fEnergy[numstrip]=value;
}

//________________________________________________
void UNIMStripArray::SetTime(int numstrip, Short_t value)
{
  fTime[numstrip]=value;
}

//________________________________________________
void UNIMStripArray::SetEnergyCal(int numstrip, double value)
{
  fEnergyCal[numstrip]=value;
}

//________________________________________________
Short_t UNIMStripArray::GetEnergy(int numstrip) const
{
  return fEnergy[numstrip];
}

//________________________________________________
Short_t UNIMStripArray::GetTime(int numstrip) const
{
  return fTime[numstrip];
}

//________________________________________________
double UNIMStripArray::GetEnergyCal(int numstrip) const
{
  return fEnergyCal[numstrip];
}
