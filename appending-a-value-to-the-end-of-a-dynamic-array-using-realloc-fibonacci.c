#include <stdio.h>
#include <stdlib.h>

/* adding a comment */

int * dynamic_array_append(int * array, int size);

int main() {

    int i, n, size=0, *array = NULL;

    printf("Dynamic array, Fibonacci series. \n");
    printf("Capture upto element: ");
    scanf("%d", &n);

    for (i=0 ; i<n ; i++)
        array = dynamic_array_append(array, i);

    for (i=0 ; i<n ; i++) 
        printf("array[%d] = %d\n", i, array[i]);

    return 0;
}

int * dynamic_array_append(int * array, int size) 
{
    int i;
    int n1, n2;
    int new_size = size + 1;
    int * new_addr = (int *) realloc(array, new_size * (int)sizeof(int));

    if (new_addr == NULL) {
        printf("ERROR: unable to realloc memory \n");
        return NULL;
    }

    if (size == 0 || size == 1) {
        new_addr[size] = size;
        return new_addr;
    }

    n1 = new_addr[size-1];
    n2 = new_addr[size];
    new_addr[new_size-1] = new_addr[new_size-2] + new_addr[new_size-3];

    return new_addr;
}

/*
Output:

Dynamic array, Fibonacci series. 
Capture upto element: 10
array[0] = 0
array[1] = 1
array[2] = 1
array[3] = 2
array[4] = 3
array[5] = 5
array[6] = 8
array[7] = 13
array[8] = 21
array[9] = 34

*/
