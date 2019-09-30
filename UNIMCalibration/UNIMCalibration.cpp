#include <UNIMCalibration.h>

//________________________________________________
UNIMCalibration::UNIMCalibration() :
fIsLoaded(false)
{}

//________________________________________________
UNIMCalibration::~UNIMCalibration()
{
  for(std::map<std::string, std::map<unsigned long, std::map<int, UNIMCalibrationElement *> *> *>::iterator it1=fTheCalibrations.begin(); it1!=fTheCalibrations.end(); it1++) {
    for(std::map<unsigned long, std::map<int, UNIMCalibrationElement *> *>::iterator it2=(it1->second)->begin(); it2!=(it1->second)->end(); it2++) {
      for(std::map<int, UNIMCalibrationElement *>::iterator it3=(it2->second)->begin(); it3!=(it2->second)->end(); it3++) {
        delete it3->second;
      }
      delete it2->second;
    }
    delete it1->second;
  }
}

//________________________________________________
int UNIMCalibration::LoadCalibration(const char * file_name)
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
    
    std::istringstream LineStream(LineReadCommentLess);
    
    std::string detector;
    std::string quantity;
    int unit;
    std::string formula;
    int num_parameters;
    double parameter_read;
    std::vector<double> parameters;
    
    LineStream >> detector >> quantity >> unit >> formula >> num_parameters;
    for(int i=0; i<num_parameters; i++) {
      LineStream>>parameter_read;
      parameters.push_back(parameter_read);
    }
    std::replace (formula.begin(), formula.end(), '.', '*');

    //Creating new calibration element
    UNIMCalibrationElement * NewElement = new UNIMCalibrationElement();
    //
    NewElement->SetNumParameters(num_parameters);
    for(int i=0; i<num_parameters; i++) {
      NewElement->SetParameter(i,parameters[i]);
    }
    NewElement->InitCalibration(formula.c_str());
    //
    
    //Insert new calibration element in the list
    if(fTheCalibrations.find(detector)==fTheCalibrations.end()) {
      fTheCalibrations[detector]=new std::map<unsigned long, std::map<int, UNIMCalibrationElement *> *>;
    }
    unsigned long quantity_id = std::hash<std::string>()(quantity);
    if((fTheCalibrations[detector])->find(quantity_id)==(fTheCalibrations[detector])->end()) {
      (*(fTheCalibrations[detector]))[quantity_id]= new std::map<int, UNIMCalibrationElement *>;
    }
    (*(*(fTheCalibrations[detector]))[quantity_id])[unit]=NewElement;
    //

    NRead++;
  }
  FileIn.close();
  
  if(NRead>0) fIsLoaded=true;

  return NRead;
}

//________________________________________________
bool UNIMCalibration::IsPresent() const
{
  return fIsLoaded; 
}

//________________________________________________
UNIMCalibrationElement * UNIMCalibration::GetCalibration(const char * det, unsigned long quantity_id, int unit)
{
  if(fTheCalibrations.find(det)==fTheCalibrations.end()) return 0;
  if((fTheCalibrations[det])->find(quantity_id)==(fTheCalibrations[det])->end()) return 0;
  if(((*(fTheCalibrations[det]))[quantity_id])->find(unit)==((*(fTheCalibrations[det]))[quantity_id])->end()) return 0;
  return (*((*(fTheCalibrations[det]))[quantity_id]))[unit];
}
