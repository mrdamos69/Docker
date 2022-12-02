# Simple Docker отчет brittabu

## Part 1. Готовый докер

##### Берем официальный докер образ с **nginx** и выкачать его при помощи `docker pull`
![alt text](screenshots/1.1.png)

##### Проверяем наличие докер образа через `docker images`
![alt text](screenshots/1.2.png)

##### Запускаем докер образ через `docker run -d [image_id|repository]`
![alt text](screenshots/1.3.png)

##### Проверяем, что образ запустился через `docker ps`
![alt text](screenshots/1.4.png)

##### Смотрим информацию о контейнере через `docker inspect [container_id|container_name]`
![alt text](screenshots/1.5.png)

##### По выводу команды определяем размер контейнера, список замапленных портов и ip контейнера
![alt text](screenshots/1.6.png)
![alt text](screenshots/1.7.png)

##### Останавливаем докер образ через `docker stop [container_id|container_name]` и проверяем что образ остановился через `docker ps`
![alt text](screenshots/1.8.png)

##### Запускаем докер с замапленными портами 80 и 443 на локальную машину через команду *run*
![alt text](screenshots/1.9.png)

##### Проверяем, что в браузере по адресу *localhost:80* доступна стартовая страница **nginx**
![alt text](screenshots/1.10.png)

##### Перезапускаем докер контейнер через `docker restart [container_id|container_name]` и проверяем, что контейнер запустился
![alt text](screenshots/1.11.png)


## Part 2. Операции с контейнером

##### Открытие конфигурационного файла *nginx.conf* внутри докер контейнера через команду *exec*
![alt text](screenshots/2.1.png)

##### Создаем на локальной машине файл *nginx.conf* и настраиваем в нем по пути */status* отдачу страницы статуса сервера **nginx**
![alt text](screenshots/2.2.png)

##### Копируем созданный файл *nginx.conf* внутрь докер образа через команду `docker cp`
![alt text](screenshots/2.3.png)

##### Перезапускаем **nginx** внутри докер образа через команду *exec*
![alt text](screenshots/2.4.png)

##### Проверяем, что по адресу *localhost:80/status* отдается страничка со статусом сервера **nginx**
![alt text](screenshots/2.5.png)

##### Экспортируем контейнер в файл *container.tar* через команду *export* и останавливаем контейнер
![alt text](screenshots/2.6.png)

##### Удаляем образ через `docker rmi [image_id|repository]`, не удаляя перед этим контейнеры
![alt text](screenshots/2.7.png)
![alt text](screenshots/2.8.png)

##### Удаляем остановленный контейнер
![alt text](screenshots/2.9.png)

##### Импортируем контейнер обратно через команду *import*
![alt text](screenshots/2.10.png)

##### Запускаем импортированный контейнер
![alt text](screenshots/2.11.png)

##### Проверяем, что по адресу *localhost:80/status* отдается страничка со статусом сервера **nginx**
![alt text](screenshots/2.12.png)

## Part 3. Мини веб-сервер

##### Для того что бы написать мини сервер на **C** и **FastCgi**, который будет возвращать простейшую страничку с надписью `Hello World!` нам необходимо:

##### Скачать офицальный докер образ с **nginx** и выкачать его при помощи `docker pull` и запустить его через `docker run -d [image_id|repository]`
![alt text](screenshots/3.1.png)

##### Пишем свой сервер мини сервер на **C**. Используем для этого библиотеку *fcgi_stdio.h*
![alt text](screenshots/3.2.png)

##### Пишем свой *nginx.conf*, который будет проксировать все запросы с 81 порта на *127.0.0.1:8080*.
![alt text](screenshots/3.3.png)

##### Отправляем `server.c` и `nginx.conf` в наш запущенный контейнер и входим в него
![alt text](screenshots/3.4.png)

##### Для того что бы у нас все успешно запустилось гам нужно установить в наш контейнер компилятор gcc и все необходимое для библиотеки *fcgi*
![alt text](screenshots/3.5.png) 

##### Запускаем написанный мини сервер через *spawn-fcgi* на порту 8080
![alt text](screenshots/3.6.png)

##### Проверяем, что в браузере по *localhost:81* отдается написанная вами страничка
![alt text](screenshots/3.7.png)

## Part 4. Свой докер

##### 1) указываем нужный нам родительский образ (в нашем случае `nginx`)
##### 2) копируем внутрь образа написанный *./nginx/nginx.conf*
##### 3) скачиваем компилятор `gcc`,  утилиту `spawn-fcgi` и библиотеку `libfcgi-dev`
##### 4) указваем порты, входим в директорию `home` и даем права доступа для нашего файла `nginx.conf`
##### 5) запускает скрипт.
![alt text](screenshots/4.1.png)

##### 1) компилируем файл
##### 2) запускаем скомпелированный файл с портом `8080`
##### 3) запускаем службу `nginx`
![alt text](screenshots/4.2.png)

##### `nginx.config`
![alt text](screenshots/4.3.png)

##### Собираем написанный докер образ через `docker build` при этом указав имя и тег. Проверяем через `docker images`, что все собралось корректно
![alt text](screenshots/4.4.png)

##### 1) Запускаем собранный докер образ с маппингом 81 порта на 80 на локальной машине и маппингом папки *./nginx* внутрь контейнера по адресу, где лежат конфигурационные файлы **nginx**'а
##### 2) Проверяем, что по localhost:80 доступна страничка написанного мини сервера
![alt text](screenshots/4.5.png)

##### Дописываем в *./nginx/nginx.conf* проксирование странички */status*, по которой надо отдавать статус сервера **nginx**
![alt text](screenshots/4.6.png)

##### 1) Перезапускаем докер образ
##### 2) Проверяем, что теперь по *localhost:80/status* отдается страничка со статусом **nginx**
![alt text](screenshots/4.7.png)

## Part 5. **Dockle**

После написания образа никогда не будет лишним проверить его на безопасность.

**== Задание ==**
##### Устанавливаем `homebrew` и затем `dockle`
![alt text](screenshots/5.1.png)

##### Сканируем образ из предыдущего задания через `dockle [image_id|repository]`
![alt text](screenshots/5.2.png)

##### Исправляем образ
![alt text](screenshots/5.4.png)

##### Проверяем через **dockle** не было ошибок и предупреждений
![alt text](screenshots/5.3.png)

## Part 6. Базовый **Docker Compose**

##### Берем за основу докер из [Части 5](#part-5-инструмент-dockle) и копируем его в папку ./prox_server редактируем его и удаляем лишнее:

##### Dockerfile:
![alt text](screenshots/6.2.png)

##### get_server.sh:
![alt text](screenshots/6.4.png)

##### Берем за основу докер из [Части 5](#part-5-инструмент-dockle) копируем его в папку ./nginx_server и редактируем что бы он проксировал все запросы с 8080 порта на 81 порт первого контейнера:
##### Dockerfile:
![alt text](screenshots/6.1.png)
##### nginx.cong:
![alt text](screenshots/6.3.png)

##### Пишем файл *docker-compose.yml*:
![alt text](screenshots/6.0.png)

##### Собираем и запускаем проект с помощью команд `docker-compose build` и `docker-compose up`. Затем проверяем, что в браузере по *localhost:80*
##### localhost:80
![alt text](screenshots/6.6.png)

##### localhost/status
![alt text](screenshots/6.7.png)
