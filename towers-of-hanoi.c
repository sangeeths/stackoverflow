#include <stdio.h>
#include <stdlib.h>

void toh(int n, char from, char to, char using)
{
	// if there is only one disk, then move it from 
	// A to C and return
	if (n == 1) {
		printf("move %d from %c to %c\n", n, from, to);
		return;
	}

	// move n-1 disks from 'from' to 'using' using 'to'
	toh(n-1, from, using, to);

	printf("move %d from %c to %c\n", n, from, to);

	// move n-1 disks from 'using' to 'to' using 'from'
	toh(n-1, using, to, from);
}

int main()
{
	int n;
	printf("Enter number of plates : ");	
	scanf("%d", &n);

	printf("The moves are as follows: \n");
	toh(n, 'A', 'C', 'B');
	
	return 0;
}
