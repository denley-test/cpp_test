#!/usr/bin/env bash

CUR_PATH=$(cd $(dirname $0); pwd)
WORK_PATH=${CUR_PATH}/..
INSTALL_PATH=${WORK_PATH}/cpp_test

cd ${WORK_PATH} && mkdir -p build && cd build
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=${INSTALL_PATH} .. && make -j$(nproc --all) && make install

cd ${WORK_PATH}
