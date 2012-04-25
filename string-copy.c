// array version
char * strcpy1(char to[], char from[])
{
        int i=0;
        while(from[i]) {
                to[i] = from[i];
                i++;
        }       
        to[i] = '\0';
        return to;
}

// pointer version
char * strcpy2(char *to, char *from)
{
        char *t = to;
        while (*to++ = *from++);
        return t;
}

