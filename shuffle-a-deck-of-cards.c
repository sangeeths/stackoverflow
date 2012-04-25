#include <stdio.h>
#include <stdlib.h>

#define DECKSIZE 52 

/*
begin = begining for the (unshuffled) deck
end = end of the (unshuggled) deck
random = the random number generated using system lib

from begin to end
	Find an index between begin and end and swap a[index] with a[begin]

challenge:
How to find a random number between a given begin and end?
	
	rand() % (end - begin + 1) + begin
*/

void print_deck(int a[])
{
	int i;
	for (i=0; i<DECKSIZE; i++)
		printf("%d, ", a[i]);
	printf("\n");
	return;
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void shuffle_deck(int a[])
{
	int index, i;
	int high, low, random;

	for(i=0; i<DECKSIZE; i++) {

		high = DECKSIZE-1;
		low = i;
		random = rand();

		index = rand() % (high - low + 1) + low;

		/*
		printf("low=%d high=%d random=%d index=%d\n",
				low, high, random, index);
		*/

		swap(a+i, a+index);
	
		/*
		print_deck(a);
		printf("\n");
		*/
	}

	return;
}

int main()
{
	int cards[DECKSIZE] = {0};
	int i = 0;

	for (i=0; i<DECKSIZE; i++) 
		cards[i] = i+1;
	
	printf("before shuffle: \n");
	print_deck(cards);

	shuffle_deck(cards);	

	printf("after shuffle: \n");
	print_deck(cards);

	return 0;
}

