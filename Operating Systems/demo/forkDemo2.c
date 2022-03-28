#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


int main(void)
{
	char buf[1024];
	pid_t pid;
	int status;
	printf("%% ");
	while (fgets(buf,1024,stdin) != NULL)
	{
		buf[strlen(buf) -1] =0;
		if ((pid = fork()) <0)
			printf("fork error");
		else if (pid == 0) { /* child */
			execlp(buf, buf, (char *) 0);
			printf("couldn't execute: %s", buf);
			_exit(127);
		}
		/* parent */
		if ( (pid = waitpid(pid, &status, 0)) <0)
			printf("waitpid error");
		printf("%% ");
	}
	return 0;
}
