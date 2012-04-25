#include <stdio.h>
#include <assert.h>

#define STACK_SIZE 25

void display(int stack[], int sp)
{
	int i;
	
	for (i=sp-1; i>=0; i--)
		printf("%d ", stack[i]);
	printf("\n");

	return;
}

void push(int stack[], int * sp, int data)
{
	if (*sp >= STACK_SIZE) {
		printf("stack full - can't push %d \n", data);
		return;
	}
	
	assert(*sp >= 0);

	stack[*sp] = data;
	*sp += 1;
	return;
}

int pop(int stack[], int *sp)
{
	if (*sp == 0) {
		printf("empty stack - nothing to pop\n");
		return -1;
	}

	assert(*sp <= STACK_SIZE);

	*sp -= 1;
	return stack[*sp];
}

int main()
{
	int stack[STACK_SIZE];
	int sp = 0;

	display(stack, sp);

	pop(stack, &sp);		display(stack, sp);
	pop(stack, &sp);		display(stack, sp);
	pop(stack, &sp);		display(stack, sp);


	push(stack, &sp, 1);	display(stack, sp);
	push(stack, &sp, 2);	display(stack, sp);
	push(stack, &sp, 3);	display(stack, sp);
	push(stack, &sp, 4);	display(stack, sp);
	push(stack, &sp, 5);	display(stack, sp);
	push(stack, &sp, 6);	display(stack, sp);
	push(stack, &sp, 7);	display(stack, sp);

	pop(stack, &sp);		display(stack, sp);
	pop(stack, &sp);		display(stack, sp);
	pop(stack, &sp);		display(stack, sp);

	push(stack, &sp, 16);	display(stack, sp);
	push(stack, &sp, 17);	display(stack, sp);

	int i;
	for(i=0; i<25; i++) {
		push(stack, &sp, i);	display(stack, sp);
	}

	for(i=0; i<30; i++) {
		pop(stack, &sp);	display(stack, sp);
	}
	
	return 0;
}

