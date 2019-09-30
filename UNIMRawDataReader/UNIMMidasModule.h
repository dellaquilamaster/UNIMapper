#ifndef UNIMMIDASMODULE_H
#define UNIMMIDASMODULE_H

#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <M2RMidasRootEvent.h>

class UNIMMidasModule
{
public :
  UNIMMidasModule (TTreeReader *);
  ~UNIMMidasModule ();
  
  Int_t GetMulti();
  Short_t GetGid(int);
  Short_t GetCh(int);
  Short_t GetAmpl(int);

private :
  TTreeReader * fTheReader;
  TTreeReaderValue<M2RMidasRootEvent> DAQ;
};

#endif
