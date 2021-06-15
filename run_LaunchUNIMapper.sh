#!/bin/bash

cd ${UNIMapperSrc}

#extracting information from configuration file from config/UNIMapper.conf
while IFS= read -r line;do
    fields=($(printf "%s" "$line"|cut --output-delimiter=' ' -f1-))
    if [ ${fields[1]} ] && [ ${fields[1]} = "MIDAS_ROOT_FILE_PATH" ] ; then
      DATA_PATH=$(echo ${fields[2]} | sed 's/[\"]//g')
      break
    fi
done < config/UNIMapper.conf

echo $DATA_PATH

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

for file_name in $(ls ${DATA_PATH});
do
  
  run_name=$(echo $file_name | grep -o -P '(?<=run_).*(?=.root)')
  
  re='^[0-9]+$'

  if ! [[ ${run_name} =~ $re ]] ; then
       continue
  fi
    
    if [ -z $3 ]
    then
      if [ ${run_name} -le ${last_run} ] && [ ${run_name} -ge ${first_run} ] ;
      then
        echo "Mapping run $run_name..."
        eval './exec_UNIMapper.exe --run=${run_name}'
      fi
    else
      if [ ${run_name} -le ${last_run} ] && [ ${run_name} -ge ${first_run} ] ;
      then
        echo "echo Mapping run $run_name... && eval './exec_UNIMapper.exe --run=${run_name}'" >> parallel_runs.txt
      fi
    
    fi
done

if [ ! -z "$3" ]; then
  parallel $parallel_processes < parallel_runs.txt
  rm -f parallel_runs.txt
fi
