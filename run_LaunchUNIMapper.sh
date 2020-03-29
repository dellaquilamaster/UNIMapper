#!/bin/bash

cd ${UNIMapperSrc}

first_run=$1

if [ -z "$2" ]; then
  last_run=$1
else
  last_run=$2
fi

if [ ! -z "$3" ]; then
  parallel_processes=$3
fi

if [ -f "parallel_runs.txt" ]; then
  rm -f parallel_runs.txt
fi

for run_num in `seq $first_run $last_run`
do
re='^[0-9]+$'

if ! [[ $run_num =~ $re ]] ; then
   echo "Error: Invalid run number" >&2; exit 1
fi

if [ ! -z "$3" ]; then
  echo "Mapping run $run_num... && eval './exec_UNIMapper.exe --run=$run_num'" >> parallel_runs.txt      
else 
  ./exec_UNIMapper.exe --run=$run_num
fi

done

if [ ! -z "$3" ]; then
  parallel $parallel_processes < parallel_runs.txt
  rm -f parallel_runs.txt
fi
