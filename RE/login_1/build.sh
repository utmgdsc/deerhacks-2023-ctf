sudo docker build -t login_1 .
sudo docker kill login_1_chal
sudo docker rm -f login_1_chal
sudo docker run --name login_1_chal -dp 1337:1337 login_1
