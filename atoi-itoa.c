#include <stdio.h>

void string_reverse(char s[]);

int atoi(char a[])
{
	int i, n=0;

	for (i=0 ; a[i] >= '0' && a[i] <= '9' ; i++)
		n = 10 *n + (a[i]-'0');

	return n;
}

void itoa(int n, char s[])
{
	int i = 0, sign;

	if ((sign = n) < 0)
		n = -n;
	
	do {
		s[i++] = n % 10 + '0';
	} while ((n/=10) > 0);

	if (sign < 0) 
		s[i++] = '-';
	s[i] = '\0';

	string_reverse(s);
}

int lower(int c)
{
	if ( c >= 'A' && c <= 'Z')
		return c+'a'-'A';
	else
		return c;
}	

int upper(int c)
{
	if ( c >= 'a' && c <= 'z') 
		return c + 'A' - 'a';

	return c;
}

int string_length(char *s)
{	
	int len = 0;

	while(s[len] != '\0')
		len++;

	return len;
}

void string_reverse(char s[])
{
	int c, i, j=string_length(s)-1;

	for(i=0 ; i<j ; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}

}

int main()
{
	char from[] = "hello";
	char to[20];
	char a[10] = {'1','2','3','4'};
	char s[20] = "hai";
	char t[6] = "world";


	string_copy(to, from);
	printf("to: %s - from: %s \n", to, from);

	printf("length = to: %d - from: %d \n", 
			string_length(to), string_length(from));

	printf("a[] = %s -- atoi = %d \n", a, atoi(a));

	printf("lower: %c \n", lower('C'));
	printf("upper: %c \n", upper('x'));
		
	char name[20] = "sangeeth";	
	squeez(name, 'e');
	printf("squeez(sangeeth) : %s \n", name);
	
	printf("strcat(%s, %s): ", s, t); string_concat(s, t);
	printf("%s \n", s);

	printf("strrev(%s): ", from); string_reverse(from);
	printf("%s \n", from);
	
	int num = -1234;
	char numc[10];
	itoa(num, numc);
	printf("itoa(%d): %s \n", num, numc);	

	return 0;
}
