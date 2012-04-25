#include <stdio.h>

/*

NOTE: 
The mergesort boils downs to this.. 
Given two sorted array's how do we merge this?

We need a new array to hold the result of merging
otherwise it is not possible to do it using array, 
so we may need a linked list

*/

void merge(int a[], int i, int j)
{
    int mid = (i+j)/2;
    int ai = i;
    int bi = mid+1;

    int newa[j-i+1], newai = 0;

    while(ai <= mid && bi <= j) {
        if (a[ai] > a[bi])
            newa[newai++] = a[bi++];
        else                    
            newa[newai++] = a[ai++];
    }

    while(ai <= mid) {
        newa[newai++] = a[ai++];
    }

    while(bi <= j) {
        newa[newai++] = a[bi++];
    }

    for (ai = 0; ai < (j-i+1) ; ai++)
        a[i+ai] = newa[ai];

}

void mergesort(int a[], int i, int j)
{
    int mid = (i+j) / 2;

    if (i >= j) return;

    mergesort(a, i, mid);
    mergesort(a, mid+1, j);
    merge(a, i, j);
    return;
}

int main()
{
    //int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int a[] = {9, 7, 2, 3, 5, 4, 1, 8, 6, 10};
    int i;

    mergesort(a, 0, 9);

    for (i = 0; i < 10; i++)
        printf ("%d ", a[i]);

    printf ("\n");

    return 0;
}
