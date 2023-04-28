sudo docker build -t num_guess .
sudo docker kill num_guess_chal
sudo docker rm -f num_guess_chal
sudo docker run --name num_guess_chal -dp 1337:1337 num_guess
