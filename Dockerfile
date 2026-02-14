FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
    build-essential \
    gdb \
    cmake \
    clang \
    && apt-get clean

WORKDIR /workspace
