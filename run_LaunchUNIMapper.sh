#!/bin/bash

FRAMEWORK_PATH="/home/daniele/Dropbox/Ricerca/Ruder_Boskovic/software/UNIMapper/"

cd ${FRAMEWORK_PATH}
source UNIMapper.sh

first_run=$1

if [ -z "$2" ]; then
  last_run=$1
else
  last_run=$2
fi

for run_num in `seq $first_run $last_run`
do
re='^[0-9]+$'

if ! [[ $run_num =~ $re ]] ; then
   echo "Error: Invalid run number" >&2; exit 1
fi

./exec_UNIMapper.exe --run=$run_num

done
