#include <stdio.h>

#define N 4

int main()
{
	int matrix[N][N];
	int i, j, val = 1;
	
	for (i=0; i<N; i++)
		for (j=0; j<N; j++)
			matrix[i][j] = val++;

	for (i=0; i<N; i++) {
		for (j=0; j<N; j++) {
			printf("%3d", matrix[i][j]);
		} 
		printf("\n");
	}


	int layer, first, last, offset, top;
	for (layer = 0; layer < N/2 ; layer++) {
		first = layer;
		last = N - layer - 1;

		for (i=first; i< last ; i++) {
			offset = i - first;
			top = matrix[first][i];

			matrix[first][i] = matrix[last-offset][first];
			matrix[last-offset][first] = matrix[last][last-offset];
			matrix[last][last-offset] = matrix[i][last];
			matrix[i][last] = top;
			
		}
	}
	
	printf("\n\n\n");

	for (i=0; i<N; i++) {
		for (j=0; j<N; j++) {
			printf("%3d", matrix[i][j]);
		} 
		printf("\n");
	}

	return 0;
}
