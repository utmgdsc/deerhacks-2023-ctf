FROM ubuntu
WORKDIR /app
COPY /src .

RUN chmod +x login_1
RUN apt-get update -y && apt-get install -y socat

CMD ["socat", "tcp-listen:1337,reuseaddr,fork", "exec:./login_1,pty"]

EXPOSE 1337

