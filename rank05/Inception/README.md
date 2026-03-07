*This project has been created as part of the 42 curriculum by nash.*

# Inception

## Description

This project builds a small containerized infrastructure on a virtual machine with Docker Compose. The mandatory stack contains NGINX as the only public entrypoint, WordPress with php-fpm, and MariaDB for persistent storage.

## Instructions

### Prerequisites

- Docker Engine with Compose support
- A virtual machine environment
- The domain `nash.42.fr` mapped to the VM IP address

### Build and run

```bash
make build
make up
```

### Stop and clean

```bash
make down
make clean
make fclean
```

## Resources

- Docker documentation: https://docs.docker.com/
- Docker Compose specification: https://compose-spec.io/
- NGINX documentation: https://nginx.org/en/docs/
- MariaDB documentation: https://mariadb.com/kb/en/documentation/
- WordPress and WP-CLI documentation: https://wordpress.org/support/article/how-to-install-wordpress/ and https://developer.wordpress.org/cli/commands/

AI was used to help review the subject, structure the implementation plan, and draft initial infrastructure and documentation scaffolding. Every generated part was reviewed and adjusted before being kept.

## Project Description

This repository includes custom Dockerfiles for MariaDB, WordPress with php-fpm, and NGINX. The main design choice is to keep each mandatory service isolated in its own container, connect them through a dedicated Docker network, and store database and WordPress data in persistent named volumes backed by `/home/nash/data`.

The project sources include Dockerfiles, service-specific configuration files, entrypoint scripts, environment variable definitions, and local Docker secrets files ignored by Git.

### Virtual Machines vs Docker

Virtual machines emulate a full machine with their own kernel-facing guest system. Docker containers share the host kernel and isolate processes, which makes them lighter and faster to start.

### Secrets vs Environment Variables

Environment variables are convenient for non-sensitive configuration and small runtime settings. Secrets are better for passwords because they are exposed as files and reduce the chance of accidentally hardcoding confidential values in images or tracked files.

### Docker Network vs Host Network

A Docker bridge network isolates containers while still allowing service-to-service communication by name. Host networking removes that isolation and is forbidden by the subject.

### Docker Volumes vs Bind Mounts

Named volumes abstract storage management and integrate well with Docker lifecycle. Bind mounts point directly to host paths and are explicitly forbidden for the two mandatory persistent storages in this project.
