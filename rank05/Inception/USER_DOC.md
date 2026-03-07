# USER_DOC

## Provided Services

- NGINX serving HTTPS on port 443
- WordPress running with php-fpm
- MariaDB storing WordPress data

## Start and Stop

If `srcs/.env` does not exist yet, create it from the example first:

```bash
cp srcs/.env.example srcs/.env
```

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

- Website: `https://rnishi.42.fr`
- WordPress admin panel: `https://rnishi.42.fr/wp-admin`

## Credentials

Credentials are stored locally in the `secrets/` directory:

- `secrets/credentials.txt`
- `secrets/db_password.txt`
- `secrets/db_root_password.txt`

These files are ignored by Git and should be updated locally as needed.
The values in `secrets/credentials.txt` are used only when WordPress is installed for the first time on an empty persistent volume.
If you change them after the initial installation, reset the persistent data before expecting the new users to appear.

## Service Checks

Useful checks:

```bash
make ps
make logs
docker compose -f srcs/docker-compose.yml --env-file srcs/.env exec mariadb mariadb-admin ping
```
