#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <signal.h>
#include <errno.h>
#define MAXLENGTH 1024
#define DELIMS " \t\r\n"

void signalhandler(int signum)
{
	printf("ketik exit untuk keluar program");
	printf("Masukkan perintah ");
}

int main()
{
	signal(SIGINT, signalhandler);//signaling ctrl+c
	signal(SIGTSTP, signalhandler);	//signaling ctrl+z

	char *cmd;
	char line[MAXLENGTH]; //get command line
	char *argv[100]; //user command
	char *path="/bin/"; //set path at bin
	char fullpath[20]; //full file path
	int argc; //argument count

	while(1)
	{
		
		printf("Masukkan perintah ");

    		if (!fgets(line, MAXLENGTH, stdin)) break;

    		if ((cmd = strtok(line, DELIMS))) 
		{
      			errno = 0;

     			if (strcmp(cmd, "cd") == 0) 
			{
        			char *arg = strtok(0, DELIMS);

        			if (!arg) fprintf(stderr, "argumen cd masih kurang\n");
        			else chdir(arg);
      			} 
			
    		}

		if (strcmp(cmd, "exit") == 0) 
		break;
			
		char *token; //split command into separate things
		token=strtok(line," ");
		int i=0;
		while(token!=NULL)
		{
			argv[i]=token;
			token=strtok(NULL," ");
			i++;
		}
		argv[i]=NULL; //set last value to NULL for execvp
		argc=i; //get argument count
		strcpy(fullpath,path); //copy /bin/ to file path
		strcat(fullpath,argv[0]); //add program to path

		for(i=0;i<strlen(fullpath);i++) //delete newline
		{
			if(fullpath[i]=='\n')
			{
				fullpath[i]='\0';
			}
		}
		pthread_t pid=fork(); //fork child
		if(pid==0) //child
		{
			//if(strcmp(argv[argc-1],"&")==0) argv[argc-1]='\0';
			execvp(fullpath,argv);
			//execvp(NULL,argv);		
		}
		wait();
/*		else	//parent
		{
			//if(strcmp(argv[argc-1],"&")==0);
			wait();
		}*/
	}
}
