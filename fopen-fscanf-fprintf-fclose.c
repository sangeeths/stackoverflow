#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fpi, *fpo;
    char data[100];
    int pts;
    float xxa, xxb, yyc, yyd;

    fpi = fopen("data.in", "r");

    if (fpi == NULL) {
        perror("Failed to open file - data.in \n");
        return 1;
    }

    fscanf(fpi, "%s %d %f %f %f %f", data, &pts, &xxa, &xxb, &yyc, &yyd);
    fclose(fpi);

    /* do you calculations here */

    fpo = fopen("data.out", "w");

    if (fpi == NULL) {
        perror("Failed to open file - data.out \n");
        return 1;
    }

    fprintf(fpo, "%s %d %1.1f %1.1f %1.1f %1.1f\n", data, pts, xxa, xxb, yyc, yyd);
    fclose(fpo);

    return 0;
}

