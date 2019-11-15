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
UNIMDSSSDData::UNIMDSSSDData() :
fmultif(0),
fmultib(0)
{
  fnumstripf=new Int_t[16];    
  fEnergyFront=new Short_t[16];    
  fTimeFront=new Short_t[16];      
  fEnergyFrontCal=new double[16]; 
  fnumstripb=new Int_t[16];    
  fEnergyBack=new Short_t[16];    
  fTimeBack=new Short_t[16];      
  fEnergyBackCal=new double[16]; 
}

//________________________________________________
UNIMDSSSDData::~UNIMDSSSDData()
{
  delete [] fnumstripf;
  delete [] fEnergyFront;
  delete [] fTimeFront;
  delete [] fEnergyFrontCal;
  delete [] fnumstripb;
  delete [] fEnergyBack;
  delete [] fTimeBack;
  delete [] fEnergyBackCal;
}

//________________________________________________
UNIMDSSSDRootEvent::UNIMDSSSDRootEvent(int num_dets) :
fNumDetectors(num_dets),
fDSSSD(fNumDetectors)
{}

//________________________________________________
UNIMDSSSDRootEvent::~UNIMDSSSDRootEvent()
{}
