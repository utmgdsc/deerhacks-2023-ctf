FROM ubuntu
WORKDIR /app

COPY src/flag.txt .
COPY src/return2me .

RUN chmod +x return2me
RUN apt-get update -y && apt-get install -y socat

CMD ["socat", "tcp-listen:1337,reuseaddr,fork", "exec:./return2me,pty"]

EXPOSE 1337
