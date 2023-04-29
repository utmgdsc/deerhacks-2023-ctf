sudo docker build -t rop .
sudo docker kill rop_chal
sudo docker rm -f rop_chal
sudo docker run --name rop_chal -dp 1341:1337 rop
