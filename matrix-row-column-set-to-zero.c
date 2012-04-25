#include <stdio.h>
#include <stdlib.h>

#define R 10 
#define C 10

int main()
{
	int i, j, val;
	int matrix[R][C] = {
 {1,    2,    3,    4,    5,    6,    7,    8,    9,   10},  
 {11,   12,   13,   14,   15,   16,   17,   18,   19,   20},  
 {21,   22,    0,   24,   25,   26,   27,   28,   29,   30},  
 {31,   32,   33,   34,   35,   36,   37,   38,   39,   40},  
 {41,   42,   43,   44,   45,   46,   47,   48,   49,   50},  
 {51,   52,   53,   54,   55,   56,   57,   58,   59,   60},  
 {41,   42,   43,   44,   45,   46,   47,   48,   49,   70},  
 {41,   42,   43,   44,   0,   0,   47,   48,   49,   80},  
 {81,   82,   83,   84,   85,   86,   87,   88,   89,   90},  
 {91,   92,   93,   94,   95,   96,   97,   98,   99,  0}};  
	
	int row[R] = {0};
	int col[C] = {0};
	
	int final[R][C] = {0};

	for (i=0 ; i<R ; i++) {
		for (j=0 ; j<C ; j++) {
			printf("%3d  ", matrix[i][j]);
		}
		printf("\n");
	}

	for (i=0 ; i<R ; i++) {
		for (j=0 ; j<C ; j++) {
			if (matrix[i][j] == 0) {
				row[i] = 1;
				col[j] = 1;
			}
		}
	}

	for (i=0 ; i<R ; i++) {
		for (j=0 ; j<C ; j++) {
			if (row[i] == 1 || col[j] == 1) {
				matrix[i][j] = 0;
			}
		}
	}

	printf("\n\n\n\n");
	for (i=0 ; i<R ; i++) {
		for (j=0 ; j<C ; j++) {
			printf("%3d  ", matrix[i][j]);
		}
		printf("\n");
	}

	return 0;
}
