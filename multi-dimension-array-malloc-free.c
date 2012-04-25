#include <stdio.h>
#include <stdlib.h>

/* 

d1, d2 and d3 are dimension 1, 2 and 3 

d3 is the upper/outer dimension and 
d1 is the lowest/inner dimenstion

 +----+         +----+----+ ..... +----+----+
 |    |-------->|    |    |  d2   |    |    |  
 +----+         +----+----+ ..... +----+----+
 |    |                |   
 +----+                | 
 |    |                |          +----+
 +----+                +----------|    |
 .    .                           +----+
 .    .                           |    |
 . d3 .                           +----+ 
 .    .                           .    .
 .    .                           . d1 .
 +----+                           .    .
 |    |                           +----+
 +----+                           |    |
 |    |                           +----+
 +----+


*/

#define d1 10   
#define d2 20
#define d3 30

#define SUCCESS 0
#define FAILURE 1

int main(void)
{
    int i, j, k;
    int ***array = NULL;   /* 3d array */
    int value = 0;

    /* array allocation */

    if ((array = (int ***) malloc(sizeof(int**) * d3)) == NULL) {
        printf("unable to allocate memory \n");
        return FAILURE;
    }
        
    for (i=0 ; i<d3; i++) {
        if ((array[i] = (int **) malloc(sizeof(int *) * d2)) == NULL) {
            printf("unable to allocate memory \n");
            return FAILURE;
        }
        
        for(j=0 ; j<d2; j++) {
            if ((array[i][j] = (int *) malloc(sizeof(int) * d1)) == NULL) {
                printf("unable to allocate memory \n");
                return FAILURE;
            }
            for (k=0; k<d1; k++) 
                array[i][j][k] = value++;
        }
    }
    
    /* print the value stored in the array */
    for (i=0 ; i<d3; i++) {
        for(j=0 ; j<d2; j++) {
            for (k=0; k<d1; k++) 
                printf("%4d ", array[i][j][k]);
            printf("\n");
        }
        printf("\n");
    }

    /* array de-allocation */
    for (i=0 ; i<d3; i++) {
        for(j=0 ; j<d2; j++)
            free(array[i][j]);
        free(array[i]);
    }

    free(array);

    return SUCCESS;
}


/*
$ valgrind --tool=memcheck --leak-check=yes ./a.out 
*/
