#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

#ifdef _WIN32
#include <windows.h>
#define chdir _chdir

#else
#include <unistd.h>
#endif

#define MAX_LENGTH 1024
#define DELIMS " \t\r\n"


/* 	menjalankan perintah-perintah usr/bin dan bin
	tidak berhenti saat ctrlc+ctlrz
	bisa menjalankan beberapa perintah secara background jika belakang perintah ada &
	without system function
*/

void signalhandler(int signum)
{
	printf("ketik exit untuk keluar program\n");
}
int main(int argc, char *argv[]) 
{
	signal(SIGINT, signalhandler);
	signal(SIGTSTP, signalhandler);		
		

  	char *cmd;
  	char line[MAX_LENGTH];
	while (1) 
	{
    		printf("masukkan perintah ");

    		if (!fgets(line, MAX_LENGTH, stdin)) break;

    		if ((cmd = strtok(line, DELIMS))) 
		{
      			errno = 0;

     			if (strcmp(cmd, "cd") == 0) 
			{
        			char *arg = strtok(0, DELIMS);

        			if (!arg) fprintf(stderr, "argumen cd masih kurang\n");
        			else chdir(arg);
      			} 
			else if (strcmp(cmd, "exit") == 0) 
			{
        			break;
    			} 
			else system(line);

      			if (errno) perror("perintah gagal\n");
    		}
	}
	printf("\n");	
	return 0;
}
