#ifndef UNIMDSSSD_H
#define UNIMDSSSD_H

/* *******************************************************************************************************
 * UNIMDSSSD Class
 * v1.0 27/09/2019
 * class to store DSSSD data is derived
 * implemented by Daniele Dell'Aquila (daniele.dellaquila@irb.hr)
 * Simple version containing only the raw data of a DSSSD of arbitrary number of strips.
 * The class is composed by:
 * 1 UNIMStripArray
 *
 *
 * class UNIMStripArray : it is an organization of 
 * quantities -> value in memory
 * 
 * Quantities can be: 
 * ENERGYFRONT
 * ENERGYBACK
 * TIMEFRONT
 * TIMEBACK
 *  
 */

#include <TROOT.h>
#include <TTree.h>
#include <math.h>
#include <UNIMDSSSDRootEvent.h>
#include <UNIMStripArray.h>
#include <UNIMDetector.h>

class UNIMDSSSD : public UNIMDetector
{
public :
  UNIMDSSSD(const char *, int);                          //!Constructor
  ~UNIMDSSSD();                                          //!Destructor

  void Clear() override;                                 //!Clear to -9999
  
  void SetQuantity(const char *, int, Short_t) override; //!Set a quantity to the detector data structure

  void InitTTreeBranch(TTree *) override;                //!Initialize TTree Branch containing detector ROOT type
  void BuildEvent() override;                            //!Organizes and calibrates data into the ROOTEvent object
  void FillMappedData() override;                        //!Stores mapped data in detector ROOT class to be written on the output tree

private :
  UNIMStripArray *fDSSSD;                                //!UNIMStripArray containing mapped event-by-event data
  UNIMDSSSDRootEvent * fevt;                             //!RootEvent type of the detector

};

#endif
