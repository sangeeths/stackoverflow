#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* N is the number of threads */
/* also N is the number of arrays */
/* row */
#define N 10 

/* M is the length of each array */
/* column */
#define M 10

/* the 2d array which contains N rows and M columns */
int **matrix;

void display(void)
{
    int i, j;
    for (i=0 ; i<N ; i++) {
        for (j=0 ; j<M ; j++) {
            printf("%3d  ", matrix[i][j]);
        }
        printf("\n");
    }
    return;
}

void * thread_handler(void *thread_id)
{
    int *id = (int *) thread_id;
    int i = *id, j; 
    int min = matrix[i][0];
    int max = matrix[i][0];

    for (j=1 ; j<M ; j++) {
        if (matrix[i][j] > max)
            max = matrix[i][j];
        if (matrix[i][j] < min)
            min = matrix[i][j];
    }

    printf("array[%d] min[%d] max[%d]\n", i, min, max);
    pthread_exit(NULL);
}

int main(void)
{
    int i, j, ret;
    pthread_t tids[N];
    int ids[N] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    srand(time(NULL));

    matrix = (int **) malloc (sizeof(int *) * N);
    for (i=0 ; i<N ; i++) 
        matrix[i] = (int *) malloc (sizeof(int) * M);

    for (i=0 ; i<N ; i++) {
        for (j=0 ; j<M ; j++) {
            matrix[i][j] = rand() % 500;
        }
    }

    display();

    for (i=0 ; i<N ; i++) {
        printf("Creating thread #%d \n", ids[i]);
        ret = pthread_create(&tids[i], NULL, thread_handler, &ids[i]);
        if (ret) {
            printf("unable to create thread! \n");
            exit(-1);
        } 
    }

    for (i=0 ; i<N ; i++) {
        pthread_join(tids[i], NULL);
    }

    pthread_exit(NULL);     

    for (i=0 ; i<N ; i++) 
        free(matrix[i]);
    free(matrix);

    return 0;
}

