#include <stdio.h>

#define N 10 
int matrix[N][N];

void display()
{
    int i, j;

    printf("\n");
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) 
            printf("%3d", matrix[i][j]);
        printf("\n");
    }
    printf("\n");

    return;
}

int main()
{
    int i, j, val = 1;
    int layer, first, last, offset, top;

    for (i=0; i<N; i++)
        for (j=0; j<N; j++)
            matrix[i][j] = val++;

    display();

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

    display();
    return 0;
}
