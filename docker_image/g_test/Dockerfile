FROM ubuntu

RUN apt-get update && apt-get upgrade -y\
    && apt-get install -y gcc g++ \
    && apt-get install -y libgtest-dev \
    && apt-get install -y cmake \
    && cd /usr/src/gtest \ 
    && cmake CMakeLists.txt \ 
    && make \ 
    && cp *.a /usr/lib

