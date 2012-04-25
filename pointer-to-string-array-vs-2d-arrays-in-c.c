#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ROW 5
#define COL 10

int main(void) 
{
    int i, j;
    char a[ROW][COL] = {"string1", "string2", "string3", "string4", "string5"};
    char *b[ROW];

    /*

    a[][]

      0   1   2   3   4   5   6     7    8   9
    +---+---+---+---+---+---+---+------+---+---+
    | s | t | r | i | n | g | 1 | '\0' |   |   |
    +---+---+---+---+---+---+---+------+---+---+
    | s | t | r | i | n | g | 2 | '\0' |   |   |
    +---+---+---+---+---+---+---+------+---+---+
    | s | t | r | i | n | g | 3 | '\0' |   |   |
    +---+---+---+---+---+---+---+------+---+---+
    | s | t | r | i | n | g | 4 | '\0' |   |   |
    +---+---+---+---+---+---+---+------+---+---+
    | s | t | r | i | n | g | 5 | '\0' |   |   |
    +---+---+---+---+---+---+---+------+---+---+

    */  

    /* Now, lets work on b */    
    for (i=0 ; i<5; i++) {
        if ((b[i] = malloc(sizeof(char) * COL)) == NULL) {
            printf("unable to allocate memory \n");
            return -1;
        }
    }

    strcpy(b[0], "string1");
    strcpy(b[1], "string2");
    strcpy(b[2], "string3");
    strcpy(b[3], "string4");
    strcpy(b[4], "string5");

    /*

       b[]              0   1   2   3   4   5   6    7     8   9
    +--------+        +---+---+---+---+---+---+---+------+---+---+
    |      --|------->| s | t | r | i | n | g | 1 | '\0' |   |   |
    +--------+        +---+---+---+---+---+---+---+------+---+---+
    |      --|------->| s | t | r | i | n | g | 2 | '\0' |   |   |
    +--------+        +---+---+---+---+---+---+---+------+---+---+
    |      --|------->| s | t | r | i | n | g | 3 | '\0' |   |   |
    +--------+        +---+---+---+---+---+---+---+------+---+---+
    |      --|------->| s | t | r | i | n | g | 4 | '\0' |   |   |
    +--------+        +---+---+---+---+---+---+---+------+---+---+
    |      --|------->| s | t | r | i | n | g | 5 | '\0' |   |   |
    +--------+        +---+---+---+---+---+---+---+------+---+---+

    */

    char (*ptr1)[COL] = a;
    printf("Contents of first array \n");
    for (i=0; i<ROW; i++)
        printf("%s \n", *ptr1++);


    char **ptr2 = b;
    printf("Contents of second array \n");
    for (i=0; i<ROW; i++)
        printf("%s \n", ptr2[i]);

    /* b should be free'd */
    for (i=0 ; i<5; i++)
        free(b[i]);

    return 0;
}

