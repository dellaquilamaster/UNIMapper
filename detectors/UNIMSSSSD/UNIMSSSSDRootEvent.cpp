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
UNIMSSSSDData::~UNIMSSSSDData()
{
  printf("distruggo il root data\n");
  delete [] fnumstrip;
  delete [] fEnergy;
  delete [] fTime;
  delete [] fEnergyCal;
  printf("finito di distruggere il root data\n");
}

//________________________________________________
UNIMSSSSDRootEvent::UNIMSSSSDRootEvent(int num_dets) :
fNumDetectors(num_dets),
fSSSSD(fNumDetectors)
{}

//________________________________________________
UNIMSSSSDRootEvent::~UNIMSSSSDRootEvent()
{
  printf("distruggo il root evento\n");
  printf("finito di distruggere il root evento\n");
}
