#!/bin/bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
export UNIMapperSrc=${DIR}/

export LD_LIBRARY_PATH=$UNIMapperSrc/lib:$LD_LIBRARY_PATH
