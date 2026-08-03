#!/bin/bash

DIR=$(dirname $(realpath $0))

PROJECT_NAME="llvm-project"

PROJECT_ROOT="${DIR}/${PROJECT_NAME}"
PROJECT_VERSION="release/16.x"

CYAN="\e[96m"
GREEN="\e[32m"
RED="\e[91m"
RESET="\e[0m"

FAILED=0
SUCCEDDED=0

echo -e "$GREEN -----=======   Cloning LLVM project $GREEN ======----- $RESET\n"
git clone https://github.com/llvm/llvm-project/ "${PROJECT_NAME}"
pushd $PROJECT_ROOT > /dev/null

echo -e "$GREEN -----=======   Checking out project at version: $CYAN $PROJECT_VERSION $GREEN ======----- $RESET\n"
git checkout $PROJECT_VERSION
for patch in $DIR/patch/*.patch; do
    if [ -f "$patch" ]; then 
        echo -e "$GREEN -----=======   Applying patch:$CYAN $(basename $patch) $GREEN ======----- $RESET\n"
        git apply $patch
        if [[ "$?" != 0 ]]; then
            echo -e "$RED!!!!!!!!!   Return Code: FAILED  !!!!!!!!!$RESET\n"
            ((FAILED=FAILED+1))
        else
            echo -e "$GREEN++++++++   Return Code: Success  ++++++++$RESET\n" 
            ((SUCCEDED=SUCCEDED+1))
        fi
    fi
done

echo -e "In a total of $CYAN$((FAILED+SUCCEDED))$RESET patches, $CYAN$FAILED$RESET failed."

popd > /dev/null
