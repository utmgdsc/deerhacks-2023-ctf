FROM ubuntu
WORKDIR /app
COPY /src .

RUN chmod +x basic
RUN apt-get update -y && apt-get install -y socat

CMD ["socat", "tcp-listen:1337,reuseaddr,fork", "exec:./basic,pty"]

EXPOSE 1337
