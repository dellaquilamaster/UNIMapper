#ifndef UNIMMIDASMODULE_H
#define UNIMMIDASMODULE_H

#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>

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
  TTreeReaderValue<Int_t> DAQ_fmulti; 
  TTreeReaderArray<Short_t> DAQ_fgid; 
  TTreeReaderArray<Short_t> DAQ_fch;  
  TTreeReaderArray<Short_t> DAQ_fampl;
};

#endif
