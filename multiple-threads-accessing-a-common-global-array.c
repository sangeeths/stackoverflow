#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NOTHREADS 5

/*
The following are the critical sections.
(1) array
(2) array index
*/

int arr[10 * NOTHREADS];
int aindex;

pthread_mutex_t mutex; 

void *hello(void *thread_id)
{
        int i;
        int *id = (int *) thread_id;

        for (i=1; i<=10 ; i++) {
                pthread_mutex_lock(&mutex);
                arr[aindex] = (*id)*100+ i;
                sleep(1);
                aindex = aindex + 1;
                pthread_mutex_unlock(&mutex);
        }

        pthread_exit(NULL);
}

int main()
{
        pthread_t tids[NOTHREADS];
        int ids[NOTHREADS] = {1, 2, 3, 4, 5};
        int ret; 
        long t;
        int i;

        pthread_mutex_init(&mutex, NULL);       

        for (i=0 ; i<NOTHREADS; i++) {
                printf("%d %s - Creating thread #%d \n", __LINE__, __FUNCTION__, i);
                ret = pthread_create(&tids[i], NULL, hello, &ids[i]);
                if (ret) {
                        printf("unable to create thread! \n");
                        exit(-1);
                } 
        }

        for (i=0 ; i<NOTHREADS; i++) {
                pthread_join(tids[i], NULL);
        }

        printf("Final array : \n");
        for (i=0; i<50; i++)
                printf("%d ", arr[i]);
        printf("\n\n");

        pthread_mutex_destroy(&mutex);
        pthread_exit(NULL);     

        return 0;
}

