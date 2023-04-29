#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int change_me = 0;
    char buf[40];

    gets(buf);

    if (change_me != 0)
    {
        printf("yay! here's ur flag :3\n");
        system("cat flag.txt");
        return 0;
    }

    return 1;
}