#ifndef UNIMDSSSD_H
#define UNIMDSSSD_H

/* *******************************************************************************************************
 * UNIMDSSSD Class
 * v1.0 27/09/2019
 * class to store Double-Sided Silicon Strip Detector (DSSSD) data
 * implemented by Daniele Dell'Aquila (daniele.dellaquila@irb.hr)
 * Simple version containing only the raw data of a DSSSD of arbitrary number of strips.
 * The class is composed by:
 * 1 UNIMStripArray for strip front
 * 1 UNIMStripArray for strip back
 *
 *
 * class UNIMStripArray : it is an organization of data.
 * This data is associated by the UNIMDSSSD class to certain quantitites that can be:
 * ENERGYFRONT
 * ENERGYBACK
 * TIMEFRONT
 * TIMEBACK
 *  
 */

#include <TROOT.h>
#include <TTree.h>
#include <math.h>
#include <string>
#include <functional>
#include <UNIMDSSSDRootEvent.h>
#include <UNIMStripArray.h>
#include <UNIMDetector.h>
#include <UNIMCalibrationElement.h>

class UNIMDSSSD : public UNIMDetector
{
public :
  UNIMDSSSD(const char *, int);                              //!Constructor
  ~UNIMDSSSD();                                              //!Destructor
                                                             
  void Clear() override;                                     //!Clear to -9999
                                                             
  void SetQuantity(unsigned long, int, Short_t) override;    //!Set a quantity to the detector data structure
                                                             
  void InitTTreeBranch(TTree *) override;                    //!Initialize TTree Branch containing detector ROOT type
  void BuildEvent() override;                                //!Organizes data into the ROOTEvent object
  void BuildEvent(UNIMCalibration*) override;                //!Organizes and calibrates data into the ROOTEvent object
  void FillMappedData() override;                            //!Stores mapped data in detector ROOT class to be written on the output tree
  
  void BuildCalibratedQuantities(UNIMCalibration*) override; //!Executes energy calibrations

private :
  UNIMStripArray *fDSSSDFront;                               //!UNIMStripArray containing mapped event-by-event data for the strip front
  UNIMStripArray *fDSSSDBack;                                //!UNIMStripArray containing mapped event-by-event data for the strip back
  UNIMDSSSDRootEvent * fevt;                                 //!RootEvent type of the detector
                                                             
  const unsigned long fEnergyFrontID;                        //!Identifier of the ENERGYFRONT quantity, used for a fast mapping
  const unsigned long fEnergyBackID;                         //!Identifier of the ENERGYBACK quantity, used for a fast mapping
  const unsigned long fTimeFrontID;                          //!Identifier of the TIMEFRONT quantity, used for a fast mapping
  const unsigned long fTimeBackID;                           //!Identifier of the TIMEBACK quantity, used for a fast mapping

};

#endif
