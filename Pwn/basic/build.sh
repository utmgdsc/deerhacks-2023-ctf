sudo docker build -t basic .
sudo docker kill basic_chal
sudo docker rm -f basic_chal
sudo docker run --name basic_chal -dp 1340:1337 basic
