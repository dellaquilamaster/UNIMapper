#include <UNIMSSSSD.h>

//________________________________________________
UNIMSSSSD::UNIMSSSSD(const char * name, int num_detectors) : 
UNIMDetector(name, num_detectors),
fSSSSD(new UNIMStripArray(fNumDetectors)),
fevt(new UNIMSSSSDRootEvent(fNumDetectors))
{
  fType.assign("UNIMSSSSD");
}

//________________________________________________
UNIMSSSSD::~UNIMSSSSD()
{
  printf("distruggo il SSSSD\n");
  if(fSSSSD) delete fSSSSD;
  if(fevt) delete fevt;
  printf("finito di distruggere il SSSSD\n");
}

//________________________________________________
void UNIMSSSSD::Clear()
{
  fSSSSD->Clear();
}

//________________________________________________
void UNIMSSSSD::InitTTreeBranch(TTree * theTree)
{
  theTree->Branch(Form("%s.",fName.c_str()),"UNIMSSSSDData",&(fevt->fSSSSD),32768,1);
  return;
}

//________________________________________________
void UNIMSSSSD::SetQuantity(const char * quantity, int det_unit, Short_t value)
{
  if(strcmp(quantity,"ENERGY")==0) {
    fSSSSD->SetEnergy(det_unit, value);
  } else if (strcmp(quantity,"TIME")==0) {
    fSSSSD->SetEnergy(det_unit, value);    
  }
}

//________________________________________________
void UNIMSSSSD::BuildEvent()
{
  //Launch calibrations
  //TO BE IMPLEMENTED  

  //Fill Root Event structure to be written on the tree
  FillMappedData();

  return;
}

//________________________________________________
void UNIMSSSSD::FillMappedData()
{  
  //Retrieving information from UNIMStripArray to fill UNIMSSSSDData object
  //Fill strips
  fevt->fSSSSD.fmulti=0;
  for(int NumStrip=0; NumStrip<fNumDetectors; NumStrip++) {
    if(fSSSSD->GetEnergy(NumStrip)>0)
    {
      fevt->fSSSSD.fnumstrip[fevt->fSSSSD.fmulti]=NumStrip;
      fevt->fSSSSD.fEnergy[fevt->fSSSSD.fmulti]=fSSSSD->GetEnergy(NumStrip);
      fevt->fSSSSD.fEnergyCal[fevt->fSSSSD.fmulti]=fSSSSD->GetEnergyCal(NumStrip);
      fevt->fSSSSD.fTime[fevt->fSSSSD.fmulti]=fSSSSD->GetTime(NumStrip);
      fevt->fSSSSD.fmulti++;
    }
  }

  return;
}
