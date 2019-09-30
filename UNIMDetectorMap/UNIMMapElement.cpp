#include <UNIMMapElement.h>

//________________________________________________
UNIMMapElement::UNIMMapElement()
{}

//________________________________________________
UNIMMapElement::~UNIMMapElement()
{
  printf("distruggo la map element\n");
  printf("finito di distruggere la map element\n");
}

//________________________________________________
void UNIMMapElement::SetDetector(UNIMDetector * NewDetector)
{
  fTheDetector=NewDetector;
}

//________________________________________________
void UNIMMapElement::SetQuantity(const char * TheQuantity)
{
  fTheQuantity.assign(TheQuantity);
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
const char * UNIMMapElement::GetQuantity()
{
  return fTheQuantity.c_str();
}

//________________________________________________
int UNIMMapElement::GetUnit()
{
  return fTheUnit;
}
