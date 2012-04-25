#include <stdio.h>

/*

Reference:
http://www.intel.com/design/intarch/papers/endian.pdf

Endianness - 	How multibyte data is represented in the 
				memory as dicated by the CPU architecture

			MSB		 LSB
integer i = 12 34 56 78;

address			1000	1001	1002	1003
big-endian		12		34		56		78
little-endian	78		56		34		12

Big endian = 	MSB in the lower address
Little endian =	LSB in the lower address	

Advantages:
BI - (1) The sign information of the given number is 
		 available in the MSB which is placed in the 
		 first memort offset.
	 (2) Its the natural order. So binary to decimal 
	 	 are faster.
	 (3) Comparing 2 numbers (bit by bit) can be done.
		 the comparison can stop (with the correct result) 
		 when the first different bit is encountered.

LI - (1) offset 0 == byte 0 - so multiple precision math
		 routines are easy to write

Standard conversion methods:
include netinet/in.h and use the following functions:
ntohs(), ntohl(), htons(), htonl()

-> Network byte order is Big endian

*/

void check1(void)
{
	printf("%s - ", __FUNCTION__);
	union findendian {
		int i;
		char c[sizeof(int)];
	} myendian;
	
	myendian.i = 1;
	if (myendian.c[0] == 1) {
		printf("Little endian \n");
	} else {
		printf("Big endian \n");
	}

	return;
}

void check2(void)
{
	printf("%s - ", __FUNCTION__);
	int i = 1;
	
	if (*(char *) &i == 1) {
		printf("Little endian \n");
	} else {
		printf("Big endian \n");
	}

	return;
}

/*
Disadvantage of this method 
(1) struct may add padding
(2) size of int is assumed to be 4 bytes
*/
void convert1(void)
{
	printf("%s - ", __FUNCTION__);
	int num = 0x11223344;

	typedef union endian {
		int i;
		char c[sizeof(int)];
	} myendian;
	
	myendian a = {0};
	myendian b = {0};

	a.i = num;	
	b.c[0] = a.c[3];
	b.c[1] = a.c[2];
	b.c[2] = a.c[1];
	b.c[3] = a.c[0];
	
	printf("%x - %x \n", a.i, b.i);
	return;
}


/*
conversion using bitwise operations
Disadvantages
(1) Bitwise works only on intergers, not other types like float
(2) size of integer is assumed to be 4 bytes
*/
void convert2(void)
{
	printf("%s - ", __FUNCTION__);
	int num = 0x11223344;
	int revnum = 0;
	
	/*
	printf("%x \n", num >> 24);
	printf("%x \n", (num >> 24) & 0x000000FF);
	printf("%x \n", num >> 8);
	printf("%x \n", (num >> 8) & 0x0000FF00);
	printf("%x \n", num << 8);
	printf("%x \n", (num << 8) & 0x00FF0000);
	printf("%x \n", num << 24);
	printf("%x \n", (num << 24) & 0xFF000000);
	*/

	revnum |= (num >> 24) & 0x000000FF;
	revnum |= (num >> 8)  & 0x0000FF00;
	revnum |= (num << 8)  & 0x00FF0000;
	revnum |= (num << 24) & 0xFF000000;

	printf("%x - %x \n", num, revnum);
	return;
}

void convert3(void)
{
	printf("%s - ", __FUNCTION__);
	typedef int T;
	T num = 0x11223344;
	T rev = 0;
	char *nump = (char *) &num;
	char *revp = (char *) &rev;

	int size = sizeof(T);
	int i = 0;
	
	for(i=0 ; i<size ; i++) {
		revp[i] = nump[size-i-1];
	}
	
	printf("%x - %x \n", num, rev);
	return;
}


void reverse(void *dst, void *src, size_t size)
{
	char *s = (char *) src + size - 1;
	char *d = (char *) dst;

	while (size--)
		*d++ = *s--;		
}

void convert4(void)
{
	printf("%s - ", __FUNCTION__);
	int i = 0x11223344, j;
	//long l1=0x01, l2;	

	reverse(&j, &i, sizeof(int));
	//reverse(&l2, &l1, sizeof(long));
	
	printf("%x - %x \n", i, j);
	//printf("%x - %x \n", l1, l2);
	return;
}

void convert5(void)
{
	printf("%s - ", __FUNCTION__);
	#include <netinet/in.h>
	int i = 0x11223344;
	int j = htonl(i);
	
	printf("%x - %x \n", i, j);
	return;
}

int main()
{
	check1();
	check2();

	convert1();
	convert2();
	convert3();
	convert4();
	convert5();

	return 0;
}
