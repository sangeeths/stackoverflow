#include <stdio.h>
#include <stdlib.h>

#define LEN 6

int main(void)
{
    unsigned long long start[LEN] = {0, 2861, 6957, 10916, 13296, 17392};
    unsigned short int length[LEN] = {2861, 4096, 3959, 2380, 4096, 4096};
    int i;
    unsigned long long s;
    unsigned short int l;
    FILE *out_file, *in_file;

    if ((out_file = fopen("out_file", "w")) == NULL) {
        printf("ERROR: unable to open out_file\n");
        return -1;
    }

    for (i=0; i<LEN; i++)
        fprintf(out_file, "%llu,%hu \n",start[i], length[i]);

    fclose(out_file);


    if ((in_file = fopen("out_file", "r")) == NULL) {
        printf("ERROR: unable to open out_file\n");
        return -1;
    }

    for (i=0; i<LEN; i++) {
        fscanf(out_file, "%llu,%hu \n", &s, &l);
        printf("start = %llu - length = %hu \n", s, l);
    }

    fclose(in_file);

    return 0;
}

