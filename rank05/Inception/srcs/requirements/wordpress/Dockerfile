FROM debian:12-slim AS downloader

ARG WORDPRESS_VERSION=6.9.1
ARG WP_CLI_VERSION=2.12.0

RUN apt-get update \
	&& apt-get install -y --no-install-recommends ca-certificates curl tar \
	&& rm -rf /var/lib/apt/lists/*

RUN curl -fsSL "https://wordpress.org/wordpress-${WORDPRESS_VERSION}.tar.gz" -o /tmp/wordpress.tar.gz \
	&& tar -xzf /tmp/wordpress.tar.gz -C /usr/src \
	&& rm -f /tmp/wordpress.tar.gz

RUN curl -fsSL "https://github.com/wp-cli/wp-cli-bundle/releases/download/v${WP_CLI_VERSION}/wp-cli-${WP_CLI_VERSION}.phar" -o /usr/local/bin/wp \
	&& chmod 755 /usr/local/bin/wp

FROM debian:12-slim

RUN apt-get update \
	&& apt-get install -y --no-install-recommends \
		mariadb-client \
		php-fpm \
		php-mysql \
		php-curl \
		php-gd \
		php-mbstring \
		php-xml \
		php-xmlrpc \
		php-soap \
		php-intl \
		php-zip \
		php-cli \
		tini \
	&& rm -rf /var/lib/apt/lists/*

COPY conf/www.conf /etc/php/8.2/fpm/pool.d/www.conf
COPY tools/wordpress-entrypoint.sh /usr/local/bin/wordpress-entrypoint.sh
COPY --from=downloader /usr/local/bin/wp /usr/local/bin/wp
COPY --from=downloader /usr/src/wordpress /usr/src/wordpress

RUN chmod 755 /usr/local/bin/wordpress-entrypoint.sh \
	&& chmod 755 /usr/local/bin/wp \
	&& mkdir -p /run/php /usr/src/wordpress /var/www/html \
	&& chown -R www-data:www-data /run/php /usr/src/wordpress /var/www/html \
	&& php /usr/local/bin/wp --info >/dev/null

EXPOSE 9000

ENTRYPOINT ["tini", "--", "/usr/local/bin/wordpress-entrypoint.sh"]
