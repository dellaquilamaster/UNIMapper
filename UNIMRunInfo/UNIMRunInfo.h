#ifndef UNIMRUNINFO_H
#define UNIMRUNINFO_H

#include <fstream>
#include <sstream>

class UNIMRunInfo
{
public:
  UNIMRunInfo(long run_number);                          //! Constructor
  ~UNIMRunInfo();                                        //! Destructor
  
  int InitClass(const char *);                           //! Class initializer called by UNIMMapper::InitializeMapper
  
  int LoadSetupConfiguration(const char *);              //! Read general setup lines from configuration file of the experiment
  int LoadRunConfiguration(const char *, long);          //! Read run configuration for a specific run

  const char * GetDataAcquisitionName() const;           //! Get the name of the data acquisition used for the experiment
  const char * GetName() const;                          //! Get Experiment Name
  const char * GetTitle() const;                         //! Get Experiment Title
  long GetRunNumber() const;                             //! Returns run number
  const char * GetMidasROOTFilePath() const;             //! Returns path containing Midas binary files for the run
  const char * GetMappingFile() const;                   //! Returns the path to the mapping file for the run
  const char * GetEnergyCalibrationFile() const;         //! Returns the path to the energy calibration file for the run
  const char * GetUNIMapperROOTFilePath() const;         //! Returns the path to the unpacked files of the run
  bool GetEmptyMappingWarning() const;                   //! Returns true if the empty mapping warning is required, false otherwise

  void SetMidasFilePath(const char *);                   //! Set path for Midas binary files of the run

private:
  long fRunNumber;                                       //!
  std::string fDataAcquisitionName;                      //!
  std::string fExperimentName;                           //!
  std::string fExperimentTitle;                          //!
  std::string fUNIMapperRootFilePath;                    //!
  std::string fMidasROOTFilePath;                        //!
  std::string fEnergyCalibrationsFileName;               //!
  std::string fMappingFileName;                          //!
  bool fEmptyMappingWarning;                             //!
  
  void ParseSetConfigLine(const char *);                 //! Parse a "set" line in the configuration file
  void ParseSetConfigLineRunInfo(const char *, long );   //! Parse a "set" line of a run-by-run instruction
};

#endif
