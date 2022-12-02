FROM nginx
USER root

COPY ./nginx/nginx.conf /etc/nginx/nginx.conf
COPY ./server.c /home/server.c
COPY ./get_server.sh /home/get_server.sh

RUN apt-get update &&\
apt-get install -y gcc spawn-fcgi libfcgi-dev

EXPOSE 81/tcp
EXPOSE 80/udp

WORKDIR /home/

RUN chmod +x ./get_server.sh

ENTRYPOINT ["sh", "./get_server.sh"]