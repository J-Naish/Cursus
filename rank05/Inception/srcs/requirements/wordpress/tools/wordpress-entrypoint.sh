#!/bin/sh
set -eu

readonly WP_PATH="/var/www/html"
readonly CREDENTIALS_FILE="${WP_CREDENTIALS_FILE:-/run/secrets/credentials}"
readonly DB_PASSWORD_FILE="${MYSQL_PASSWORD_FILE:-/run/secrets/db_password}"

require_env() {
	name="$1"
	value="$(printenv "$name" || true)"
	if [ -z "$value" ]; then
		echo "Missing required environment variable: $name" >&2
		exit 1
	fi
}

read_secret() {
	secret_file="$1"
	if [ ! -f "$secret_file" ]; then
		echo "Missing secret file: $secret_file" >&2
		exit 1
	fi
	tr -d '\r' < "$secret_file"
}

extract_credential() {
	key="$1"
	value="$(sed -n "s/^${key}=//p" "$CREDENTIALS_FILE" | head -n 1)"
	if [ -z "$value" ]; then
		echo "Missing ${key} in credentials secret" >&2
		exit 1
	fi
	printf "%s" "$value"
}

wait_for_database() {
	attempt=0
	while ! mariadb-admin ping \
		-h"${WORDPRESS_DB_HOST}" \
		-u"${MYSQL_USER}" \
		-p"${MYSQL_PASSWORD}" >/dev/null 2>&1; do
		attempt=$((attempt + 1))
		if [ "$attempt" -ge 60 ]; then
			echo "MariaDB is not reachable" >&2
			exit 1
		fi
		sleep 2
	done
}

require_env DOMAIN_NAME
require_env MYSQL_DATABASE
require_env MYSQL_USER
require_env WORDPRESS_DB_HOST

MYSQL_PASSWORD="$(read_secret "$DB_PASSWORD_FILE" | tr -d '\n')"
WP_ADMIN_USER="$(extract_credential WP_ADMIN_USER)"
WP_ADMIN_PASSWORD="$(extract_credential WP_ADMIN_PASSWORD)"
WP_ADMIN_EMAIL="$(extract_credential WP_ADMIN_EMAIL)"
WP_USER="$(extract_credential WP_USER)"
WP_USER_PASSWORD="$(extract_credential WP_USER_PASSWORD)"
WP_USER_EMAIL="$(extract_credential WP_USER_EMAIL)"

mkdir -p /run/php "$WP_PATH"
chown -R www-data:www-data /run/php "$WP_PATH"

if [ ! -f "$WP_PATH/wp-load.php" ]; then
	wp core download --allow-root --path="$WP_PATH"
fi

wait_for_database

if [ ! -f "$WP_PATH/wp-config.php" ]; then
	wp config create \
		--allow-root \
		--path="$WP_PATH" \
		--dbname="$MYSQL_DATABASE" \
		--dbuser="$MYSQL_USER" \
		--dbpass="$MYSQL_PASSWORD" \
		--dbhost="$WORDPRESS_DB_HOST" \
		--dbcharset="utf8mb4"
fi

if ! wp core is-installed --allow-root --path="$WP_PATH" >/dev/null 2>&1; then
	wp core install \
		--allow-root \
		--path="$WP_PATH" \
		--url="https://${DOMAIN_NAME}" \
		--title="Inception" \
		--admin_user="$WP_ADMIN_USER" \
		--admin_password="$WP_ADMIN_PASSWORD" \
		--admin_email="$WP_ADMIN_EMAIL"
fi

if ! wp user get "$WP_USER" --allow-root --path="$WP_PATH" >/dev/null 2>&1; then
	wp user create "$WP_USER" "$WP_USER_EMAIL" \
		--allow-root \
		--path="$WP_PATH" \
		--user_pass="$WP_USER_PASSWORD" \
		--role=author
fi

chown -R www-data:www-data "$WP_PATH"

exec php-fpm8.2 -F
