FROM ubuntu:latest

RUN apt-get update && \
    apt-get install -y valgrind make gcc && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY philo/ /app/philo/
COPY philo_bonus/ /app/philo_bonus/

RUN cd /app/philo && make fclean && \
    cd /app/philo_bonus && make fclean

CMD ["bash"]
