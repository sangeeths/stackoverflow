#include <stdio.h>

#define SIZE 6

/*

Array:
2	-8	3	-2	4	-10
	
Subsum:
2	-8	3	-2	4	-10
	-6	-5	1	2	-6	
		-3	-7	5	-8
			-5	-3	-5
				-1	-13
					-11

Largest of all subsum = 5 (3, -2, 4)

Time complexity = O(n^2)
*/				
int largest_sequence(int a[])
{
	// variables to store the largest 
	// subsequence index.. i and j.. and 
	// the largest sum of the subsequence
	int li, lj;
	int largest;

	// the index are initialized to 0 and
	// the largest sum is initialized to the
	// first element of the array
	li = lj = 0;
	largest = a[0];
	
	int large_subsum_index;
	int large_subsum, subsum;
	int i, j;	

	for(i=1; i<SIZE ; i++) {
		large_subsum = subsum = 0;
		large_subsum_index = i;

		// find the large subsum from i to 0
		for(j=i ; j>=0; j--) {
			subsum = subsum + a[j];
			if (subsum > large_subsum) {
				large_subsum = subsum;
				large_subsum_index = j;
			}
		}

		/*
		printf("%d %d %d %d %d %d\n", 
				i, large, largest, li, lj, jindex);
		*/

		// if the now found subsum is greater than 
		// the earlier found subsum, then update the
		// index and variables..
		if (large_subsum > largest) {
			lj = i;
			li = large_subsum_index;
			largest = large_subsum;
		}
	}

	// print the subsequence with the largest sum
	for (i=li; i<=lj ;i++)
		printf("%d, ", a[i]);
	printf("\n");

	// return the largest sum
	return largest;
}


// Try to compute the largest sum of a subsequence in 
// O(n) time complexity
int largest_sequence_2(int a[])
{
	int i;
	int sum = 0, maxsum =0;
	int li, lj;
	int previ;

	previ = li = lj = 0;
	

	for(i=0; i<SIZE; i++) {
		sum = sum + a[i];
		if (maxsum < sum) {
			maxsum = sum;
			li = previ;
			lj = i;
		} else if (sum < 0) {
			sum = 0;
			previ = i+1;
		}
	}

	// print the subsequence with the largest sum
	for (i=li; i<=lj ;i++)
		printf("%d, ", a[i]);
	printf("\n");
		
	return maxsum;
}


int main()
{
	int a[SIZE] = {2, -8, -3, 2, 4, -10};

	printf("sum: %d\n", largest_sequence(a));
	printf("sum: %d\n", largest_sequence_2(a));

	return 0;
}

