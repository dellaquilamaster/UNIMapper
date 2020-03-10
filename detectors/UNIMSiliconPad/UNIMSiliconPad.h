#ifndef UNIMSILICONPAD_H
#define UNIMSILICONPAD_H

/* *******************************************************************************************************
 * UNIMSiliconPad Class
 * v1.0 10/03/2020
 * class to store Silicon Pad data
 * implemented by Daniele Dell'Aquila (daniele.dellaquila@irb.hr)
 * Simple version containing only the raw data of a Single Pad.
 * The class is composed by:
 *  1 UNIMSiliconSignal
 * 
 * UNIMSiliconSignal class contains the following quantities (as in the mapping file):
 *  - ENERGY
 *  - TIME
 *
 *  
 */

#include <TROOT.h>
#include <TTree.h>
#include <math.h>
#include <string>
#include <functional>
#include <UNIMSiliconPadRootEvent.h>
#include <UNIMSiliconSignal.h>
#include <UNIMDetector.h>
#include <UNIMCalibrationElement.h>

class UNIMSiliconPad : public UNIMDetector
{
public :
  UNIMSiliconPad(const char *);                              //!Constructor
  ~UNIMSiliconPad();                                         //!Destructor
                                                             
  void Clear() override;                                     //!Clear to -9999
  
  void SetQuantity(unsigned long, int, Short_t) override;    //!Set a quantity to the detector data structure

  void InitTTreeBranch(TTree *) override;                    //!Initialize TTree Branch containing detector ROOT type
  void BuildEvent() override;                                //!Organizes data into the ROOTEvent object
  void BuildEvent(UNIMCalibration*) override;                //!Organizes and calibrates data into the ROOTEvent object
  void FillMappedData() override;                            //!Stores mapped data in detector ROOT class to be written on the output tree
  
  void BuildCalibratedQuantities(UNIMCalibration*) override; //!Executes energy calibrations

private :
  UNIMSiliconSignal *fSiliconPad;                            //!UNIMSiliconSignal containing mapped event-by-event data
  UNIMSiliconPadRootEvent * fevt;                            //!RootEvent type of the detector
  
  const unsigned long fEnergyID;                             //!Identifier of the ENERGY quantity, used for a fast mapping
  const unsigned long fTimeID;                               //!Identifier of the TIME quantity, used for a fast mapping

};

#endif
