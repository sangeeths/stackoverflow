#include <stdio.h>

void endian(void);

int main(void)
{
    endian();
    return 0;
}

void endian(void)
{
        int i = 1;

        if (*(char *) &i == 1)
                printf("Little endian \n");
        else
                printf("Big endian \n");

        return;
}

