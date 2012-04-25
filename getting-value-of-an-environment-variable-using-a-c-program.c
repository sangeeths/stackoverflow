/*
 * The recommended way is to use the solution provided by ANSI as getenv() function for maximum portability:
 */

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    char * env = getenv(“PROMPT”); 

    if(env)
        puts(env);
    else
    puts(“The environmental variable not available”);

    return 0;
}

/*
There are other non-standard ways of doing the same which is not recommended.

The third argument to main() could be char **envp is used widely to get the information about the environment and is non-standard.
*/


int main(int argc, char **argv, char **envp)
{
    while(*envp)
        printf("%s\n",*envp++);
}

/*
Using the third argument in main() is not strictly conforming to standard.

There is another widely used non-standard way of accessing the environmental variables and that is through the environ external variable.

*/

int i=0;
extern char ** environ;

while(environ[i])
    printf("\n%s",environ[i++]);

/*
NOTE: The examples are in-complete and lacks error handling.
*/
