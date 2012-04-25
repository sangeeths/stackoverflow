#include <stdio.h>

// array version
int strlen1(char a[])
{
        int len = 0;
        while (a[len])
                len++;
        return len;
}

// pointer version
// *p++ = dereference the pointer value and then
// increment the pointer to the next memory location
int strlen2(char *p)
{
        int len = 0;
        while (*p++)
                len++;
        return len;

        /*              
        int *q = p;
        while (*p);
                p++;
        return p-q;
        */
}

int main()
{
        char s[] = "test string";
        char *p = "another string";

        printf("strlen1(%s) = %d \n", s, strlen1(s));
        printf("strlen1(%s) = %d \n", p, strlen1(p));

        printf("strlen2(%s) = %d \n", s, strlen2(s));
        printf("strlen2(%s) = %d \n", p, strlen2(p));

        return 0;
}
