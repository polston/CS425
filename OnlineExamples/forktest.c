#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("I am: %d\n", (int)getpid());
    
    //create child
    pid_t pid = fork();
    printf("Fork returned: %d\n", (int)pid);
    
    
    if(pid < 0) //failed to fork
    {
        perror("Fork failed");
    }
    else if(pid == 0) //if inside child
    {
        printf("I am the child with pid: %d\n", (int)getpid());
        exit(0);
    }
    //we must be the parent, because the child exited
    printf("I am the parent\n");
    
    return 0;
}