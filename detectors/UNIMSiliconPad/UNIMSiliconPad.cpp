#include <UNIMSiliconPad.h>

//________________________________________________
UNIMSiliconPad::UNIMSiliconPad(const char * name) : 
UNIMDetector(name, 1),
fSiliconPad(new UNIMSiliconSignal()),
fevt(new UNIMSiliconPadRootEvent()),
fEnergyID(std::hash<std::string>()("ENERGY")),
fTimeID(std::hash<std::string>()("TIME"))
{
  fType.assign("UNIMSiliconPad");
}

//________________________________________________
UNIMSiliconPad::~UNIMSiliconPad()
{
  if(fevt) delete fevt;
}

//________________________________________________
void UNIMSiliconPad::Clear()
{
  fSiliconPad->Clear();
}

//________________________________________________
void UNIMSiliconPad::InitTTreeBranch(TTree * theTree)
{
  theTree->Branch(Form("%s.",fName.c_str()),"UNIMSiliconPadData",&(fevt->fSiliconPad),32768,1);
  return;
}

//________________________________________________
void UNIMSiliconPad::SetQuantity(unsigned long quantity_code, int det_unit, Short_t value)
{
  if (quantity_code==fEnergyID) {
    fSiliconPad->SetEnergy(value);
  } else if (quantity_code==fTimeID) {
    fSiliconPad->SetTime(value);
  }
}

//________________________________________________
void UNIMSiliconPad::BuildEvent()
{
  //Fill Root Event structure to be written on the tree
  FillMappedData();

  return;
}

//________________________________________________
void UNIMSiliconPad::BuildEvent(UNIMCalibration* TheCalibrations)
{
  //Launch calibrations
  if(TheCalibrations->IsPresent()) BuildCalibratedQuantities(TheCalibrations);

  //Fill Root Event structure to be written on the tree
  FillMappedData();

  return;
}

//________________________________________________
void UNIMSiliconPad::BuildCalibratedQuantities(UNIMCalibration* TheCalibrations)
{
  if(fSiliconPad->GetEnergy()>0)
  {      
    UNIMCalibrationElement * TheCalibration = TheCalibrations->GetCalibration(GetName(),fEnergyID);
    if(TheCalibration) fSiliconPad->SetEnergyCal(TheCalibration->GetCalibrated(fSiliconPad->GetEnergy()));
  }
}

//________________________________________________
void UNIMSiliconPad::FillMappedData()
{  
  //Retrieving information from UNIMSiliconSignal to fill UNIMSiliconPadData object
  //Fill data without specific conditions
  if(1)
  {
    fevt->fSiliconPad.fEnergy=fSiliconPad->GetEnergy();
    fevt->fSiliconPad.fEnergyCal=fSiliconPad->GetEnergyCal();
    fevt->fSiliconPad.fTime=fSiliconPad->GetTime();
  }

  return;
}
