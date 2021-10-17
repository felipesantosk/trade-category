FROM ubuntu:latest

RUN apt-get update && \
    apt-get install -y clang clang-format cmake gdb llvm && \
    apt-get clean

RUN apt-get update && \
    apt-get install -y python3 python3-pip && \
    apt-get clean && \
    pip3 install conan 

