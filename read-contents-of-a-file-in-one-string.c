#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp = NULL;
    int len = 0;
    char * file_buff = NULL;

    if ((fp = fopen("file1", "rb")) == NULL) {
        printf("Failed to open file\n"); 
        return EXIT_FAILURE;
    }   

    fseek(fp, 0, SEEK_END);
    len = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    if ((file_buff = (char *) malloc((int)sizeof(char) * len)) == NULL) {
        printf("ERROR: unable to allocate memory\n");
        return EXIT_FAILURE;
    }   

    fread(file_buff, len, 1, fp);   
    fclose(fp);

    printf("Contents of the file : \n%s", file_buff);

    /* do whatever you wanted to do with file_buff here */

    /* once done, free the file buffer */
    free(file_buff);

    return EXIT_SUCCESS;
}

