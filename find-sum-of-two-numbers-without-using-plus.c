#include <stdio.h>

int sum(int a, int b)
{
	static int index = 1;
	if (b==0) return a;
	int addition = a ^ b;
	int carry =	(a&b) << 1;
	printf("%d addition=%d carry=%d\n", index++, addition, carry);
	return sum(addition, carry);
}

int main()
{
	int a = 123; 
	int b = 456;

	printf("a=%d b=%d result=%d \n", a, b, sum(a, b));
	
	return 0;
}

