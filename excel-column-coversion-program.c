#include <stdio.h>

/*
In an excel sheet, the columns are named as A, B, C.. Y, Z, AA, AB,.. AZ, BA... 

So 
1) given an number say 100, convert that to the excel column representation
2) given an excel column representation, say ABC, convert that to number

This is similar to atoi and itoa, where we convert strings to base 10 number.
Here we convert strings to base 26 number

itoa (int i=123 to a[]="123") ==> (int i=123 to a[]="ABC")
atoi (char a[]="123" to int i=123) ==> (char a[]="AABBCC" to int i=12345)


ABC to 123 
As long as string is not empty
	result = 26 * result + (str[i] - 'A' + 1) 

123 to ABC
As long as number is not zero 
	str[i] = (number % 26) + 'A';
	number = number / 26;

*/


int symbols_to_numbers(char *s)
{
	int num = 0;
	int i = 0;
	long base;

	for(i=0; s[i] >= 'A' && s[i] <= 'Z' ; i++)
		num = 26 * num + (s[i] - 'A' + 1);

	return num;	
}

int strlen(char *s)
{
	char *p = s;
	while (*p)
		p++;
	return p - s;
}

char * strrev(char *s)
{
	char *begin = s;
	char *end = s + strlen(s) - 1;
	int temp;
	
	while (begin < end) {
		temp = *begin;
		*begin = *end;
		*end = temp;
		begin++; end--;
	}

	return s;		
}

void numbers_to_symbols(int num, char *str)
{
	int i = 0;
	do {
		str[i++] = (num % 26) + 'A' - 1;

	} while ((num = num/26) > 0);
	str[i] = '\0';
	strrev(str);
	return;
}

int main()
{
	int i = 703; char res[10];
	char a[] = "AAA";
		
	printf("%s = %d \n", a, symbols_to_numbers(a));

	numbers_to_symbols(i, res);
	printf("%d = %s \n", i, res);

	return 0;
}

