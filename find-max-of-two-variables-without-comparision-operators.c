#include <stdio.h>

/*
Compute the maximum of two given numbers without
using comparision operators like >, <, if, else...

What makes 'a' greater than 'b'? 
its the difference between 'a' and 'b'

if the difference is positive then 'a' is greater else
'a' is smaller than 'b'

1. if the difference is +ive, we do nothing and return 'a' (max is a)
2. if the difference is -ive, we subtract the -ive difference with 'a'
   (which is nothing but adding the difference to 'a')

*/


int max(int a, int b)
{
	// get the difference
	int diff = a - b;

	// check for -ive difference
	// if the difference is -ive then the MSB will be 1
	// because the negative numbers are stored in 2's
	// complement
	int msb = diff >> 31 & 1;
	
	return a - (diff * msb);
}

int main()
{
	int a = 10;
	int b = -20;
	
	printf("max of %d and %d is %d \n", 
			a, b, max(a, b));

	return 0;
}
