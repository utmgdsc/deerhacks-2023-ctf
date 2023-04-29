#include <stdio.h>
#include <stdlib.h>

void start(void);

int main(void) {
    start();
}

void start(void) {
    char buf[40];
    printf("hello! what's your name?\n> ");
    gets(buf);
    printf("hello %s, nice to meet you!\n", buf);
}

void profit(void) {
    system("/bin/sh");
}