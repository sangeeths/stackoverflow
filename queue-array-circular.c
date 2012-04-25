#include <stdio.h>
#include <stdlib.h>

#define QSIZE 10

typedef struct _q {
	int data[QSIZE];
	int front; 
	int rear;
} queue;

void display(queue * q)
{
	int i;

	// empty queue
	if (q->rear == -1 && q->front == -1) {
		printf("empty queue \n");
		return;
	}

	// one element queue
	if (q->rear == q->front) {
		printf("%3d \n", q->data[q->front]);
	}

	// non-circular queue
	if (q->rear > q->front) {
		for (i=q->rear; i >= q->front; i--)
			printf("%3d ", q->data[i]);
		printf("\n");
	}

	// circular queue 
	// print from 
	// 		rear to start-of-the-queue
	// 		end-of-the-queue to front
	if (q->rear < q->front) {
		for (i=q->rear ; i>= 0 ; i--)
			printf("%3d ", q->data[i]);
		for (i=QSIZE-1 ; i>= q->front ; i--)
			printf("%3d ", q->data[i]);
		printf("\n");
	}
	
	return;
}

/*
1. queue full
	(rear + 1) % qsize == front

2. queue not full 

*/

queue * enqueue(queue * q, int data)
{

	// First element to be added in an empty queue
	if (q->rear == -1 && q->front == -1) {
		q->rear++;	q->front++;
		q->data[q->rear] = data;
		printf("%s - %d\n", __FUNCTION__, data);
		return q;	
	}

	// If queue full, then return 
	if((q->rear + 1)% QSIZE == q->front) {
		printf("%s - queue full \n", __FUNCTION__);
		return q;
	}

	q->rear += 1;
	q->rear %= QSIZE;
	q->data[q->rear] = data;
	printf("%s - %d\n", __FUNCTION__, data);

	return q;
}

queue * dequeue(queue * q, int * data)
{
	// Empty queue
	if (q->front == -1 && q->rear == -1) {
		printf("%s - Empty queue\n", __FUNCTION__);
		*data = -1;
		return q;
	}
	
	// One element queue 
	// extract the value and initialize front and rear to -1
	if (q->front == q->rear) {
		*data = q->data[q->rear];
		q->rear = q->front = -1;
		printf("%s - one element queue - %d\n", __FUNCTION__, *data);
		return q;
	}

	*data = q->data[q->front];
	q->front += 1;
	q->front %= QSIZE;
	printf("%s - %d\n", __FUNCTION__, *data);

	return q;
}


int main()
{
	queue * q1 = (queue *) malloc(sizeof(queue));
	q1->front = q1->rear = -1;
	int * data = (int *) malloc(sizeof(int));

	display(q1);
	q1 = enqueue(q1, 10);	display(q1);
	q1 = enqueue(q1, 20);	display(q1);
	q1 = enqueue(q1, 30);	display(q1);
	q1 = enqueue(q1, 40);	display(q1);
	q1 = enqueue(q1, 50);	display(q1);
	q1 = enqueue(q1, 60);	display(q1);
	q1 = enqueue(q1, 70);	display(q1);

	q1 = dequeue(q1, data); display(q1);
	q1 = dequeue(q1, data); display(q1);
	q1 = dequeue(q1, data); display(q1);
	q1 = dequeue(q1, data); display(q1);

	q1 = enqueue(q1, 80);	display(q1);
	q1 = enqueue(q1, 90);	display(q1);
	q1 = enqueue(q1, 100);	display(q1);
	q1 = enqueue(q1, 110);	display(q1);
	q1 = enqueue(q1, 120);	display(q1);
	q1 = enqueue(q1, 130);	display(q1);
	q1 = enqueue(q1, 140);	display(q1);
	q1 = enqueue(q1, 140);	display(q1);

	q1 = dequeue(q1, data); display(q1);
	q1 = dequeue(q1, data); display(q1);
	q1 = dequeue(q1, data); display(q1);
	q1 = dequeue(q1, data); display(q1);
	q1 = dequeue(q1, data); display(q1);
	q1 = dequeue(q1, data); display(q1);
	q1 = dequeue(q1, data); display(q1);
	q1 = dequeue(q1, data); display(q1);
	q1 = dequeue(q1, data); display(q1);
	q1 = dequeue(q1, data); display(q1);
	q1 = dequeue(q1, data); display(q1);
	q1 = dequeue(q1, data); display(q1);
	q1 = dequeue(q1, data); display(q1);


	q1 = enqueue(q1, 150);	display(q1);
	q1 = enqueue(q1, 160);	display(q1);
	q1 = enqueue(q1, 170);	display(q1);
	q1 = enqueue(q1, 180);	display(q1);
	q1 = enqueue(q1, 190);	display(q1);

	free(data);
	free(q1);

	return 0;
}


