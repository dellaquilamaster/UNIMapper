#include <UNIMSiliconHodoscope.h>

//________________________________________________
UNIMSiliconHodoscope::UNIMSiliconHodoscope(const char * name, int num_det) : 
UNIMDetector(name, num_det),
fSiliconHodoscope(new UNIMSiliconSignal[num_det]),
fevt(new UNIMSiliconHodoscopeRootEvent(fNumDetectors)),
fEnergyID(std::hash<std::string>()("ENERGY")),
fTimeID(std::hash<std::string>()("TIME"))
{
  fType.assign("UNIMSiliconHodoscope");
}

//________________________________________________
UNIMSiliconHodoscope::~UNIMSiliconHodoscope()
{
  if(fevt) delete fevt;
  if(fSiliconHodoscope) delete [] fSiliconHodoscope;
}

//________________________________________________
void UNIMSiliconHodoscope::Clear()
{
  for(int det=0; det<fNumDetectors; det++) {
    fSiliconHodoscope[det].Clear();
  }
}

//________________________________________________
void UNIMSiliconHodoscope::InitTTreeBranch(TTree * theTree)
{
  theTree->Branch(Form("%s.",fName.c_str()),"UNIMSiliconHodoscopeData",&(fevt->fSiliconHodoscope),32768,1);
  return;
}

//________________________________________________
void UNIMSiliconHodoscope::SetQuantity(unsigned long quantity_code, int det_unit, Short_t value)
{
  if (quantity_code==fEnergyID) {
    fSiliconHodoscope[det_unit].SetEnergy(value);
  } else if (quantity_code==fTimeID) {
    fSiliconHodoscope[det_unit].SetTime(value);
  }
}

//________________________________________________
void UNIMSiliconHodoscope::BuildEvent()
{
  //Fill Root Event structure to be written on the tree
  FillMappedData();

  return;
}

//________________________________________________
void UNIMSiliconHodoscope::BuildEvent(UNIMCalibration* TheCalibrations)
{
  //Launch calibrations
  if(TheCalibrations->IsPresent()) BuildCalibratedQuantities(TheCalibrations);

  //Fill Root Event structure to be written on the tree
  FillMappedData();

  return;
}

//________________________________________________
void UNIMSiliconHodoscope::BuildCalibratedQuantities(UNIMCalibration* TheCalibrations)
{
  for(int det=0; det<fNumDetectors; det++) {
    if(fSiliconHodoscope[det].GetEnergy()>0)
    {      
      UNIMCalibrationElement * TheCalibration = TheCalibrations->GetCalibration(GetName(),fEnergyID, det);
      if(TheCalibration) fSiliconHodoscope[det].SetEnergyCal(TheCalibration->GetCalibrated(fSiliconHodoscope[det].GetEnergy()));
    }
  }
}

//________________________________________________
void UNIMSiliconHodoscope::FillMappedData()
{  
  //Retrieving information from UNIMSiliconSignal to fill UNIMSiliconHodoscopeData object
  //Fill data for all pads with energy above 0
  fevt->fSiliconHodoscope.fmulti=0;
  for(int det=0; det<fNumDetectors; det++) {
    if(fSiliconHodoscope[det].GetEnergy()>0)
    {
      fevt->fSiliconHodoscope.fnumpad[fevt->fSiliconHodoscope.fmulti]=det;
      fevt->fSiliconHodoscope.fEnergy[fevt->fSiliconHodoscope.fmulti]=fSiliconHodoscope[det].GetEnergy();
      fevt->fSiliconHodoscope.fEnergyCal[fevt->fSiliconHodoscope.fmulti]=fSiliconHodoscope[det].GetEnergyCal();
      fevt->fSiliconHodoscope.fTime[fevt->fSiliconHodoscope.fmulti]=fSiliconHodoscope[det].GetTime();
      fevt->fSiliconHodoscope.fmulti++;
    }
  }
  
  return;
}

