FROM ubuntu:latest

# Update packages and install Valgrind
RUN apt-get update && \
    apt-get install -y valgrind && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# Create directory for the project
WORKDIR /app

# Copy both philo and philo_bonus directories
COPY philo/ /app/philo/
COPY philo_bonus/ /app/philo_bonus/

# Set default command to bash
CMD ["bash"]
