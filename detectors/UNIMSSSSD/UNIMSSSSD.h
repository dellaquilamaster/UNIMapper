#ifndef UNIMSSSSD_H
#define UNIMSSSSD_H

/* *******************************************************************************************************
 * UNIMSSSSD Class
 * v1.0 30/09/2019
 * class to store Single-Sided Silicon Strip Detector (SSSSD) data
 * implemented by Daniele Dell'Aquila (daniele.dellaquila@irb.hr)
 * Simple version containing only the raw data of a SSSSD of arbitrary number of strips.
 * The class is composed by:
 * 1 UNIMStripArray
 *
 *
 * class UNIMStripArray : it is an organization of data.
 * This data is associated by the UNIMSSSSD class to certain quantitites that can be:
 * ENERGY
 * TIME
 *  
 */

#include <TROOT.h>
#include <TTree.h>
#include <math.h>
#include <UNIMSSSSDRootEvent.h>
#include <UNIMStripArray.h>
#include <UNIMDetector.h>

class UNIMSSSSD : public UNIMDetector
{
public :
  UNIMSSSSD(const char *, int);                          //!Constructor
  ~UNIMSSSSD();                                          //!Destructor

  void Clear() override;                                 //!Clear to -9999
  
  void SetQuantity(int, int, Short_t) override;          //!Set a quantity to the detector data structure

  void InitTTreeBranch(TTree *) override;                //!Initialize TTree Branch containing detector ROOT type
  void BuildEvent() override;                            //!Organizes and calibrates data into the ROOTEvent object
  void FillMappedData() override;                        //!Stores mapped data in detector ROOT class to be written on the output tree

private :
  UNIMStripArray *fSSSSD;                                //!UNIMStripArray containing mapped event-by-event data
  UNIMSSSSDRootEvent * fevt;                             //!RootEvent type of the detector
  
  const int fEnergyID;                                   //!Identifier of the ENERGY quantity, used for a fast mapping
  const int fTimeID;                                     //!Identifier of the TIME quantity, used for a fast mapping

};

#endif
