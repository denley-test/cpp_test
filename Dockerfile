FROM denley/cmake:3.16.0

RUN apt-get update -y && apt-get install -y libcppunit-dev libgflags-dev libgtest-dev

RUN git clone https://github.com/google/glog && cd glog && \
  cmake -DWITH_CUSTOM_PREFIX=ON -DCMAKE_BUILD_TYPE=Release && make && make install && \
  cd .. && rm -fr glog

ENV LD_LIBRARY_PATH /usr/local/lib:$LD_LIBRARY_PATH
ENV LD_LIBRARY_PATH /usr/local/lib64:$LD_LIBRARY_PATH
