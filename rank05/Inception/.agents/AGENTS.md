# Inception Project Requirements

## Overview

System administration project (v5.2) to build a small infrastructure using Docker Compose on a Virtual Machine.

## Directory Structure

```
.
├── Makefile
├── secrets/
│   ├── credentials.txt
│   ├── db_password.txt
│   └── db_root_password.txt
└── srcs/
    ├── .env
    ├── docker-compose.yml
    └── requirements/
        ├── mariadb/
        │   ├── Dockerfile
        │   ├── .dockerignore
        │   ├── conf/
        │   └── tools/
        ├── nginx/
        │   ├── Dockerfile
        │   ├── .dockerignore
        │   ├── conf/
        │   └── tools/
        ├── wordpress/
        │   ├── Dockerfile
        │   ├── .dockerignore
        │   ├── conf/
        │   └── tools/
        ├── bonus/
        └── tools/
```

## Architecture Diagram

```
                              WWW
                               |
                            port 443
                               |
┌──────────────────── Computer HOST ────────────────────────┐
│                                                           │
│  ┌──────────────── Docker network ─────────────────────┐  │
│  │                                                     │  │
│  │  ┌───────────┐  3306  ┌───────────────┐ 9000  ┌─────────┐
│  │  │ Container │◄──────►│   Container   │◄─────►│Container│
│  │  │    DB     │        │ WordPress+PHP │       │  NGINX  │
│  │  └─────┬─────┘        └───────┬───────┘       └─────────┘
│  │        │                      │                         │
│  └────────┼──────────────────────┼─────────────────────────┘
│           │                      │                         │
│      ┌────▼────┐           ┌─────▼─────┐                   │
│      │   DB    │           │ WordPress │                   │
│      │ Volume  │           │  Volume   │                   │
│      └─────────┘           └───────────┘                   │
└───────────────────────────────────────────────────────────┘
```

- External access only through **NGINX (port 443)**
- NGINX → WordPress+PHP via **port 9000** (php-fpm)
- WordPress+PHP → MariaDB via **port 3306**
- Two **named volumes** persist data on the host

## General Rules

- Must be done on a Virtual Machine
- All configuration files go in `srcs/`
- Root `Makefile` must build everything via `docker-compose.yml`
- Must use `docker compose`
- Each Docker image must have the same name as its corresponding service
- Each service must run in a dedicated container
- Base image: **penultimate stable** version of Alpine or Debian
- Write your own Dockerfile per service
- Dockerfiles must be called from `docker-compose.yml` by the root `Makefile`
- Pulling ready-made images from DockerHub is forbidden (Alpine/Debian excluded)
- `latest` tag is prohibited

## Mandatory Services

### NGINX
- TLSv1.2 or TLSv1.3 only
- **Only entrypoint** into the infrastructure (port 443 only)

### WordPress + php-fpm
- Install and configure php-fpm
- Must not contain nginx
- 2 users required (one being the administrator)
- Administrator username must not contain `admin`/`Admin`/`administrator`/`Administrator`

### MariaDB
- Must not contain nginx

## Volumes

- Must use **named volumes** (bind mounts are not allowed)
- One volume for WordPress database
- One volume for WordPress website files
- Host machine storage path: `/home/<login>/data`

## Network

- Define a `docker-network` to connect containers
- `network: host`, `--link`, and `links:` are forbidden
- Network definition must be present in `docker-compose.yml`

## Container Rules

- Must restart on crash (restart policy)
- Must not start with an infinite loop (`tail -f`, `bash`, `sleep infinity`, `while true` are prohibited)
- Follow PID 1 best practices for Dockerfiles

## Security

- No passwords in Dockerfiles
- Must use environment variables
- Must use a `.env` file for environment variables
- Strongly recommended to use Docker secrets for confidential information
- Credentials in the Git repository (outside of properly configured secrets) = project failure

## Domain

- Domain name: `<login>.42.fr`
- Must point to local IP address

## Required Documents

### README.md (must be in English)
- First line (italicized): `This project has been created as part of the 42 curriculum by <login>.`
- **Description**: project goal and brief overview
- **Instructions**: build, install, and execution steps
- **Resources**: references and a description of how AI was used, including which tasks and which parts of the project
- **Project description**: explain Docker usage and include comparisons:
  - Must explain the sources included in the project
  - Must indicate the main design choices
  - Virtual Machines vs Docker
  - Secrets vs Environment Variables
  - Docker Network vs Host Network
  - Docker Volumes vs Bind Mounts

### USER_DOC.md
- What services are provided by the stack
- How to start and stop the project
- How to access the website and admin panel
- Where to find and manage credentials
- How to verify services are running correctly

### DEV_DOC.md
- How to set up the environment from scratch (prerequisites, config files, secrets)
- How to build and launch using Makefile and Docker Compose
- Relevant commands for managing containers and volumes
- Where project data is stored and how it persists

## Bonus (only evaluated if mandatory part is perfect)

- Redis cache for WordPress
- FTP server pointing to WordPress volume
- Simple static website (any language except PHP)
- Adminer
- A service of your choice (must justify during defense)
- Each bonus service needs its own Dockerfile and container
- Each bonus service may have its own dedicated volume if necessary
- Extra ports may be opened for bonus services if needed
