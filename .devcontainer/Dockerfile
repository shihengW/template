FROM ubuntu

ARG DEBIAN_FRONTEND=noninterac

# Dependencies.
RUN apt-get update && apt-get install -y \
    cmake git build-essential gdb && \
    rm -rf /var/lib/apt/lists/*

# Install gtest.
RUN git clone https://github.com/google/googletest.git && \
    cd googletest && mkdir build && cd build && \
    cmake .. -Dgtest_disable_pthreads=ON && \
    make && make install && rm -rf ../../googletest

# --------------- To build 32 bit ---------------
# You need:
#   1. install some more libs; 
#   2. rebuild 32 bit gtest;
#
# RUN apt update && apt install -y gcc-multilib g++-multilib && \
#     rm -rf /var/lib/apt/lists/*

# RUN git clone https://github.com/google/googletest.git && \
#     cd googletest && mkdir build && cd build && \
#     cmake .. -Dgtest_disable_pthreads=ON \
#              -DCMAKE_CXX_FLAGS=-m32 \
#              -DCMAKE_C_FLAGS=-m32 && \
#     make && make install && rm -rf ../../googletest
# -----------------------------------------------