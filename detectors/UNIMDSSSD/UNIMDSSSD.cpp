#include <UNIMDSSSD.h>

//________________________________________________
UNIMDSSSD::UNIMDSSSD(const char * name, int num_detectors) : 
UNIMDetector(name, num_detectors),
fDSSSD(new UNIMStripArray(fNumDetectors)),
fevt(new UNIMDSSSDRootEvent(fNumDetectors))
{
  fType.assign("UNIMDSSSD");
}

//________________________________________________
UNIMDSSSD::~UNIMDSSSD()
{
  if(fDSSSD) delete fDSSSD;
  if(fevt) delete fevt;
}

//________________________________________________
void UNIMDSSSD::Clear()
{
  fDSSSD->Clear();
}

//________________________________________________
void UNIMDSSSD::InitTTreeBranch(TTree * theTree)
{
  theTree->Branch(Form("%s.",fName.c_str()),"UNIMDSSSDData",&(fevt->fDSSSD),32768,1);
  return;
}

//________________________________________________
void UNIMDSSSD::SetQuantity(const char * quantity, int det_unit, Short_t value)
{
  fDSSSD->SetQuantity(quantity, det_unit, value);
}

//________________________________________________
void UNIMDSSSD::BuildEvent()
{
  //Launch calibrations
  //TO BE IMPLEMENTED  

  //Fill Root Event structure to be written on the tree
  FillMappedData();

  return;
}

//________________________________________________
void UNIMDSSSD::FillMappedData()
{  
  //Retrieving information from UNIMStripArray to fill UNIMDSSSDData object
  //Fill front strips
  fevt->fDSSSD.fmultif=0;
  for(int NumStrip=0; NumStrip<fNumDetectors; NumStrip++) {
    if(fDSSSD->GetEnergyFront(NumStrip)>0)
    {
      fevt->fDSSSD.fnumstripf[fevt->fDSSSD.fmultif]=NumStrip;
      fevt->fDSSSD.fEnergyFront[fevt->fDSSSD.fmultif]=fDSSSD->GetEnergyFront(NumStrip);
      fevt->fDSSSD.fEnergyFrontCal[fevt->fDSSSD.fmultif]=fDSSSD->GetEnergyFrontCal(NumStrip);
      fevt->fDSSSD.fTimeFront[fevt->fDSSSD.fmultif]=fDSSSD->GetTimeFront(NumStrip);
      fevt->fDSSSD.fmultif++;
    }
  }
  //Fill back strips
  fevt->fDSSSD.fmultib=0;
  for(int NumStrip=0; NumStrip<fNumDetectors; NumStrip++) {
    if(fDSSSD->GetEnergyBack(NumStrip)>0)
    {
      fevt->fDSSSD.fnumstripf[fevt->fDSSSD.fmultib]=NumStrip;
      fevt->fDSSSD.fEnergyBack[fevt->fDSSSD.fmultib]=fDSSSD->GetEnergyBack(NumStrip);
      fevt->fDSSSD.fEnergyBackCal[fevt->fDSSSD.fmultib]=fDSSSD->GetEnergyBackCal(NumStrip);
      fevt->fDSSSD.fTimeBack[fevt->fDSSSD.fmultib]=fDSSSD->GetTimeBack(NumStrip);
      fevt->fDSSSD.fmultib++;
    }
  }

  return;
}
