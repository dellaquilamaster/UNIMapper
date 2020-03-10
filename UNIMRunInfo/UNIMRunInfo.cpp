#include <UNIMRunInfo.h>

//________________________________________________
UNIMRunInfo::UNIMRunInfo(int run_number) :
fRunNumber(run_number),
fEmptyMappingWarning(true)
{}

//________________________________________________
UNIMRunInfo::~UNIMRunInfo()
{}

//________________________________________________
int UNIMRunInfo::InitClass(const char *file_name)
{
  int NLinesRead=0;

  //Set general setup configuration
  NLinesRead += LoadSetupConfiguration(file_name);
  
  //Load run-by-run information
  NLinesRead += LoadRunConfiguration(file_name,fRunNumber);

  return NLinesRead;
}

//________________________________________________
int UNIMRunInfo::LoadSetupConfiguration(const char *file_name)
{
  std::ifstream FileIn(file_name);
  if(!FileIn.is_open()) {
    return -1;
  }

  int NRead=0;

  while (!FileIn.eof())
  {
    std::string LineRead;
    std::getline(FileIn, LineRead);
    std::string LineReadCommentLess(LineRead.substr(0,LineRead.find("*")));

    if(LineReadCommentLess.empty()) continue;

    if(LineReadCommentLess.find_first_not_of(' ') == std::string::npos) continue;

    if(LineReadCommentLess.find("set ")!=std::string::npos) {
      ParseSetConfigLine(LineReadCommentLess.c_str());
    }

    NRead++;
  }
  FileIn.close();

  return NRead;
}

//________________________________________________
int UNIMRunInfo::LoadRunConfiguration(const char *file_name, int run_num)
{
  std::ifstream FileIn(file_name);
  if(!FileIn.is_open()) {
    return -1;
  }

  int NRead=0;

  while (!FileIn.eof())
  {
    std::string LineRead;
    std::getline(FileIn, LineRead);
    std::string LineReadCommentLess(LineRead.substr(0,LineRead.find("*")));

    if(LineReadCommentLess.empty()) continue;

    if(LineReadCommentLess.find_first_not_of(' ') == std::string::npos) continue;

    if(LineReadCommentLess.find("set ")!=std::string::npos) {
      ParseSetConfigLineRunInfo(LineReadCommentLess.c_str(), run_num);
    }

    NRead++;
  }
  FileIn.close();

  return NRead;
}

const char * UNIMRunInfo::GetName() const
{
  return fExperimentName.c_str();
}

const char * UNIMRunInfo::GetTitle() const
{
   return fExperimentTitle.c_str(); 
}

int UNIMRunInfo::GetRunNumber() const
{
  return fRunNumber;  
} 

const char * UNIMRunInfo::GetMidasROOTFilePath() const
{
  return fMidasROOTFilePath.c_str();  
} 

const char * UNIMRunInfo::GetMappingFile() const
{
  return fMappingFileName.c_str();  
}

const char * UNIMRunInfo::GetEnergyCalibrationFile() const
{
  return fEnergyCalibrationsFileName.c_str();  
}

const char * UNIMRunInfo::GetUNIMapperROOTFilePath() const
{
  return fUNIMapperRootFilePath.c_str();  
}          

bool UNIMRunInfo::GetEmptyMappingWarning() const
{
  return fEmptyMappingWarning;  
}          

//________________________________________________
void UNIMRunInfo::ParseSetConfigLine(const char *line_to_parse)
{
  std::string LineToParse(line_to_parse);

  LineToParse.assign(LineToParse.substr(LineToParse.find("set ")+4)); //remove set command

  std::istringstream LineStream(LineToParse);

  std::string ValueToSet;
  LineStream>>ValueToSet;
  std::string NewValue(LineToParse.substr(LineToParse.find("\"")+1,LineToParse.find_last_of("\"")-(LineToParse.find("\"")+1)));

  if(ValueToSet.compare("EXPERIMENT_NAME")==0) {
    fExperimentName.assign(NewValue);
  } else if (ValueToSet.compare("EXPERIMENT_TITLE")==0) {
    fExperimentTitle.assign(NewValue);
  } else if (ValueToSet.compare("MIDAS_ROOT_FILE_PATH")==0) {
    if(LineToParse.find("--run")==std::string::npos) { //EvtFileName might be different run-by-run, if --run is specified don't set it now but in ParseSetConfigLineRunInfo
      fMidasROOTFilePath.assign(NewValue);
    }
  } else if (ValueToSet.compare("UNIMAPPER_ROOT_FILE_PATH")==0) {
    fUNIMapperRootFilePath.assign(NewValue);
  } else if (ValueToSet.compare("EMPTY_MAPPING_WARNING")==0) {
    std::string TheOption;
    LineStream>>TheOption;
    fEmptyMappingWarning=(TheOption.compare("true")==0 ? true : false);
  }

  return;
}

