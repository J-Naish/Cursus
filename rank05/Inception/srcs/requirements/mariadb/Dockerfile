FROM debian:12-slim

RUN apt-get update \
	&& apt-get install -y --no-install-recommends mariadb-server tini \
	&& rm -rf /var/lib/apt/lists/*

COPY conf/60-inception.cnf /etc/mysql/mariadb.conf.d/60-inception.cnf
COPY tools/mariadb-entrypoint.sh /usr/local/bin/mariadb-entrypoint.sh

RUN chmod 755 /usr/local/bin/mariadb-entrypoint.sh \
	&& mkdir -p /run/mysqld /var/lib/mysql \
	&& chown -R mysql:mysql /run/mysqld /var/lib/mysql

EXPOSE 3306

ENTRYPOINT ["tini", "--", "/usr/local/bin/mariadb-entrypoint.sh"]
