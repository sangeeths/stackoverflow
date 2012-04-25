#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid;

    switch(pid = fork()) {
    case -1: 
        perror("fork");  
        exit(1);             

    case 0:
        printf(" CHILD: This is the child process!\n");
        printf(" CHILD: My PID is %d\n", getpid());
        printf(" CHILD: My parent's PID is %d\n", getppid());
        /* you can exec another program here if you wish to */
        printf(" CHILD: I'm outta here!\n");
        break;

    default:
        printf("PARENT: This is the parent process!\n");
        printf("PARENT: My PID is %d\n", getpid());
        printf("PARENT: My child's PID is %d\n", pid);
        printf("PARENT: I'm not going to wait for my child to exit\n");
        signal(SIGCHLD, SIG_IGN);
        printf("PARENT: I'm outta here!\n");
    }   

    return 0;
}

