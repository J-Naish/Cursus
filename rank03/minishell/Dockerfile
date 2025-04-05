FROM ubuntu:latest

RUN apt-get update && \
    apt-get install -y valgrind make gcc man-db && \
    yes | unminimize && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . /app/

CMD ["bash"]
