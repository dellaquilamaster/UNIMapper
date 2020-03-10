#ifndef UNIMSPARECHANNEL_H
#define UNIMSPARECHANNEL_H

#include <string>
#include <TROOT.h>

class UNIMSpareChannel
{
public :
  UNIMSpareChannel(const char *);
  ~UNIMSpareChannel();
  
  void Clear();

  Short_t GetValue() const;
  const Short_t * GetValuePointer() const;
  const char * GetName() const;

  void SetValue(Short_t);

private :
  std::string fname;
  Short_t fvalue;
};

#endif
