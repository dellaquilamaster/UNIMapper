#include <UNIMMidasModule.h>

//________________________________________________
UNIMMidasModule::UNIMMidasModule(TTreeReader * NewReader) :
fTheReader(NewReader),
DAQ_fmulti (*fTheReader,"DAQ.fmulti"),
DAQ_fgid (*fTheReader,"DAQ.fgid"),
DAQ_fch  (*fTheReader,"DAQ.fch"),
DAQ_fampl  (*fTheReader,"DAQ.fampl")
{}

//________________________________________________
UNIMMidasModule::~UNIMMidasModule()
{
  printf("distruggo il midas module\n");
  printf("finito di distruggere il midas module\n");
}

//________________________________________________
Int_t UNIMMidasModule::GetMulti()
{
  return (*DAQ_fmulti);
}

//________________________________________________
Short_t UNIMMidasModule::GetGid(int Index)
{
  return DAQ_fgid[Index];
}

//________________________________________________
Short_t UNIMMidasModule::GetCh(int Index)
{
  return DAQ_fch[Index];
}

//________________________________________________
Short_t UNIMMidasModule::GetAmpl(int Index)
{
  return DAQ_fampl[Index];
}
