FROM ubuntu:latest

RUN apt-get update && \
    apt-get install -y clang clang-format cmake gdb llvm && \
    apt-get clean


