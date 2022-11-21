#!/usr/bin/env bash

CUR_PATH=$(cd $(dirname $0); pwd)
WORK_PATH=${CUR_PATH}/..
INSTALL_PATH=${WORK_PATH}/cpp_test

cd ${WORK_PATH}
cmake -S . -B build -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=${INSTALL_PATH}
cd build && make && make install

cd ${INSTALL_PATH}/bin
./glog_test --alsologtostderr=true --colorlogtostderr=true
cd ${WORK_PATH}
