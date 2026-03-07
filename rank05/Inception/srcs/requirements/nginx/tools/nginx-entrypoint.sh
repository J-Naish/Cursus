#!/bin/sh
set -eu

readonly SSL_DIR="/etc/nginx/ssl"
readonly CERT_PATH="${SSL_DIR}/inception.crt"
readonly KEY_PATH="${SSL_DIR}/inception.key"
readonly TEMPLATE_PATH="/etc/nginx/templates/default.conf.template"
readonly TARGET_CONF="/etc/nginx/conf.d/default.conf"

require_env() {
	name="$1"
	value="$(printenv "$name" || true)"
	if [ -z "$value" ]; then
		echo "Missing required environment variable: $name" >&2
		exit 1
	fi
}

require_env DOMAIN_NAME

mkdir -p "$SSL_DIR" /run/nginx /var/www/html

if [ ! -f "$CERT_PATH" ] || [ ! -f "$KEY_PATH" ]; then
	openssl req -x509 -nodes -days 365 \
		-newkey rsa:2048 \
		-keyout "$KEY_PATH" \
		-out "$CERT_PATH" \
		-subj "/C=JP/ST=Tokyo/L=Tokyo/O=42Tokyo/OU=Inception/CN=${DOMAIN_NAME}"
fi

envsubst '${DOMAIN_NAME}' < "$TEMPLATE_PATH" > "$TARGET_CONF"

exec nginx -g 'daemon off;'
