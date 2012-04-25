#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
	int data;
	struct stack * next;
} node;

node * push(node * stack, int data)
{
	node * newnode = (node *) malloc(sizeof(node));
	newnode->data = data;
	newnode->next = stack;
	stack = newnode;

	printf("%s - added %d \n", __FUNCTION__, data);

	return stack;
}

node * pop(node * stack, int * data)
{
	node * temp;

	if (!stack) {
		*data = -1;
		return NULL;
	}

	temp = stack;
	*data = stack->data;
	stack = stack->next;

	printf("%s - deleting %d \n", __FUNCTION__, *data);			
	free(temp);

	return stack;
}

void display(node * stack)
{
	while (stack) {
		printf("%d ", stack->data);
		stack = stack->next;
	}
	printf("\n");
}

int main()
{
	node * stack = NULL;
	int * p = (int *) malloc (sizeof(int));

	stack = push(stack, 10);	display(stack);
	stack = push(stack, 12);	display(stack);
	stack = push(stack, 13);	display(stack);
	stack = push(stack, 14);	display(stack);
	stack = push(stack, 10);	display(stack);
	stack = push(stack, 12);	display(stack);
	
	stack = pop(stack, p); 		display(stack);
	stack = pop(stack, p); 		display(stack);
	stack = pop(stack, p); 		display(stack);

	stack = push(stack, 15);	display(stack);
	stack = push(stack, 16);	display(stack);
	stack = push(stack, 30);	display(stack);
	stack = push(stack, 42);	display(stack);

	return 0;
}


