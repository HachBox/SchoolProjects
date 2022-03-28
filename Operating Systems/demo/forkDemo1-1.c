#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void) {
	pid_t pid;
	if ((pid = fork()) <0) {
		fprintf(stderr, "fork error");
		exit (-1);
	}
	else if (pid == 0) //child
	{
		printf("****** I am the child...\. ");
		execlp("/bin/ls", "ls", (char*) 0);
		printf("couldn't execute "); //if success, should not go to this line
		exit (127);
	}
	else {
		/* parent */
		wait(0);
	printf(" ----- I am the parent just finish waiting ... \n");
	}
	return 0;
}
