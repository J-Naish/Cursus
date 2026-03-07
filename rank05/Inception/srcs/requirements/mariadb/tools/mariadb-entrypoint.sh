#!/bin/sh
set -eu

readonly SOCKET_PATH="/run/mysqld/mysqld.sock"
readonly PID_PATH="/run/mysqld/mysqld.pid"
readonly DATA_DIR="/var/lib/mysql"

require_env() {
	name="$1"
	value="$(printenv "$name" || true)"
	if [ -z "$value" ]; then
		echo "Missing required environment variable: $name" >&2
		exit 1
	fi
}

validate_identifier() {
	value="$1"
	case "$value" in
		""|*[!A-Za-z0-9_]*)
			echo "Invalid MariaDB identifier: $value" >&2
			exit 1
			;;
	esac
}

read_secret() {
	secret_file="$1"
	if [ ! -f "$secret_file" ]; then
		echo "Missing secret file: $secret_file" >&2
		exit 1
	fi
	tr -d '\r\n' < "$secret_file"
}

escape_sql_string() {
	printf "%s" "$1" | sed "s/'/''/g"
}

wait_for_socket() {
	attempt=0
	while ! mariadb-admin --socket="$SOCKET_PATH" ping >/dev/null 2>&1; do
		attempt=$((attempt + 1))
		if [ "$attempt" -ge 30 ]; then
			echo "Temporary MariaDB bootstrap timed out" >&2
			exit 1
		fi
		sleep 1
	done
}

require_env MYSQL_DATABASE
require_env MYSQL_USER

validate_identifier "$MYSQL_DATABASE"
validate_identifier "$MYSQL_USER"

MYSQL_ROOT_PASSWORD="$(read_secret "${MYSQL_ROOT_PASSWORD_FILE:-/run/secrets/db_root_password}")"
MYSQL_PASSWORD="$(read_secret "${MYSQL_PASSWORD_FILE:-/run/secrets/db_password}")"

mkdir -p /run/mysqld "$DATA_DIR"
chown -R mysql:mysql /run/mysqld "$DATA_DIR"

if [ ! -d "$DATA_DIR/mysql" ]; then
	mariadb-install-db --user=mysql --datadir="$DATA_DIR" --skip-test-db >/dev/null

	mariadbd \
		--user=mysql \
		--datadir="$DATA_DIR" \
		--socket="$SOCKET_PATH" \
		--pid-file="$PID_PATH" \
		--skip-networking &
	temp_pid="$!"

	wait_for_socket

	escaped_root_password="$(escape_sql_string "$MYSQL_ROOT_PASSWORD")"
	escaped_user_password="$(escape_sql_string "$MYSQL_PASSWORD")"

	mariadb --protocol=socket --socket="$SOCKET_PATH" <<-SQL
		ALTER USER 'root'@'localhost' IDENTIFIED BY '${escaped_root_password}';
		DELETE FROM mysql.user WHERE User='';
		DROP DATABASE IF EXISTS test;
		CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;
		CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${escaped_user_password}';
		GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'%';
		FLUSH PRIVILEGES;
SQL

	mariadb-admin --protocol=socket --socket="$SOCKET_PATH" -uroot -p"$MYSQL_ROOT_PASSWORD" shutdown
	wait "$temp_pid"
fi

exec mariadbd --user=mysql --console
