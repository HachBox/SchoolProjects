#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>

void firCumFirSer(int num) {
	int waitTot = 0;
	int waitAvg = 0;

	std::cout << "FCFS scheduling simulation with " << num <<" processes.\n";
	for(int i = 0; i < num; i++) { //all random values
		int random_number = rand()%100 + 3;
		if(!(i == num-1)) {
			waitTot += random_number; //random number between 1 and 100;//calculate wait total
		}
		std::cout << "CPU burst: " << random_number << " ms\n";
	}
	waitAvg = waitTot/num; //calculate wait average

	std::cout << "Total waiting time in the ready queue: " << waitTot << " ms\n" 
		  << "Average waiting time in the ready queue: " << waitAvg << " ms\n";
	
}

int main(void) {
	char buf[1024];
	pid_t pid;
	int status;
	printf("myshell> ");
	while (fgets(buf,1024,stdin) != NULL) {
		buf[strlen(buf) -1] =0;
		if ((pid = fork()) <0)
			printf("fork error");
		else if (pid==0) { /* child */
			if(strcmp(buf,"quit") == 0 || strcmp(buf,"q") == 0){
				std::cout << "Quitting Program: \n";
				exit(128);
			}
			execlp(buf, buf, (char *) 0);
			execvp(firCumFirSer(buf));
			printf("couldn't execute: %s \n", buf); //better change to printing to stderr
			exit(127);
		}
		/* parent */
		if ( (pid = waitpid(pid, &status, 0)) <0)
			printf("waitpid error");
		printf("\nmyshell> ");
		exit(0);
	}
	exit(0);
} 
