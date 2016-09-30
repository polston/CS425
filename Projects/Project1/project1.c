#include <stdio.h>
#include <unistd.h>

#define MAX_LINE 90

int main(void)
{
	char *args[MAX_LINE/2+1]; // command line arguments
	int should_run = 1;
	//int pid;

	while(should_run)
	{
		printf("COMMAND->");
		fflush(stdout);
		/*After reading user input, the steps are:
		 *(1) for a child process using fork();
		 *(2) the child process will invoke execvp();
		 *(3) if command included &, parent will invoke wait()
		*/
		scanf("%s", *args);
		//pid = fork();
		fork();

	}

	return 0;
}
