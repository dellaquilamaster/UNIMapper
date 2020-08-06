#include <UNIMSiliconHodoscopeRootEvent.h>

//________________________________________________
UNIMSiliconHodoscopeData::UNIMSiliconHodoscopeData(int num_dets) :
fmulti(0)
{
  fnumpad=new Int_t[num_dets];    
  fEnergy=new Short_t[num_dets];    
  fTime=new Short_t[num_dets];      
  fEnergyCal=new double[num_dets]; 
}

//________________________________________________
UNIMSiliconHodoscopeData::UNIMSiliconHodoscopeData() :
fmulti(0)
{
  fnumpad=new Int_t[16];    
  fEnergy=new Short_t[16];    
  fTime=new Short_t[16];      
  fEnergyCal=new double[16]; 
}

//________________________________________________
UNIMSiliconHodoscopeData::~UNIMSiliconHodoscopeData()
{
  delete [] fnumpad;
  delete [] fEnergy;
  delete [] fTime;
  delete [] fEnergyCal;
}

//________________________________________________
UNIMSiliconHodoscopeRootEvent::UNIMSiliconHodoscopeRootEvent(int num_dets) :
fNumDetectors(num_dets),
fSiliconHodoscope(fNumDetectors)
{}

//________________________________________________
UNIMSiliconHodoscopeRootEvent::~UNIMSiliconHodoscopeRootEvent()
{}
