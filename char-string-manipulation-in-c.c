#include <stdio.h>

#define MAX 80

int main(void)
{
    char stg_array[MAX];
    int i = 0, j;
    int len;

    printf("Enter String : ");
    while((i < MAX-1) && ((stg_array[i] = getchar()) != '\n')) {
        i++;
    }
    stg_array[i] = '\0';

    for (j=i ; j>=0 ; j--) {
        printf("stg_array[%d] = %c / %x \n", j, stg_array[j], stg_array[j]);
    }

    return 0;
}

