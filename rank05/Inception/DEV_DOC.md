# DEV_DOC

## Environment Setup

### Prerequisites

- Docker Engine with Compose support
- A virtual machine
- Local DNS or `/etc/hosts` mapping for `rnishi.42.fr`

### Required local files

- `srcs/.env`
- `srcs/.env.example`
- `secrets/credentials.txt`
- `secrets/db_password.txt`
- `secrets/db_root_password.txt`

`secrets/credentials.txt` seeds the initial WordPress administrator and regular user only when the WordPress data volume is empty.
If the stack has already been initialized, delete the persistent data before reapplying changed WordPress credentials.

Create the runtime environment file from the tracked example before running the stack:

```bash
cp srcs/.env.example srcs/.env
```

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

- `/home/rnishi/data/mariadb`
- `/home/rnishi/data/wordpress`

Docker named volumes map to those directories through bind-backed local volume definitions in `srcs/docker-compose.yml`.

For local validation on macOS, `DATA_ROOT` can be overridden at runtime to use a writable local path while keeping `/home/rnishi/data` as the default target for the final VM environment.
