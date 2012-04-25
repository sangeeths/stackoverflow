#include <stdio.h>

#define n 4

int main(void)
{
	int a[n][n] = {{1, 2, 3, 4},
				   {5, 6, 7, 8},
				   {1, 2, 3, 4},
				   {5, 6, 7, 8}};
	int b[n][n] = {{1, 2, 3, 4},
				   {5, 6, 7, 8},
				   {1, 2, 3, 4},
				   {5, 6, 7, 8}};
	int ab[n][n];
	int i, j, k;

	for (i=0 ; i<n ; i++) {
		for (j=0 ; j<n ; j++) {
			ab[i][j] = 0;
			for (k=0 ; k<n ; k++)
				ab[i][j] += a[i][k] * b[k][j];
		}
	}	

	for (i=0 ; i<n ; i++) {
		for (j=0 ; j<n ; j++) {
			printf("%5d", ab[i][j]);
		}
		printf("\n");
	}

	return 0;
}

