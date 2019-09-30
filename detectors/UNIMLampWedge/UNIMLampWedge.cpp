#include <UNIMLampWedge.h>

//________________________________________________
UNIMLampWedge::UNIMLampWedge(const char * name, int num_detectors) : 
UNIMDetector(name, num_detectors),
fLampWedge(new UNIMStripArray(fNumDetectors)),
fevt(new UNIMLampWedgeRootEvent(fNumDetectors))
{
  fType.assign("UNIMLampWedge");
}

//________________________________________________
UNIMLampWedge::~UNIMLampWedge()
{
  printf("distruggo il LampWedge\n");
  if(fLampWedge) delete fLampWedge;
  if(fevt) delete fevt;
  printf("finito di distruggere il LampWedge\n");
}

//________________________________________________
void UNIMLampWedge::Clear()
{
  fLampWedge->Clear();
}

//________________________________________________
void UNIMLampWedge::InitTTreeBranch(TTree * theTree)
{
  theTree->Branch(Form("%s.",fName.c_str()),"UNIMLampWedgeData",&(fevt->fLampWedge),32768,1);
  return;
}

//________________________________________________
void UNIMLampWedge::SetQuantity(const char * quantity, int det_unit, Short_t value)
{
  if(strcmp(quantity,"ENERGY")==0) {
    fLampWedge->SetEnergy(det_unit, value);
  } else if (strcmp(quantity,"TIME")==0) {
    fLampWedge->SetEnergy(det_unit, value);    
  }
}

//________________________________________________
void UNIMLampWedge::BuildEvent()
{
  //Launch calibrations
  //TO BE IMPLEMENTED  

  //Fill Root Event structure to be written on the tree
  FillMappedData();

  return;
}

//________________________________________________
void UNIMLampWedge::FillMappedData()
{  
  //Retrieving information from UNIMStripArray to fill UNIMLampWedgeData object
  //Fill strips
  fevt->fLampWedge.fmulti=0;
  for(int NumStrip=0; NumStrip<fNumDetectors; NumStrip++) {
    if(fLampWedge->GetEnergy(NumStrip)>0)
    {
      fevt->fLampWedge.fnumstrip[fevt->fLampWedge.fmulti]=NumStrip;
      fevt->fLampWedge.fEnergy[fevt->fLampWedge.fmulti]=fLampWedge->GetEnergy(NumStrip);
      fevt->fLampWedge.fEnergyCal[fevt->fLampWedge.fmulti]=fLampWedge->GetEnergyCal(NumStrip);
      fevt->fLampWedge.fTime[fevt->fLampWedge.fmulti]=fLampWedge->GetTime(NumStrip);
      fevt->fLampWedge.fmulti++;
    }
  }

  return;
}
