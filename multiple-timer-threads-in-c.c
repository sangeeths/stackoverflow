#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NOTHREADS 2

void * fun1(void *thread_id)
{
    int i;
    int *id = (int *) thread_id;

    while(1) {
        usleep(1000 * 1000 * 60);
        printf("1 minute \n");
    }

    pthread_exit(NULL);
}

void * fun2(void *thread_id)
{
    int i;
    int *id = (int *) thread_id;

    while(1) {
        usleep(2000 * 1000 * 60);
        printf("2 minute \n");
    }

    pthread_exit(NULL);
}

int main()
{
    pthread_t tids[NOTHREADS];
    int ids[NOTHREADS] = {1, 2};
    int ret; 
    long t;
    int i;

    printf("Creating fun1 thread \n");
    ret = pthread_create(&tids[0], NULL, fun1, &ids[0]);
    if (ret) {
        printf("unable to create thread! \n");
        exit(-1);
    } 

    printf("Creating fun2 thread \n");
    ret = pthread_create(&tids[1], NULL, fun2, &ids[1]);
    if (ret) {
        printf("unable to create thread! \n");
        exit(-1);
    } 

    for (i=0 ; i<NOTHREADS; i++) {
        pthread_join(tids[i], NULL);
    }

    pthread_exit(NULL);     

    return 0;
}
