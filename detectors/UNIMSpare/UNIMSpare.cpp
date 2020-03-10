#include <UNIMSpare.h>

//________________________________________________
UNIMSpare::UNIMSpare(const char * name) :
UNIMDetector(name)
{
  fType.assign("UNIMSpare");
}

//________________________________________________
UNIMSpare::~UNIMSpare()
{
  for(int i=0; i<fNumDetectors; i++) {
    delete fSpareChannels[i];
  }
}

//________________________________________________
void UNIMSpare::Clear()
{
  for(auto&& quantity : fSpareChannels) {
    quantity.second->Clear();
  }
}

//________________________________________________
void UNIMSpare::DefineQuantity(const char * the_quantity)
{
  unsigned long quantity_id=std::hash<std::string>()(std::string(the_quantity));
  fSpareChannels[quantity_id] = new UNIMSpareChannel(the_quantity);
}

//________________________________________________
void UNIMSpare::SetQuantity(unsigned long quantity_code, int det_unit, Short_t value)
{
  fSpareChannels[quantity_code]->SetValue(value);
}

//________________________________________________
void UNIMSpare::InitTTreeBranch(TTree * theTree)
{
  for(auto&& quantity : fSpareChannels) {
    theTree->Branch(Form("%s.%s",fName.c_str(),quantity.second->GetName()),(Short_t*)quantity.second->GetValuePointer());
  }
  
  return;
}

//________________________________________________
void UNIMSpare::BuildEvent()
{
  //Fill Root Event structure to be written on the tree
  FillMappedData();

  return;
}

//________________________________________________
void UNIMSpare::FillMappedData()
{
  // The entire data is used to fill the tree, no selection is made and no auxiliary data structures are needed
}
