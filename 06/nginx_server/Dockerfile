FROM nginx

COPY ./nginx/nginx.conf etc/nginx/nginx.conf

RUN apt-get update && apt-get install -y nginx \
    && rm -rf /var/lib/apt/lists; \
    chown -R nginx:nginx /etc/nginx/nginx.conf; \
    chown -R nginx:nginx /var/cache/nginx; \
    chown -R nginx:nginx /home; \
    touch /var/run/nginx.pid; \
    chown -R nginx:nginx /var/run/nginx.pid; \
    chmod u-s /usr/bin/gpasswd; \
    chmod u-s /usr/bin/newgrp; \
    chmod u-s /bin/su; \
    chmod u-s /bin/mount; \
    chmod u-s /bin/umount; \
    chmod u-s /usr/bin/chsh; \
    chmod u-s /usr/bin/chfn; \
    chmod u-s /usr/bin/chsh; \
    chmod 255 /usr/bin/expiry; \
    chmod 255 /usr/bin/wall; \
    chmod 255 /sbin/unix_chkpwd; \
    chmod 255 /usr/bin/chage; \
    chmod 755 /usr/bin/passwd;

WORKDIR /home/

RUN groupadd -g 999 new_user && \
    useradd -r -u 999 -g new_user new_user
USER new_user

HEALTHCHECK NONE

ENTRYPOINT ["nginx", "-g", "daemon off;"]

