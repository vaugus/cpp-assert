FROM alpine

WORKDIR /work

RUN apk --update add gcc make g++ zlib-dev bash
