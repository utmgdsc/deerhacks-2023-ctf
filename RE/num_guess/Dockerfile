FROM ubuntu
WORKDIR /app
COPY /src .

RUN chmod +x number_guesser
RUN apt-get update -y && apt-get install -y socat

CMD ["./number_guesser"]

EXPOSE 1337

