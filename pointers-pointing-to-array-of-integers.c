#include <stdio.h>

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int (*r)[10] = &a;

    printf("r=%p  *r=%p  *(r+0)=%p  *(r+1)=%p\n", r, *r, *(r+0), *(r+1));
    printf("sizeof(int)=%d \n", sizeof(int));

    return 0;
}


/*

The output is as follows:

r=0xbfeaa4b4  *r=0xbfeaa4b4  *(r+0)=0xbfeaa4b4  *(r+1)=0xbfeaa4dc
sizeof(int)=4 
Observations / Point(s)-to-note:

-> _DO_NOT_ de-reference a pointer which has not yet made to point to an address. So in your program int (*r)[10]; was de-referenced without being assigned to a memory area. This is not acceptable.

-> If you see the output - *r is same as *(r+0) which is same as r (only w.r.t this case)

-> If you see the output for *(r+0) and *(r+1) it is 40 bytes (0xbfeaa4dc - 0xbfeaa4b4 = sizeof(int) * size of the array (which is 10 in this case). So when you increment a pointer to a particular type, it gets incremented to sizeof(type) bytes!

-> the other worth-notable points about a pointer-to-an-array-of-integers are explained here


*/

