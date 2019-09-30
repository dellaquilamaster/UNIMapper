#include <UNIMMapElement.h>

//________________________________________________
UNIMMapElement::UNIMMapElement()
{}

//________________________________________________
UNIMMapElement::~UNIMMapElement()
{}

//________________________________________________
void UNIMMapElement::SetDetector(UNIMDetector * NewDetector)
{
  fTheDetector=NewDetector;
}

//________________________________________________
void UNIMMapElement::SetQuantity(const char * TheQuantity)
{
  fTheQuantity=(atoi(TheQuantity));
}

//________________________________________________
void UNIMMapElement::SetUnit(int new_unit)
{
  fTheUnit=new_unit;
}

//________________________________________________
UNIMDetector * UNIMMapElement::GetDetector()
{
  return fTheDetector;
}

//________________________________________________
int UNIMMapElement::GetQuantity()
{
  return fTheQuantity;
}

//________________________________________________
int UNIMMapElement::GetUnit()
{
  return fTheUnit;
}
