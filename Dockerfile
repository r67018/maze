FROM ubuntu:20.04
WORKDIR /root

COPY Makefile .
COPY src src/

RUN apt update && apt install -y \
    g++ \
    make
RUN make CFLAGS="-DPRINT_CREATE_PROCESS"

WORKDIR /root/build
