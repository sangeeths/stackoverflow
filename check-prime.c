#include <stdio.h>

/*

Formula to check whether the given number is prime or not is:

( 2 power n-1 ) % n == 1 ---> prime 
else, not prime



*/



//	the below function will work only if x is 2
unsigned long int power1(unsigned long int x, int y)
{
	if (y == 0) return 1;
	return x<<(y-1);
}

// O(n) solution
unsigned long int power2(unsigned long int x, int y)
{
	int i;
	unsigned long int result = 1;

	if (y == 0) return 1;
	if (y == 1) return x;

	for (i=0 ;i<y; i++)
		result *= x;

	return result;
}

// O(log n) solution
unsigned long int power3(unsigned int x, int y)
{
	unsigned long int result=1; 
	int i;
	
	if (y == 0) return 1;
	if (y == 1) return x;

	for (i=0 ;i<y/2; i++)
		result *= x;

	if (y%2 == 0)
		return result * result;
	else 
		return result * result * x;
}

int is_prime(unsigned int n)
{
	if (n == 2) return 1;
	else return (power1(2, n-1) %n == 1);
}	

int main()
{
	unsigned int n = 0;
	int i;

	/*
	printf("Enter Number: ");
	scanf("%d", &n);
	*/
	
	for (i=1; i<=100; i++) 
		printf("%10d 	%10uld	%10uld 	%10uld	%10d \n", i, power1(2, i), power2(2, i), power3(2, i), is_prime(i));
		//printf("%d is %sa prime number\n", i, is_prime(i)?"":"not ");

	return 0;
}
