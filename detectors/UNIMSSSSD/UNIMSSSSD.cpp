#include <UNIMSSSSD.h>

//________________________________________________
UNIMSSSSD::UNIMSSSSD(const char * name, int num_detectors) : 
UNIMDetector(name, num_detectors),
fSSSSD(new UNIMStripArray(fNumDetectors)),
fevt(new UNIMSSSSDRootEvent(fNumDetectors)),
fEnergyID(std::hash<std::string>()("ENERGY")),
fTimeID(std::hash<std::string>()("TIME"))
{
  fType.assign("UNIMSSSSD");
}

//________________________________________________
UNIMSSSSD::~UNIMSSSSD()
{
  if(fSSSSD) delete fSSSSD;
  if(fevt) delete fevt;
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
void UNIMSSSSD::SetQuantity(unsigned long quantity_code, int det_unit, Short_t value)
{
  if (quantity_code==fEnergyID) {
    fSSSSD->SetEnergy(det_unit, value);
  } else if (quantity_code==fTimeID) {
    fSSSSD->SetTime(det_unit, value);
  }
}

//________________________________________________
void UNIMSSSSD::BuildEvent()
{
  //Fill Root Event structure to be written on the tree
  FillMappedData();

  return;
}

//________________________________________________
void UNIMSSSSD::BuildEvent(UNIMCalibration* TheCalibrations)
{
  //Launch calibrations
  if(TheCalibrations->IsPresent()) BuildCalibratedQuantities(TheCalibrations);

  //Fill Root Event structure to be written on the tree
  FillMappedData();

  return;
}

//________________________________________________
void UNIMSSSSD::BuildCalibratedQuantities(UNIMCalibration* TheCalibrations)
{
  //Loop on strips
  for(int NumStrip=0; NumStrip<fNumDetectors; NumStrip++) {
    if(fSSSSD->GetEnergy(NumStrip)>0)
    {      
      UNIMCalibrationElement * TheCalibration = TheCalibrations->GetCalibration(GetName(),fEnergyID,NumStrip);
      if(TheCalibration) fSSSSD->SetEnergyCal(NumStrip, TheCalibration->GetCalibrated(fSSSSD->GetEnergy(NumStrip)));
    }
  }
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
