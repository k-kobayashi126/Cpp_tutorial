FROM ubuntu:22.04

# apt-get時のタイムゾーン設定などで処理が止まるのを防ぐおまじない
ENV DEBIAN_FRONTEND=noninteractive

# 基本ツールとEigen、Git(ETLダウンロード用)のインストール
RUN apt-get update && apt-get install -y \
    build-essential \
    gdb \
    cmake \
    clang \
    git \
    wget \
    libeigen3-dev \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# ETL (Embedded Template Library) をGitHubから取得してシステムに配置
RUN git clone https://github.com/ETLCPP/etl.git /tmp/etl \
    && cp -r /tmp/etl/include/etl /usr/local/include/ \
    && rm -rf /tmp/etl

WORKDIR /workspace