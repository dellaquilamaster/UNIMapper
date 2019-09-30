#include <UNIMLampWedgeRootEvent.h>

//________________________________________________
UNIMLampWedgeData::UNIMLampWedgeData(int num_dets) :
fmulti(0)
{
  fnumstrip=new Int_t[num_dets];    
  fEnergy=new Short_t[num_dets];    
  fTime=new Short_t[num_dets];      
  fEnergyCal=new double[num_dets]; 
}

//________________________________________________
UNIMLampWedgeData::~UNIMLampWedgeData()
{
  printf("distruggo il root data\n");
  delete [] fnumstrip;
  delete [] fEnergy;
  delete [] fTime;
  delete [] fEnergyCal;
  printf("finito di distruggere il root data\n");
}

//________________________________________________
UNIMLampWedgeRootEvent::UNIMLampWedgeRootEvent(int num_dets) :
fNumDetectors(num_dets),
fLampWedge(fNumDetectors)
{}

//________________________________________________
UNIMLampWedgeRootEvent::~UNIMLampWedgeRootEvent()
{
  printf("distruggo il root evento\n");
  printf("finito di distruggere il root evento\n");
}
