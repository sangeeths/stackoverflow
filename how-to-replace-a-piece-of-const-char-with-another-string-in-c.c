#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * strrep(char *str, char *o_s, char *n_s) 
{
    char *newstr = NULL;
    char *c = NULL;

    /* no substring found */
    if ((c = strstr(str, o_s)) == NULL) {
        return str;
    }

    if ((newstr = (char *) malloc((int) sizeof(str) -
                                  (int) sizeof(o_s) +
                                  (int) sizeof(n_s) + 1)) == NULL) {
        printf("ERROR: unable to allocate memory\n");
        return NULL;
    }

    strncpy(newstr, str, c-str);  
    sprintf(newstr+(c-str), "%s%s", n_s, c+strlen(o_s));

    return newstr;
}

int main(void) 
{
    char str[] = "http://1.1.1.1/test.mpg";
    char old_s[] = "mpg";
    char new_s[] = "mkv";
    char *str_new = strrep(str, old_s, new_s);

    if (str_new != NULL) {
        printf("Original : %s\n", str);
        printf("Replaced : %s\n", str_new);
    }

    return 0;
}

/*
$ gcc strrep.c 
$ ./a.out 
Original : http://1.1.1.1/test.mpg
Replaced : http://1.1.1.1/test.mkv
$ 
*/