//________________________________________________
void UNIMRunInfo::ParseSetConfigLineRunInfo(const char *line_to_parse, int run_num)
{
  std::string LineToParse(line_to_parse);

  LineToParse.assign(LineToParse.substr(LineToParse.find("set ")+4)); //remove set command

  std::istringstream LineStream(LineToParse);

  std::string ValueToSet;
  LineStream>>ValueToSet;
  std::string NewValue;
  std::string Option;
  bool RunFound=false;

  //NOTE: for a future improvement take into account more possible options not only --run and --exclude
  //A --run or --exclude option can contain or "," or "-" as a separator, not combination of both
  // Loop on the option strings, every time one finds -- this is an option string, e.g. --run, --exclude
  // 2018/08/20 Included the possibility of specifying only 1 run with --run or --exclude options
  while(LineStream>>Option && Option.find("--")!=std::string::npos) {
    if(Option.find("--run=")!=std::string::npos) {
      Option.assign(Option.substr(Option.find("--run=")+6));
      std::istringstream LineRunStream(Option);
      if(Option.find(",")!=std::string::npos) {
        std::string RunToInclude;
        while(std::getline(LineRunStream, RunToInclude, ',')) {
          if(run_num==std::stoi(RunToInclude)) RunFound=true;
        }
      }
      if(Option.find("-")!=std::string::npos) {
        std::string StartRun;
        std::string StopRun;
        std::getline(LineRunStream, StartRun, '-');
        std::getline(LineRunStream, StopRun, '-');
        int StartRunNum=std::stoi(StartRun);
        int StopRunNum=std::stoi(StopRun);
        if(run_num>=StartRunNum && run_num<=StopRunNum) RunFound=true;
      }
      if(Option.find(",")==std::string::npos && Option.find("-")==std::string::npos && !Option.empty()) {
        if(run_num==std::stoi(Option)) RunFound=true;
      }
    } else if (Option.find("--exclude=")!=std::string::npos) {
        Option.assign(Option.substr(Option.find("--exclude=")+10));
        std::istringstream LineExcludeStream(Option);
        if(Option.find(",")!=std::string::npos) {
          std::string RunToExclude;
          while(std::getline(LineExcludeStream, RunToExclude, ',')) {
            if(run_num==std::stoi(RunToExclude)) return; //this run is excluded
          }
        }
        if(Option.find("-")!=std::string::npos) {
          std::string StartRun;
          std::string StopRun;
          std::getline(LineExcludeStream, StartRun, '-');
          std::getline(LineExcludeStream, StopRun, '-');
          int StartRunNum=std::stoi(StartRun);
          int StopRunNum=std::stoi(StopRun);
          if(run_num>=StartRunNum && run_num<=StopRunNum) return; //this run belong to a bunch of runs to be excluded
        }
        if(Option.find(",")==std::string::npos && Option.find("-")==std::string::npos && !Option.empty()) {
          if(run_num==std::stoi(Option)) return;
        }
      }
  }

  if(RunFound) {
    NewValue.assign(LineToParse.substr(LineToParse.find("\"")+1,LineToParse.find_last_of("\"")-(LineToParse.find("\"")+1)));
  } else return;

  // if I'm here so run_num has been found in the configuration line
  if(ValueToSet.compare("MIDAS_ROOT_FILE_PATH")==0) {
    fMidasROOTFilePath.assign(NewValue);
  } else if (ValueToSet.compare("CHANNEL_MAPPING")==0) {
    fMappingFileName.assign(NewValue);
  } else if (ValueToSet.compare("ENERGY_CALIBRATION")==0) {
    fEnergyCalibrationsFileName.assign(NewValue);
  }

  return;
}
