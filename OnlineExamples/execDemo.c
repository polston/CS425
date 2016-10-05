#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("execDemo: my PID is %d\n", getpid());
    
    //exec commands:
    //with L: comma separated arguements
    //with V: Vector, i.e. an array of strings
    //with P: Include normal search path for executable
    char *args[] = {"helloExec", "Hello", "World", NULL};
    
    execvp("./helloExec", args);
    
    return 0;
}