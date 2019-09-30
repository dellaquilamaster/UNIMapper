#include <UNIMDSSSDRootEvent.h>

//________________________________________________
UNIMDSSSDData::UNIMDSSSDData(int num_dets) :
fmultif(0),
fmultib(0)
{
  fnumstripf=new Int_t[num_dets];    
  fEnergyFront=new Short_t[num_dets];    
  fTimeFront=new Short_t[num_dets];      
  fEnergyFrontCal=new double[num_dets]; 
  fnumstripb=new Int_t[num_dets];    
  fEnergyBack=new Short_t[num_dets];    
  fTimeBack=new Short_t[num_dets];      
  fEnergyBackCal=new double[num_dets]; 
}

//________________________________________________
UNIMDSSSDData::~UNIMDSSSDData()
{
  printf("distruggo il root data\n");
  delete [] fnumstripf;
  delete [] fEnergyFront;
  delete [] fTimeFront;
  delete [] fEnergyFrontCal;
  delete [] fnumstripb;
  delete [] fEnergyBack;
  delete [] fTimeBack;
  delete [] fEnergyBackCal;
  printf("finito di distruggere il root data\n");
}

//________________________________________________
UNIMDSSSDRootEvent::UNIMDSSSDRootEvent(int num_dets) :
fNumDetectors(num_dets),
fDSSSD(fNumDetectors)
{}

//________________________________________________
UNIMDSSSDRootEvent::~UNIMDSSSDRootEvent()
{
  printf("distruggo il root evento\n");
  printf("finito di distruggere il root evento\n");
}
