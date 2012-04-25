#include <stdio.h>

int main()
{
	int a=-1;
	int bits=0;

	while (a) {
		a = a&a-1;
		bits++;
	}
	
	printf("%d \n", bits);
	return 0;

}
