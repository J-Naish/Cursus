FROM debian:12-slim

RUN apt-get update \
	&& apt-get install -y --no-install-recommends \
		ca-certificates \
		curl \
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

RUN curl -fsSL https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar -o /usr/local/bin/wp \
	&& chmod 755 /usr/local/bin/wp

COPY conf/www.conf /etc/php/8.2/fpm/pool.d/www.conf
COPY tools/wordpress-entrypoint.sh /usr/local/bin/wordpress-entrypoint.sh

RUN chmod 755 /usr/local/bin/wordpress-entrypoint.sh \
	&& mkdir -p /run/php /var/www/html \
	&& chown -R www-data:www-data /run/php /var/www/html

EXPOSE 9000

ENTRYPOINT ["tini", "--", "/usr/local/bin/wordpress-entrypoint.sh"]
