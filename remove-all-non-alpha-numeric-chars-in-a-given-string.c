#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int isalnum_not_prefered(char s) 
{
    if((s >= 'A' && s <= 'Z') || 
       (s >= 'a' && s <= 'z') || 
       (s >= '0' && s <= '9')) 
        return 1;
    return 0;
}

int main(void)
{
    char str[] = "this!234$#&@#$^is5@#$a#@$4677~=_?}valid2234kjstring";
    int len = strlen(str);
    int i, j=0;

    char *newstr1 = NULL;
    char *newstr2 = NULL;

    if ((newstr1 = (char *) malloc(sizeof(char) * len + 1)) == NULL) {
        printf("unable to allocate memory \n");
        return -1;
    }

    for (i=0 ; i<len ; i++) {
        if (isalnum(str[i])) {
            newstr1[j] = str[i];
            j++;
        }
    }
    newstr1[j] = '\0';

    if ((newstr2 = (char *) malloc(sizeof(char) * len + 1)) == NULL) {
        printf("unable to allocate memory \n");
        return -1;
    }

    j=0;
    for (i=0 ; i<len ; i++) {
        if (isalnum_not_prefered(str[i])) {
            newstr2[j] = str[i];
            j++;
        }
    }
    newstr2[j] = '\0';

    printf("string  : %s \n", str);
    printf("result1 : %s \n", newstr1);
    printf("result2 : %s \n", newstr2);

    free(newstr1);
    free(newstr2);

    return 0;
}
