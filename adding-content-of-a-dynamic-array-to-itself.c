#include <stdlib.h>
#include <stdio.h>

/* global variable to store the size */
int g_size;

void ADDER(int *a, int *b) 
{
    int i;
    for (i=0 ; i<g_size ; i++) {
        b[i] += a[i];
    }

    return;     
}

int main(void) 
{
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *a = NULL;
    if ((a = (int *)malloc(n * sizeof(int))) == NULL) {
        printf("unable to allocate memory \n");
        return -1;
    }

    for (i=0; i<n; i++) {
        printf("Enter element number %d: ", i);
        scanf("%d", &a[i]);
    }

    g_size = n;
    ADDER(a, a);

    for (i=0; i<n; i++) {
        printf("%d \n", a[i]);
    }

    free(a);
    return 0;
}
