FROM debian:12-slim

RUN apt-get update \
	&& apt-get install -y --no-install-recommends nginx openssl gettext-base tini \
	&& rm -rf /var/lib/apt/lists/*

COPY conf/nginx.conf /etc/nginx/nginx.conf
COPY conf/default.conf.template /etc/nginx/templates/default.conf.template
COPY tools/nginx-entrypoint.sh /usr/local/bin/nginx-entrypoint.sh

RUN chmod 755 /usr/local/bin/nginx-entrypoint.sh \
	&& mkdir -p /etc/nginx/ssl /run/nginx /var/www/html

EXPOSE 443

ENTRYPOINT ["tini", "--", "/usr/local/bin/nginx-entrypoint.sh"]
