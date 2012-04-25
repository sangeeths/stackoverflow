#include <stdio.h>

int main(void)
{

    char a[10];
    int i[10];
    char *b[10];
    int *c[10];
    int (*d)[10];
    char (*e)[10];

    printf("sizeof(char)        = %d bytes\n", (int) sizeof(char));
    printf("sizeof(int)         = %d bytes\n", (int) sizeof(int));
    printf("sizeof(float)       = %d bytes\n", (int) sizeof(float));
    printf("sizeof(double)      = %d bytes\n", (int) sizeof(double));
    printf("sizeof(char *)      = %d bytes\n", (int) sizeof(char *));
    printf("sizeof(int *)       = %d bytes\n", (int) sizeof(int *));
    printf("sizeof(float *)     = %d bytes\n", (int) sizeof(float *));
    printf("sizeof(double *)    = %d bytes\n", (int) sizeof(double *));
    printf("sizeof(char **)     = %d bytes\n", (int) sizeof(char **));
    printf("sizeof(int **)      = %d bytes\n", (int) sizeof(int **));
    printf("sizeof(int ***)     = %d bytes\n", (int) sizeof(int ***));
    printf("sizeof(float **)    = %d bytes\n", (int) sizeof(float **));
    printf("sizeof(double **)   = %d bytes\n", (int) sizeof(double **));
    printf("sizeof(a)           = %d bytes\n", (int) sizeof(a));
    printf("sizeof(i)           = %d bytes\n", (int) sizeof(i));
    printf("sizeof(b)           = %d bytes\n", (int) sizeof(b));
    printf("sizeof(*b)          = %d bytes\n", (int) sizeof(*b));
    printf("sizeof(&b)          = %d bytes\n", (int) sizeof(&b));
    printf("sizeof(c)           = %d bytes\n", (int) sizeof(c));
    printf("sizeof(*c)          = %d bytes\n", (int) sizeof(*c));
    printf("sizeof(&c)          = %d bytes\n", (int) sizeof(&c));
    printf("sizeof(d)           = %d bytes\n", (int) sizeof(d));
    printf("sizeof(e)           = %d bytes\n", (int) sizeof(e));

    return 0;
}

