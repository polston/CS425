#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE 90
#define HISTORY_SIZE 10

//parses user input into character pointer array to be passed into execvp
void setup(char* args[], char in[])
{
	char **next = args;
	char *t = strtok(in, " ");
		int count = 0;
		
		while (t != NULL)
	    {
	        *next++ = t;
	        t = strtok(NULL, " ");
	    }
	    *next = NULL;
}

void addHist(char** hist, char in[], int histCount)
{
	char* tempStr = (char*)malloc(strlen(in)+1);
	strcpy(tempStr, in);
	int tempHistCount = histCount % HISTORY_SIZE;
	strcpy(hist[tempHistCount], tempStr);
}



int main(void)
{
	char *args[MAX_LINE]; // command line arguments
	char **hist;
	int histCount = 0;
	hist = malloc(HISTORY_SIZE * sizeof(char *));
	
	for(int i = 0; i < HISTORY_SIZE; i++)
	{
		hist[i] = malloc(HISTORY_SIZE * sizeof(char));
    	hist[i][0] = '\0';
	}
	
	char input[MAX_LINE];
	int should_run = 1;
	pid_t pid;
	
	//char* thing = "";

	while(should_run)
	{
		
		printf("COMMAND->");
		fflush(stdout);
		
		/*After reading user input, the steps are:
		 *(1) for a child process using fork();
		 *(2) the child process will invoke execvp();
		 *(3) if command included &, parent will invoke wait()
		*/
		
		//gets user input
		fgets(input, sizeof(input), stdin);
		int len;
		len = strlen(input);
		if (len > 0 && input[len-1] == '\n') {
		    input[len-1] = '\0';
		}
		
		//printf("test %s\n", input);
		//read user input
		//Put strings into the array
		
		//addHist(hist, input, histCount);
		addHist(hist, input, histCount);
		histCount++;
	    setup(args, input);
	    
	    /*
        for (char **next = args; *next != 0; next++)
            printf("Checking: %s\n", *next);
    	*/

        for (char **next = hist; *next != 0; next++)
            printf("History: %s\n", *next);
            
	    printf("HistCount: %d\n", histCount);
	    //printf("-----------------------------------------------------\n");
		pid = fork();
		
		//printf("-----------------------------------------------------\n");
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
		
		//sleep(1);
		//in parent
		printf("in parent\n");
		wait(NULL);
	}

	return 0;
}
