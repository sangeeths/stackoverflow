#include <stdio.h>

int main(void) 
{
    FILE* inputF = stdin;
    char inputStr[10];

    fread(inputStr, 1, 9, inputF);

    inputStr[9] = '\0';
    printf("%s \n", inputStr);

    return 0;
}

/*
$ gcc run.c 
$ ./a.out 
123456789
123456789 
$ 

*/
