#!/usr/bin/env bash

CUR_PATH=$(cd $(dirname $0); pwd)
WORK_PATH=${CUR_PATH}/..
INSTALL_PATH=${WORK_PATH}/cpp_test

cd ${INSTALL_PATH}/bin
./glog_test --alsologtostderr=true --colorlogtostderr=true
cd ${WORK_PATH}
