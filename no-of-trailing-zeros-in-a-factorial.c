#include <stdio.h>

/*
0! = 1
1! = 1
2! = 2
3! = 6
4! = 24
5! = 120
6! = 720
7! = ..

number of trailing zeros is the "number of multiples 
of 5 present in that number"..

for example: 

26 / 5 = 5
26 / 25 = 1
so there are 6 trailing zeros 

*/


int no_of_trailing_zeros(int n)
{
	int count = 0;
	int i;

	if (n < 0) {
		printf("cannot compute factorial\n");
		return count;
	}
	
	for(i=5; n/i > 0 ; i = i*5)
		count = count + n/i;

	return count;
}

int main()
{
	int n = 200;

	printf("Number of trailing zeros in %d is %d\n", 
			n, no_of_trailing_zeros(n));

	return 0;
}

