#include <UNIMSpareChannel.h>

//________________________________________________
UNIMSpareChannel::UNIMSpareChannel(const char * name) :
fname(name),
fvalue(-9999)
{}

//________________________________________________
UNIMSpareChannel::~UNIMSpareChannel()
{}

//________________________________________________
void UNIMSpareChannel::Clear()
{
  fvalue=-9999;
}

//________________________________________________
Short_t UNIMSpareChannel::GetValue() const
{
  return fvalue;
}

//________________________________________________
const Short_t * UNIMSpareChannel::GetValuePointer() const
{
  return &fvalue;
}

//________________________________________________
const char * UNIMSpareChannel::GetName() const
{
  return fname.c_str();
}

//________________________________________________
void UNIMSpareChannel::SetValue(Short_t new_value)
{
  fvalue=new_value;
}
