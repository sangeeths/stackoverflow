#include <stdio.h>

/*
reference: 
http://www.catonmat.net/blog/low-level-bit-hacks-you-absolutely-must-know/
http://jeremy.baumont.org/wiki/index.php/Bitwise_Operators

The following are the bitwise operators used in this program:
&, |, ^, ~, <<, >>

A	B	&	|	^	~
----------------------
0	0	0	0	0	-1
0 	1	0	1	1
1 	0	0	1	1	-2
1 	1	1	1	0

*/

int bit_swap_required(unsigned int a, unsigned int b)
{
	int count = 0;
	int i;
	unsigned result = a ^ b;
	while (result) {
		if (result & 01 == 1)
			count++;
		result = result >> 1;
	}

	return count;
}

int main()
{
	unsigned int a, b, n;

	// Check whether given integer is odd or even
	// The LSB of odd number will always be 1
	// The LSB of even number will always be 0
	// a & 01
	a = -2;
	if (a & 01) 
		printf("%d is odd \n", a);
	else 
		printf("%d is even \n", a);

	// Check whether nth bit is set or not
	// a & (01<<n)
	a = 15; n = 3;
	if (a & 01<<n) 
		printf("%d bit is set in %d \n", n, a);
	else
		printf("%d bit is not set in %d \n", n, a);

	// Set nth bit
	// a = a | (01<<n) 
	a = 15; n = 4;
	printf("%d - %dth bit is set - %d \n", a, n, a|(1<<n));
	
	// Un-Set nth bit
	// a = a & ~(01 << n)
	a = 15; n = 2;
	printf("%d - %dth bit is unset - %d \n", a, n, a&~(01<<n));

	// toggle nth bit
	// a = a ^ (01 << n)
	a = 10; n = 2;
	printf("%d - %dth bit is toggled - %d \n", a, n, a^(01<<n));

	// Turn off the right most 1 bit
	// a = a & (a-1)
	a = 10;
	printf("%d - right most 1 bit turned off - %d \n", a, a&(a-1));

	// Isolate the right most 1 bit
	// a = a & (-a)
	a = 10;
	printf("%d - right most 1 bit isolated - %d \n", a, a&(-a));

	// Turn on the right most 0 bit
	// a = a | (a+1)
	a = 10;
	printf("%d - right most 0 bit turned on - %d \n", a, a|(a+1));
	
	// Multiply a given element by 2
	// left shift one time - a<<1
	a = 11;
	printf("%d - multipled by 2 - %d \n", a, a<<1);

	// Divide a given element by 2
	// right shift one time - a>>1
	a = 11;
	printf("%d - divided by 2 - %d \n", a, a>>1);

	// Check whether the given integer is power of 2
	// a & (a-1) == 0 ==>> a is power of 2
	a = 128;
	if ( a & a-1)
		printf("%d is not power of 2\n", a);
	else
		printf("%d is power of 2\n", a);

	a = 31;
	b = 14;
	printf("a=%d - b=%d - bit swap needed = %d \n", a, b, bit_swap_required(a, b));


	/*
	// prints the truth table for & | ^
	printf("0&0 : %d \n", 0&0);
	printf("0&1 : %d \n", 0&1);
	printf("1&0 : %d \n", 1&0);
	printf("1&1 : %d \n", 1&1);
	printf("\n");
	printf("0|0 : %d \n", 0|0);
	printf("0|1 : %d \n", 0|1);
	printf("1|0 : %d \n", 1|0);
	printf("1|1 : %d \n", 1|1);
	printf("\n");
	printf("0^0 : %d \n", 0^0);
	printf("0^1 : %d \n", 0^1);
	printf("1^0 : %d \n", 1^0);
	printf("1^1 : %d \n", 1^1);
	printf("\n");
	printf("~0 : %d \n", ~0);
	printf("~1 : %d \n", ~1);
	printf("\n");
	*/

	/*
	{

	// bitwise XOR way of swapping two
	// variables 

	int a = 10; b = 20;
	printf("a : %d \n", a);
	printf("b : %d \n", b);
	a ^= b; b^=a ; a^=b;
	printf("a : %d \n", a);
	printf("b : %d \n", b);
	}	
	*/

	return 0;
}
