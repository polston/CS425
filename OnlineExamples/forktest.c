#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void doSomeWork(char *name)
{
    const int NUM_TIMES = 5;
    for(int i = 0; i < NUM_TIMES; i++)
    {
        sleep(rand() % 4);
        printf("Done, pass %d for %s\n", i, name);
    }
}

int main(int argc, char *argv[])
{
    printf("I am: %d\n", (int)getpid());
    
    //create child
    pid_t pid = fork();
    srand((int)pid);
    printf("Fork returned: %d\n", (int)pid);
    
    
    if(pid < 0) //failed to fork
    {
        perror("Fork failed");
    }
    else if(pid == 0) //if inside child
    {
        printf("I am the child with pid: %d\n", (int)getpid());
        doSomeWork("Child");
        printf("Child exiting\n");
        exit(42);
    }
    //we must be the parent, because the child exited
    printf("I am the parent, waiting for child to end.\n");
    doSomeWork("Parent");
    int status = 0;
    pid_t childpid = wait(&status);
    printf("Parent knows child %d finished with status %d.\n", (int)childpid, status);
    int childReturnValue = WEXITSTATUS(status);
    printf("Return value was %d\n", childReturnValue);
    
    return 0;
}