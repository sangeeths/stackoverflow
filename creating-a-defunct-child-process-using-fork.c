#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

/*
 * Execute this program and do 'ps ax | grep Z' to see that this
 * is put in a defunct state or zombie state
 * */

int main()
{
        pid_t child_pid;

        child_pid = fork();
        if (child_pid > 0) {
                sleep(60);
        } else {
                return 0;
        }

        return 0;
}

