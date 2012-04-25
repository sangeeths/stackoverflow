#include <stdio.h>


void access_digits(int n);

int main(void)
{
    int n = 123456;
    access_digits(n);
    return 0;
}

void access_digits(int n)
{
        int digit;
        int index = 0;
        if (n < 0) n = -n;
        do {
                digit = n % 10;
                /* Here you can do whatever you
                   want to do with the digit */
                printf("n[%d] = %d \n", index++, digit);
        } while ((n/=10) > 0);
}

