#include <stdio.h>

int strcmp1(char a[], char b[])
{
        int i=0;
        while (a[i] == b[i]) {
                if (a[i] == '\0')
                        return 0;
                i++;
        }

        return a[i]-b[i];
}

int strcmp2(char *a, char *b)
{
        while (*a == *b) {
                if (*a == '\0')
                        return 0;
                a++; b++;
        }
        return *a-*b;
}

int main()
{
        char s1[] = "test string";
        char s2[] = "test string";
        char s3[] = "aaa";
        char s4[] = "bbb";

        printf("strcmp1(%s, %s) = %d \n", s1, s2, strcmp1(s1, s2));
        printf("strcmp2(%s, %s) = %d \n", s3, s4, strcmp2(s3, s4));

        return 0;
}
