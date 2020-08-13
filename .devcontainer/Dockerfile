FROM ubuntu

ARG DEBIAN_FRONTEND=noninterac

# Dependencies.
RUN apt-get update && apt-get install -y \
    cmake git build-essential gdb && \
    rm -rf /var/lib/apt/lists/*
