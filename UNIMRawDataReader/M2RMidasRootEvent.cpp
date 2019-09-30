#include <M2RMidasRootEvent.h>

//____________________________________________________
M2RMidasRootEvent::M2RMidasRootEvent() :
fmulti(0),
fgid(new Short_t[MAX_MULT_M2RMIDASROOTEVENT]),
fch(new Short_t[MAX_MULT_M2RMIDASROOTEVENT]),
fampl(new Short_t[MAX_MULT_M2RMIDASROOTEVENT])
{}

//____________________________________________________
M2RMidasRootEvent::~M2RMidasRootEvent()
{
  delete [] fgid;
  delete [] fch;
  delete [] fampl;
}
