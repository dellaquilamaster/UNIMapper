#include <UNIMDSSSD.h>

//________________________________________________
UNIMDSSSD::UNIMDSSSD(const char * name, int num_detectors) : 
UNIMDetector(name, num_detectors),
fDSSSDFront(new UNIMStripArray(fNumDetectors)),
fDSSSDBack(new UNIMStripArray(fNumDetectors)),
fevt(new UNIMDSSSDRootEvent(fNumDetectors))
{
  fType.assign("UNIMDSSSD");
}

//________________________________________________
UNIMDSSSD::~UNIMDSSSD()
{
  printf("distruggo il DSSSD\n");
  if(fDSSSDFront) delete fDSSSDFront;
  if(fDSSSDBack) delete fDSSSDBack;
  if(fevt) delete fevt;
  printf("finito di distruggere il DSSSD\n");
}

//________________________________________________
void UNIMDSSSD::Clear()
{
  fDSSSDFront->Clear();
  fDSSSDBack->Clear();
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
  if(strcmp(quantity,"ENERGYFRONT")==0) {
    fDSSSDFront->SetEnergy(det_unit, value);
  } else if (strcmp(quantity,"ENERGYBACK")==0) {
    fDSSSDBack->SetEnergy(det_unit, value);    
  } else if (strcmp(quantity,"TIMEFRONT")==0) {
    fDSSSDFront->SetTime(det_unit, value);    
  } else if (strcmp(quantity,"TIMEBACK")==0) {
    fDSSSDBack->SetTime(det_unit, value);    
  }
  
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
    if(fDSSSDFront->GetEnergy(NumStrip)>0)
    {
      fevt->fDSSSD.fnumstripf[fevt->fDSSSD.fmultif]=NumStrip;
      fevt->fDSSSD.fEnergyFront[fevt->fDSSSD.fmultif]=fDSSSDFront->GetEnergy(NumStrip);
      fevt->fDSSSD.fEnergyFrontCal[fevt->fDSSSD.fmultif]=fDSSSDFront->GetEnergyCal(NumStrip);
      fevt->fDSSSD.fTimeFront[fevt->fDSSSD.fmultif]=fDSSSDFront->GetTime(NumStrip);
      fevt->fDSSSD.fmultif++;
    }
  }
  //Fill back strips
  fevt->fDSSSD.fmultib=0;
  for(int NumStrip=0; NumStrip<fNumDetectors; NumStrip++) {
    if(fDSSSDBack->GetEnergy(NumStrip)>0)
    {
      fevt->fDSSSD.fnumstripf[fevt->fDSSSD.fmultib]=NumStrip;
      fevt->fDSSSD.fEnergyBack[fevt->fDSSSD.fmultib]=fDSSSDBack->GetEnergy(NumStrip);
      fevt->fDSSSD.fEnergyBackCal[fevt->fDSSSD.fmultib]=fDSSSDBack->GetEnergyCal(NumStrip);
      fevt->fDSSSD.fTimeBack[fevt->fDSSSD.fmultib]=fDSSSDBack->GetTime(NumStrip);
      fevt->fDSSSD.fmultib++;
    }
  }

  return;
}
