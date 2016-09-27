/*Unix C program*/
#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>

int value = 10;

int main()
{
	pid_t pid;
	pid = fork;

	if(pid == 0)
	{
		value += 15;
	}
	else if(pid > 0)
	{
		wait(NULL);
		printf("PARENT: value = %d", value);
		exit(0);
	}
}
