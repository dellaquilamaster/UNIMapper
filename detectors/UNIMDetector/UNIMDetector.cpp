#include <UNIMDetector.h>

//________________________________________________
UNIMDetector::UNIMDetector(const char * name, int num_detectors) :
fName(name),
fNumDetectors(num_detectors)
{}

//________________________________________________
UNIMDetector::~UNIMDetector()
{
  printf("distruggo il detector\n");
  printf("finito di distruggere il detector\n");
}

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
void UNIMDetector::SetQuantity(const char * quantity, int det_unit, Short_t value)
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
void UNIMDetector::FillMappedData()
{
  return;
}
