# UNIMapper
A Unified Mapper program for the Rudjer Boskovic Institute nuclear clustering group.

Contributors: Daniele Dell'Aquila

Rudjer Boskovic Institute, Zagreb, Croatia

This software is able to store, in useful detector data structures, Midas data unpacked with the Midas2ROOT software. The novelty of this software is that it can systematically map an arbitrary configuration of detectors (with DSSSDs, SSSSDs and Lamp Wedges) without any change in the code. All the information is uniquely given by a configuration file. The aim of this software is to be fully reliable for each experiment carried out with the Midas DAQ.

# Useful links:
  * [Rudjer Boskovic Institute](https://www.irb.hr/eng) : Rudjer Boskovic Institute official website
  
Table of contents
=================
<!--ts-->
* [Getting the code](#getting-the-code)
  * [Using git](#using-git)
  * [Downloading from Git Hub](#downloading-from-git-hub)
* [Setup and Configuration](#setup-and-configuration)
  * [Requirements](#requirements)
  * [Environment Variables](#environment-variables)  
  * [Compile the Code](#compile-the-code)
  * [Configure the Program](#configure-the-program)
  * [Limitations](#limitations)
* [The UNIMapper Program](#the-unimapper-program)
  * [Run the Code](#run-the-code)
  * [Mapping File](#mapping-file)
  * [Energy Calibration File](#energy-calibration-file)
  * [Output Data](#output-data)
  * [Notes for Developers](#notes-for-developers)
<!--te-->

## Getting the code
### Using git
The latest version of the code can be obtained by using the git command. This is possible after installing git on a linux machine (see https://git-scm.com/download/linux for further documentation on how to install git). Use the following command to download UNIMapper:
````
$ git clone https://github.com/dellaquilamaster/UNIMapper.git
````
### Downloading from Git Hub
The code can be downloaded also frm the Git Hub web page at the link: https://github.com/dellaquilamaster/UNIMapper.git, by
clicking on the "Clone or Download" button on the right side of the page and then "Download ZIP". It is possible to donwload also a previous release of the code. For a complete list of all the releases please visit: https://github.com/dellaquilamaster/UNIMapper/releases.
## Setup and Configuration
### Requirements
The code is compiled using the g++ compiler.
In order to compile and run the code ROOT >=6 is required (the program has been tested with version 6.16.00). It is not recommended to compile the code with an installation of ROOT <=5.
### Environment Variables
Before compiling or running the code, it is required to export the needed environment variables and aliases. This can be done by launching, from the main folder of UNIMapper, the command:
````
$ source UNIMapper.sh
````
This can usually be done automatically in the bashrc file.
### Compile the Code
To compile the code and make a clean installation use the sequence of commands:
````
$ make clean
$ make distclean
$ make -jN
````
N will be the number of parallel compilation processes that will be launched.
The binary file exec_UNIMapper.exe is generated in the compilation.
### Configure the program
The program can be fully configured by uniquely modifying the following file:
````
config/UNIMapper.conf
````
In the special language used to read the file, the character '\*' is used to provide a comment.  
Following a detailed list of the general fields to configure:
* set UNIMAPPER_SUMMARY_PATH : not used in the current version of the program
* set UNIMAPPER_ROOT_FILE_PATH : the output files are stored in this folder
* set EXPERIMENT_NAME : this is the name of the experiment without spaces. This name is also used as the name of the output TTree
* set EXPERIMENT_TITLE : an arbitrary title for the experiment
* set MIDAS_ROOT_FILE_PATH : the input folder of the program. This corresponds to the output folder of the Midas2ROOT program and is the folder where the Midas unpacked files are stored. NOTE: this option can be also specified on a run-by-run basis, see below.
There are also run-by-run fields to configure. This can be done by adding to the set <COMMAND> one of the following options:  
* --run=x-y : this makes the line valid for a group of runs starting with x and ending with y  
* --run=x1,x2,x3,... : this makes the line valid for runs x1,x2,x3,...  
* --exclude=x1,x2,x3,... : this excludes runs x1,x2,x3,... from this line  
* --exclude=x-y,... : this excludes runs x-y from this line  
One can also combine an arbitrary number of --run and --exclude options in the same line (WARNING: do not combine "-" and "," symbols in the same --run or --exclude command).  
Example: set <COMMAND> --run=1-10 --run=15,18 --exclude=2,5 --exclude=7-8 -> this applies the command "COMMAND" to the runs: 1,3,4,6,9,10,15,18  
Following a detailed list of run-by-run commands:  
* set MIDAS_ROOT_FILE_PATH : as above but run-by-run. If this is specified, it is prevalent
* set CHANNEL_MAPPING : specify the mapping file for the group of runs
* set ENERGY_CALIBRATION : specify the energy calibration file for the group of runs
### Limitations

## The The UNIMapper Program
### Run the code
To run the UNIMapper program use the following command from the main program directory:
````
$ ./exec_UNIMapper.exe --run=<N>
````
N will be the number of run to map.
### Mapping File
The mapping file (usually *.map) contains the definition of detectors and associated electronics channels.  
It can be written according to the following guide.  
To define a detector use the command:
````
define detector <DetType> "name" options
````
Possible values for <DetType> and options are:  
* DSSSD : Double-Sided Silicon Strip Detectors -> options : number_of_strips  
* SSSSD : Single-Sided Silicon Strip Detectors -> options : number_of_strips  
* LampWedge : Lamp Wedge -> options : number_of_strips  
* Spare : Some spare channels (arbitrary quantities) -> options : names of all quantities separated by space    
"name" is the name associated to the detector, that will be used to name the corresponding data structure. This has to be inserted with the quotes.
To map a single detector channel to a given pair (gid, channel) use the command:  
````
map <DetName> <ChName> detector="SingleDetName" gid="gidnumber" channel="ch"
````
Where <DetName> will be the name associated to the detector without quotes, <ChName> is the name of the quantity to set (see list below), SingleDetName is the name of the individual detection unit (e.g. number of strip), gidnumber is the associated gid in the Midas DAQ, ch is the associated ch in the Midas DAQ.  
Possible values of <ChName> depend on the detector according to the following list:  
* DSSSD : ENERGYFRONT ENERGYBACK TIMEFRONT TIMEBACK  
* SSSSD : ENERGY TIME  
* LampWedge : ENERGY TIME  
* SiliconPad : ENERGY TIME  ("SingleDetName" here is always 0)  
* Spare : QUANTITY1 QUANTITY2 ... QUANTITYN ("SingleDetName" here is always 0)  
### Energy Calibration File
Energy calibrations for each individual detection unit are specified by a .ene file. In this fine, each line specifies the calibration of a certain quantity of a certain detector according to the following scheme:  
````
detector        quantity        unit        formula       n_parameters        the_parameters.....  
````
* detector : name of the detector as previously set
* quantity : name of the quantity to calibrate (e.g. ENERGYFRONT)
* unit : number of the detection unit to set (e.g. 0 for strip 0)
* formula : this is according to the ROOT standard with with the "." instead of "*" (e.g. [0]+[1].x for a simple linear calibration)
* n_parameters : number of required parameters
* the_parameters : all the parameters, in the correct order as in the formula
### Output Data
Output data is stored in a tree called as the experiment name (see section "Configure the Program). The folder where the tree is stored is configured in the config file by setting UNIMAPPER_ROOT_FILE_PATH in the configuration file (see section "Configure the Program").

The structure of the output tree is constituted by an individual branch for each detector defined in the mapping file. The name of each branch will be the same as the name of the detector. Sub-branches are created according to the individual detector data structures.
Here a summary of the data structures for each detector:  
**_DSSSD_**  
|- **UNIMDSSSDData**  
|&nbsp;&nbsp;&nbsp;+ int fmultif  
|&nbsp;&nbsp;&nbsp;+ int fnumstripf\[fmultif\]  
|&nbsp;&nbsp;&nbsp;+ Short_t fEnergyFront\[fmultif\]  
|&nbsp;&nbsp;&nbsp;+ Short_t fTimeFront\[fmultif\]  
|&nbsp;&nbsp;&nbsp;+ double fEnergyFrontCal\[fmultif\]  
|&nbsp;&nbsp;&nbsp;+ int fmultib  
|&nbsp;&nbsp;&nbsp;+ int fnumstripf\[fmultib\]  
|&nbsp;&nbsp;&nbsp;+ Short_t fEnergyBack\[fmultib\]  
|&nbsp;&nbsp;&nbsp;+ Short_t fTimeBack\[fmultib\]  
|&nbsp;&nbsp;&nbsp;+ double fEnergyBackCal\[fmultib\]  
**_SSSSD_**  
|- **UNIMSSSSDData**  
|&nbsp;&nbsp;&nbsp;+ int fmulti  
|&nbsp;&nbsp;&nbsp;+ int fnumstrip\[fmulti\]  
|&nbsp;&nbsp;&nbsp;+ Short_t fEnergy\[fmulti\]  
|&nbsp;&nbsp;&nbsp;+ Short_t fTime\[fmulti\]  
|&nbsp;&nbsp;&nbsp;+ double fEnergyCal\[fmulti\]  
**_LampWedge_**  
|- **UNIMLampWedgeData**  
|&nbsp;&nbsp;&nbsp;+ int fmulti  
|&nbsp;&nbsp;&nbsp;+ int fnumstrip\[fmulti\]  
|&nbsp;&nbsp;&nbsp;+ Short_t fEnergy\[fmulti\]  
|&nbsp;&nbsp;&nbsp;+ Short_t fTime\[fmulti\]  
|&nbsp;&nbsp;&nbsp;+ double fEnergyCal\[fmulti\] 
## Notes for Developers
