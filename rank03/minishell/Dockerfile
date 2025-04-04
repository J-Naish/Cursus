FROM ubuntu:latest

RUN apt-get update && \
    apt-get install -y valgrind make gcc && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY src/ /app/src/
COPY Makefile /app/Makefile

RUN make fclean

CMD ["bash"]
