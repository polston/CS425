#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE 90

void setup(char* strArr[], char str[])
{
	char **next = strArr;
	char *t = strtok(str, " ");
		int count = 0;
		
		while (t != NULL)
	    {
	        *next++ = t;
	        t = strtok(NULL, " ");
	    }
	    *next = NULL;
}

int main(void)
{
	char *args[MAX_LINE]; // command line arguments
	
	char input[MAX_LINE];
	int should_run = 1;
	pid_t pid = fork();
	
	//char* thing = "";

	while(should_run)
	{
		fflush(stdout);
		printf("COMMAND->");
		
		/*After reading user input, the steps are:
		 *(1) for a child process using fork();
		 *(2) the child process will invoke execvp();
		 *(3) if command included &, parent will invoke wait()
		*/
		fgets(input, sizeof(input), stdin);
		int len;
		len = strlen(input);
		if (len > 0 && input[len-1] == '\n') {
		    input[len-1] = '\0';
		}
		
		printf("test %s\n", input);
		
		//read user input
		//Put strings into the array
		/*
		char *t = strtok(input, " ");
		int count = 0;
		
		while (t != NULL)
	    {
	        //printf("t: %s\n", t);
	        *next++ = t;
	        //strcpy(args[count], t);
	        t = strtok(NULL, " ");
	        //printf("strArr[count]: %s\n", args[count]);
	        //count++;
	    }
	    *next = NULL;
	    */
	    
	    setup(args, input);
	    
	    puts("Checking:");
        for (char **next = args; *next != 0; next++)
            puts(*next);
	    
		pid = fork();
		

		if(pid < 0)
		{
			perror("Fork failed.");
		}
		else if(pid == 0)
		{
			printf("in child\n");
			//char usrInput[MAX_LINE/2+1];
			execvp(args[0], args);
			//sleep(5);
		}
		
		sleep(1);
		//in parent
		printf("in parent\n");
		wait(NULL);
	}

	return 0;
}
