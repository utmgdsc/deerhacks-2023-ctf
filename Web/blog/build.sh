sudo docker build -t php_blog .
sudo docker kill php_blog_chal
sudo docker rm -f php_blog_chal
sudo docker run --name php_blog_chal -dp 8000:80 php_blog
