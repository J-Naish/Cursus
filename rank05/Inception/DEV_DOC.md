# DEV_DOC

## Environment Setup

### Prerequisites

- Docker Engine with Compose support
- A virtual machine
- Local DNS or `/etc/hosts` mapping for `nash.42.fr`

### Required local files

- [`srcs/.env`](/Users/nash/dev/production/myself/cursus/rank05/Inception/srcs/.env)
- [`secrets/credentials.txt`](/Users/nash/dev/production/myself/cursus/rank05/Inception/secrets/credentials.txt)
- [`secrets/db_password.txt`](/Users/nash/dev/production/myself/cursus/rank05/Inception/secrets/db_password.txt)
- [`secrets/db_root_password.txt`](/Users/nash/dev/production/myself/cursus/rank05/Inception/secrets/db_root_password.txt)

## Build and Launch

Build all images:

```bash
make build
```

Launch the infrastructure:

```bash
make up
```

## Container and Volume Management

Inspect the running stack:

```bash
make ps
make logs
```

Stop the stack:

```bash
make down
```

Remove containers and local Docker artifacts:

```bash
make clean
make fclean
```

## Data Persistence

Persistent data is stored on the host under:

- `/home/nash/data/mariadb`
- `/home/nash/data/wordpress`

Docker named volumes map to those directories through bind-backed local volume definitions in `srcs/docker-compose.yml`.
