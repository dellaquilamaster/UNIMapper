#include <UNIMSSSSDRootEvent.h>

//________________________________________________
UNIMSSSSDData::UNIMSSSSDData(int num_dets) :
fmulti(0)
{
  fnumstrip=new Int_t[num_dets];    
  fEnergy=new Short_t[num_dets];    
  fTime=new Short_t[num_dets];      
  fEnergyCal=new double[num_dets]; 
}

//________________________________________________
UNIMSSSSDData::UNIMSSSSDData() :
fmulti(0)
{
  fnumstrip=new Int_t[16];    
  fEnergy=new Short_t[16];    
  fTime=new Short_t[16];      
  fEnergyCal=new double[16]; 
}

//________________________________________________
UNIMSSSSDData::~UNIMSSSSDData()
{
  delete [] fnumstrip;
  delete [] fEnergy;
  delete [] fTime;
  delete [] fEnergyCal;
}

//________________________________________________
UNIMSSSSDRootEvent::UNIMSSSSDRootEvent(int num_dets) :
fNumDetectors(num_dets),
fSSSSD(fNumDetectors)
{}

//________________________________________________
UNIMSSSSDRootEvent::~UNIMSSSSDRootEvent()
{}
