#include <stdio.h>
#include <stdlib.h>

#include <UNIMMapper.h>
#include <UNIMRawDataReader.h>
#include <UNIMLogo.h>
#include <UNIMShared.h>

int main (int argc, char ** argv)
{
  //Print program logo
  UNIMPrintLogo();

  //Create a new UNIMMapper object
  UNIMMapper * TheMapper = new UNIMMapper();

  //Pass Argument to UNIMMapper object and retrieve run number to analyze
  if(TheMapper->PassArguments(argc,argv)<0) {
    printf("Error: run number was not specified with the --run command\n");
    return -1;
  }

  //Initialize UNIMMapper object
  printf("** Initializing Mapper **\n");
  if(TheMapper->InitializeMapper("config/UNIMapper.conf")!=0) {
    printf("Error while configuring program\n");
    return -2;
  }
  printf("** Mapper correctly initialized **\n");

  //Create UNIMRawDataReader object
  UNIMRawDataReader * TheReader = new UNIMRawDataReader();

  printf("** Initializing Reader **\n");
  //Set Mapper to UNIMRawDataReader object
  TheReader->SetMapper(TheMapper);

  //Initialize UNIMRawDataReader object
  if(TheReader->InitReader()!=0) {
    printf("Error while initializing UNIMRawDataReader class\n");
    TheReader->EndProcess();
    return -3;
  }
  printf("** Reader correctly initialized **\n");
  

  //Main loop UNIMRawDataReader::ProcessRawTree()
  printf("** Mapping run %d **\n", gRun->GetRunNumber());
  TheReader->ProcessRawTree();


  //End mapping process UNIMRawDataReader::EndProcess()
  TheReader->EndProcess();

  return 0;
}
