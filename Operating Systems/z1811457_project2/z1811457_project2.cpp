#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <fcntl.h>

//Magic from tutor, because C is evil.
char** convert_to_c(std::vector<std::string> input){
	char** ret = (char **)malloc(input.size()*sizeof(char*));
	for(size_t pos=0;pos<input.size();pos++){
		ret[pos] = (char *)malloc(input[pos].size()*sizeof(char));
		strcpy(ret[pos],input[pos].c_str());
	}
	return ret;
}

std::vector<std::string> prompt() {
	char buf[1024];
	char const *delim = " \n";
	printf("myshell> ");
	fgets(buf,1024,stdin);
	char const *token = strtok(buf,delim);
	std::vector<std::string> tokenBag;
	do{

		tokenBag.push_back(token);
		token = strtok(nullptr,delim);
	}
	while(token != nullptr);
	return tokenBag;
}

void firCumFirSer(int num) {
	int waitTot = 0;
	int waitAvg = 0;

	srand(10);
	std::cout << "FCFS scheduling simulation with " << num <<" processes.\n";
	for(int i = 0; i < num; i++) { //all random values
		int random_number = rand()%100 + 1;
		if(!(i == num-1)) {
			waitTot += random_number*(num-i); //random number between 1 and 100;//calculate wait total
		}
		std::cout << "CPU burst: " << random_number << " ms\n";
	}
	waitAvg = waitTot/num; //calculate wait average

	std::cout << "Total waiting time in the ready queue: " << waitTot << " ms\n" 
		<< "Average waiting time in the ready queue: " << waitAvg << " ms\n";

}

int main(void) {
	pid_t pid;
	int status;
	auto userInput = prompt();
	while (userInput.size() != 0) {
		if(userInput[0] == "quit" || userInput[0] == "q") {
			std::cout << "Quitting Program: \n";
			exit(128);
		}
		else if(userInput[0] == "fcfs") {	
			firCumFirSer(std::stoi(userInput[1]));
		}
		else {
			pid_t child = fork();
			if (child == 0) {
				if(*(userInput.end()-2) == ">") { //.end() gives back location one after last of line. '*' dereferences pointer.
					int openFile = open((userInput.end()-1)->c_str(), O_CREAT | O_TRUNC | O_WRONLY); //open command
					dup2(openFile,STDOUT_FILENO);//dup2 command
					close(openFile);//close command
					userInput.pop_back();
					userInput.pop_back();
				}
				//if statement that returns the value of fork, if 0 = child, 1 = parent
				execvp(userInput[0].c_str(), convert_to_c(userInput));
				printf("couldn't execute: %s \n", userInput[0].c_str()); //better change to printing to stderr
				exit(127);
			}
			else { 
				if((pid = waitpid(child, &status, 0)) <0)
					printf("waitpid errorn\n");
			}
		}
		userInput = prompt();
	}
	exit(0);
}	
