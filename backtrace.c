#include <stdio.h>
#include <execinfo.h>
#include <stdlib.h>

print_trace()
{
	void *array[100];
	size_t s;
	int i;
	char **string;

	s = backtrace(array, 100);
	string = backtrace_symbols(array, s);

	printf("Obtained %zd stack frames \n", s);
	
	for (i=0 ; i<s ; i++) {
		printf("%s \n", string[i]);
	} 

	free(string);

}

void func2()
{
	print_trace();
}

void func1()
{
	func2();
}

int main()
{
	func1();
	return 0;
}
