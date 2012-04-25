#include <stdio.h>
#include <stdlib.h>

int main()
{
	int row, column;
	int **matrix;
	int i, j, val;

	printf("Enter rows: ");
	scanf("%d", &row);
	printf("Enter columns: ");
	scanf("%d", &column);

	matrix = (int **) malloc (sizeof(int *) * row);
	for (i=0 ; i<row ; i++) 
		matrix[i] = (int *) malloc (sizeof(int) * column);

	val=1;
	for (i=0 ; i<row ; i++) {
		for (j=0 ; j<column; j++) {
			matrix[i][j] = val++;
		}
	}
		
	for (i=0 ; i<row ; i++) {
		for (j=0 ; j<column; j++) {
			printf("%3d  ", matrix[i][j]);
		}
		printf("\n");
	}

	return 0;
}

/*
Allocation of 2d matrix with only one call to malloc and 
still get to access the matrix with a[i][j] format

the matrix is divided into headers and data.

headers = metadata to store the rows
data = actual data storage - buffer

allocate one contigious memory for header and data
and then make the elements in the header to point to the data are

	<- headers -----><----------- data -----------

   	-----------------------------------------------------------------
	| | | | | |	..	|
	| | | | | |	..	|
	-----------------------------------------------------------------
	 |				   ^
	 | 				   |
	 |-----------------|
	header points to data area

*/

/*
int ** allocate2dmatrix(int rows, int cols)
{
	int header = rows * sizeof(int *);
	int data = rows * cols * sizeof(int);
	
	int ** rowptr = (int **) malloc(header + data);
	int * buf = (int *) (rowptr + rows);

	int k;

	for(k=0 ; i< rows; k++)
		rowptr[k] = buf + k*cols;

	return rowptr;
}

*/

