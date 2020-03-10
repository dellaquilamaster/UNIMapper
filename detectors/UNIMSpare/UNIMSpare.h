#ifndef UNIMSPARE_H
#define UNIMSPARE_H

/* *******************************************************************************************************
 * UNIMSpare Class
 * v1.0 10/03/2020
 * class to store Spare channels usually containing triggers
 * or other useful parameters
 *
 * The class contains a vector of UNIMSpareChannel objects:
 * - UNIMSpareChannel
 * |- Double_t fvalue;
 * |- const char * fname;
 */

#include <TROOT.h>
#include <TTree.h>
#include <functional>
#include <UNIMDetector.h>

#include <UNIMSpareChannel.h>

class UNIMSpare : public UNIMDetector
{
public :
  UNIMSpare(const char *);                                    //!Constructor
  ~UNIMSpare();                                               //!Destructor
  
  void Clear() override;                                      //!Clear to -9999

  void SetQuantity(unsigned long, int, Short_t) override;     //!Set a quantity to the detector data structure
                                                              
  void InitTTreeBranch(TTree *) override;                     //!Initialize TTree Branch containing detector ROOT type
  void BuildEvent() override;                                 //!Organizes data into internal data structures
  void FillMappedData() override;                             //!Nothing to be done in this implementation
  
  void DefineQuantity(const char *);                          //!Define a new quantity in the inner data structure

private :
  std::map<unsigned long, UNIMSpareChannel *> fSpareChannels; //!UNIMSpareChannel array containing event-by-event mapped data for each individual quantity
};

#endif
