#include <UNIMLampWedge.h>

//________________________________________________
UNIMLampWedge::UNIMLampWedge(const char * name, int num_detectors) : 
UNIMDetector(name, num_detectors),
fLampWedge(new UNIMStripArray(fNumDetectors)),
fevt(new UNIMLampWedgeRootEvent(fNumDetectors)),
fEnergyID(atoi("ENERGY")),
fTimeID(atoi("TIME"))
{
  fType.assign("UNIMLampWedge");
}

//________________________________________________
UNIMLampWedge::~UNIMLampWedge()
{
  if(fLampWedge) delete fLampWedge;
  if(fevt) delete fevt;
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
void UNIMLampWedge::SetQuantity(unsigned long quantity_code, int det_unit, Short_t value)
{
  if (quantity_code==fEnergyID) {
    fLampWedge->SetEnergy(det_unit, value);
  } else if (quantity_code==fTimeID) {
    fLampWedge->SetTime(det_unit, value);
  }
}

//________________________________________________
void UNIMLampWedge::BuildEvent()
{
  //Fill Root Event structure to be written on the tree
  FillMappedData();

  return;
}

//________________________________________________
void UNIMLampWedge::BuildEvent(UNIMCalibration* TheCalibrations)
{
  //Launch calibrations
  if(TheCalibrations->IsPresent()) BuildCalibratedQuantities(TheCalibrations);

  //Fill Root Event structure to be written on the tree
  FillMappedData();

  return;
}

//________________________________________________
void UNIMLampWedge::BuildCalibratedQuantities(UNIMCalibration* TheCalibrations)
{
  //Loop on strips
  for(int NumStrip=0; NumStrip<fNumDetectors; NumStrip++) {
    if(fLampWedge->GetEnergy(NumStrip)>0)
    {
      UNIMCalibrationElement * TheCalibration = TheCalibrations->GetCalibration(GetName(),fEnergyID,NumStrip);
      if(TheCalibration) fLampWedge->SetEnergyCal(NumStrip, TheCalibration->GetCalibrated(fLampWedge->GetEnergy(NumStrip)));
    }
  }
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
