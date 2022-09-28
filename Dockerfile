FROM alpine:latest

RUN mkdir /app
WORKDIR /app

COPY . .
RUN apk update && apk add make g++ bash

VOLUME /code

ENTRYPOINT [ "bash" ]