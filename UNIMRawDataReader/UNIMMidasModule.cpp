#include <UNIMMidasModule.h>

//________________________________________________
UNIMMidasModule::UNIMMidasModule(TTreeReader * NewReader) :
fTheReader(NewReader),
DAQ (*fTheReader,"DAQ.")
{}

//________________________________________________
UNIMMidasModule::~UNIMMidasModule()
{}

//________________________________________________
Int_t UNIMMidasModule::GetMulti()
{
  return (*DAQ).fmulti;
}

//________________________________________________
Short_t UNIMMidasModule::GetGid(int Index)
{
  return (*DAQ).fgid[Index];
}

//________________________________________________
Short_t UNIMMidasModule::GetCh(int Index)
{
  return (*DAQ).fch[Index];
}

//________________________________________________
Short_t UNIMMidasModule::GetAmpl(int Index)
{
  return (*DAQ).fampl[Index];
}
