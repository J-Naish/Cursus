# USER_DOC

## Provided Services

- NGINX serving HTTPS on port 443
- WordPress running with php-fpm
- MariaDB storing WordPress data

## Start and Stop

Start the stack:

```bash
make up
```

Stop the stack:

```bash
make down
```

Remove containers, volumes, and local images:

```bash
make fclean
```

## Access

- Website: `https://nash.42.fr`
- WordPress admin panel: `https://nash.42.fr/wp-admin`

## Credentials

Credentials are stored locally in the `secrets/` directory:

- [`credentials.txt`](/Users/nash/dev/production/myself/cursus/rank05/Inception/secrets/credentials.txt)
- [`db_password.txt`](/Users/nash/dev/production/myself/cursus/rank05/Inception/secrets/db_password.txt)
- [`db_root_password.txt`](/Users/nash/dev/production/myself/cursus/rank05/Inception/secrets/db_root_password.txt)

These files are ignored by Git and should be updated locally as needed.

## Service Checks

Useful checks:

```bash
make ps
make logs
docker compose -f srcs/docker-compose.yml --env-file srcs/.env exec mariadb mariadb-admin ping
```
