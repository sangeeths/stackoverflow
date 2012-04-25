#include <stdio.h>
#include <stdlib.h>

typedef struct _n  
{
	int data;
	struct _n * next;
	struct _n * prev;
}node;

typedef struct _q 
{
	node * front;
	node * rear;
}queue;

void display(queue * q)
{
	node * cur = q->rear;
	node * front = q->front;

	while (cur) {
		printf("%d ", cur->data);
		cur = cur->next; 
	}
	printf("\n");
	return;
}

queue * enqueue(queue *q, int data)
{
	node * newnode = (node *) malloc(sizeof(node));
	newnode->data = data;
	newnode->prev = newnode->next = NULL;

	if (q->front == NULL && q->rear == NULL) {
		q->front = q->rear = newnode;
		printf("%s - empty queue - %d \n", 
				__FUNCTION__, data);
	} else {
		q->rear->prev = newnode;
		newnode->next = q->rear;
		q->rear = newnode;
		printf("%s - %d \n", __FUNCTION__, data);
	}

	return q;
}

queue * dequeue(queue * q, int * data)
{
	node * temp = NULL;
	
	if (q->front == NULL && q->rear == NULL) {
		printf("%s - empty queue\n", __FUNCTION__);
		*data = -1;
	} else {
		temp = q->front;
		*data = temp->data;

		if (q->front == q->rear) {
			printf("one element queue \n");
			q->front = q->rear = NULL;
		} else {
			q->front = q->front->prev;
			q->front->next = NULL;
		}

		printf("%s - %d \n", 
				__FUNCTION__, *data);
		free(temp);
	} 

	return q;
}



int main()
{
	queue *q1 = (queue *) malloc(sizeof(queue));
	q1->front = q1->rear = NULL;

	int * data = (int *) malloc(sizeof(int)); 

	q1 = enqueue(q1, 10); 	display(q1);
	q1 = enqueue(q1, 20);	display(q1);
	q1 = enqueue(q1, 30);	display(q1);
	q1 = enqueue(q1, 40);	display(q1);
	q1 = enqueue(q1, 50);   display(q1);
	q1 = enqueue(q1, 60);	display(q1);
	q1 = enqueue(q1, 70);	display(q1);
	q1 = enqueue(q1, 80);	display(q1);
	q1 = enqueue(q1, 90);	display(q1);
	q1 = enqueue(q1, 100);	display(q1);

	q1 = dequeue(q1, data);	display(q1);
	q1 = dequeue(q1, data);	display(q1);
	q1 = dequeue(q1, data);	display(q1);
	q1 = dequeue(q1, data);	display(q1);
	q1 = dequeue(q1, data);	display(q1);
	q1 = dequeue(q1, data);	display(q1);
	q1 = dequeue(q1, data);	display(q1);
	q1 = dequeue(q1, data);	display(q1);
	q1 = dequeue(q1, data);	display(q1);
	q1 = dequeue(q1, data);	display(q1);
	q1 = dequeue(q1, data);	display(q1);
	q1 = dequeue(q1, data);	display(q1);

	q1 = enqueue(q1, 10); 	display(q1);
	q1 = enqueue(q1, 20);	display(q1);
	q1 = enqueue(q1, 30);	display(q1);
	q1 = enqueue(q1, 40);	display(q1);
	q1 = enqueue(q1, 50);   display(q1);
	q1 = enqueue(q1, 60);	display(q1);
	q1 = enqueue(q1, 70);	display(q1);
	q1 = enqueue(q1, 80);	display(q1);
	q1 = enqueue(q1, 90);	display(q1);

	q1 = dequeue(q1, data);	display(q1);
	q1 = dequeue(q1, data);	display(q1);
	q1 = dequeue(q1, data);	display(q1);
	q1 = dequeue(q1, data);	display(q1);
	q1 = dequeue(q1, data);	display(q1);
	q1 = dequeue(q1, data);	display(q1);

	q1 = enqueue(q1, 100);	display(q1);
	q1 = enqueue(q1, 10); 	display(q1);
	q1 = enqueue(q1, 20);	display(q1);
	q1 = enqueue(q1, 30);	display(q1);
	q1 = enqueue(q1, 40);	display(q1);
	q1 = enqueue(q1, 50);   display(q1);
	q1 = enqueue(q1, 60);	display(q1);
	q1 = enqueue(q1, 70);	display(q1);
	q1 = enqueue(q1, 80);	display(q1);
	q1 = enqueue(q1, 90);	display(q1);
	q1 = enqueue(q1, 100);	display(q1);


	return 0;
}

