#include <UNIMDetectorMap.h>

//________________________________________________
UNIMDetectorMap::UNIMDetectorMap()
{}

//________________________________________________
UNIMDetectorMap::~UNIMDetectorMap()
{
  printf("distruggo il detector mappa\n");
  printf("finito di distruggere il detector mappa\n");
}

//________________________________________________
void UNIMDetectorMap::SetDetectors(std::map<std::string, UNIMDetector *> * TheDetectors)
{
  fTheDetectors=TheDetectors;
}

//________________________________________________
int UNIMDetectorMap::LoadMapping(const char * file_name)
{
  std::ifstream FileIn(file_name);

  if(!FileIn.is_open()) {
    return -1;
  }

  int NChannelsMapped=0;

  while (!FileIn.eof())
  {
    std::string LineRead;
    std::getline(FileIn, LineRead);
    std::string LineReadCommentLess(LineRead.substr(0,LineRead.find("*")));

    if(LineReadCommentLess.empty()) continue;

    if(LineReadCommentLess.find_first_not_of(' ') == std::string::npos) continue;

    if(LineReadCommentLess.find("map ")!=std::string::npos) {
      NChannelsMapped+=ParseMapLine(LineReadCommentLess.c_str());
    }
  }
  FileIn.close();

  return NChannelsMapped;
}

//________________________________________________
int UNIMDetectorMap::ParseMapLine(const char * line_to_parse)
{
  std::string LineReadCommentLess(line_to_parse);
  std::istringstream LineStream(LineReadCommentLess.substr(LineReadCommentLess.find("map ")+4));
  std::string DetectorName;
  std::string ChName;
  std::string DetectorToSet;
  std::string ModuleName;
  std::string ModuleChannelString;
  LineStream>>DetectorName>>ChName>>DetectorToSet>>ModuleName>>ModuleChannelString;

  DetectorToSet.assign(DetectorToSet.substr(DetectorToSet.find("detector=\"")+10,DetectorToSet.find_last_of("\"")-(DetectorToSet.find("detector=\"")+10)));
  ModuleName.assign(ModuleName.substr(ModuleName.find("gid=\"")+5,ModuleName.find_last_of("\"")-(ModuleName.find("gid=\"")+5)));
  ModuleChannelString.assign(ModuleChannelString.substr(ModuleChannelString.find("channel=\"")+9,ModuleChannelString.find_last_of("\"")-(ModuleChannelString.find("channel=\"")+9)));

  int DetectionUnitNumber=std::stoi(DetectorToSet);
  int GidNumber=std::stoi(ModuleName);
  int ModuleChannel=std::stoi(ModuleChannelString);
  
  //Creating the new map element
  if((*fTheDetectors).find(DetectorName.c_str())==(*fTheDetectors).end()) return 0; // if this is true the detector DetectorName does not exist
  UNIMMapElement * NewMap = new UNIMMapElement();
  NewMap->SetDetector((*fTheDetectors)[DetectorName.c_str()]);
  NewMap->SetUnit(DetectionUnitNumber);
  NewMap->SetQuantity(ChName.c_str());
  
  SetMapping(GidNumber,ModuleChannel,NewMap);

  return 1;
}

//________________________________________________
UNIMMapElement * UNIMDetectorMap::GetAssociation(int gid, int ch)
{
  return (IsMapped(gid,ch) ? ((*(fTheMapping[gid])))[ch] : 0);
}

//________________________________________________
bool UNIMDetectorMap::IsMapped(int gid, int ch)
{
  return ((fTheMapping.find(gid)!=fTheMapping.end() && (*(fTheMapping[gid])).find(ch)!=(*(fTheMapping[gid])).end()) ? true : false);
}

//________________________________________________
void UNIMDetectorMap::SetMapping(int gid, int ch, UNIMMapElement * NewElement)
{
  if(fTheMapping.find(gid)==fTheMapping.end()) {
    //first occurrence of this gid, I create its correpsonding map
    std::map<int, UNIMMapElement *> * NewMap = new std::map<int, UNIMMapElement *>();
    (fTheMapping[gid])=NewMap;
  }
  
  (*(fTheMapping[gid]))[ch]=NewElement;
  
  return;
}


