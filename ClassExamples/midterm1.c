#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    pid_t pid;
    int i = 10;
    
    pid = fork();
    if(pid > 0)
    {
        printf("Parent1: %d %d\n", i, (int)getpid());
        wait(NULL);
    }
    else if(pid == 0)
    {
        i += 10;
        printf("Child1: %d %d\n", i, (int)getpid());
    }
    
    pid = fork();
    if(pid > 0)
    {
        printf("Parent1: %d %d\n", i, (int)getpid());
        wait(NULL);
    }
    else if(pid == 0)
    {
        i += 10;
        printf("Child1: %d %d\n", i,(int)getpid());
    }
    
    return 0;
}