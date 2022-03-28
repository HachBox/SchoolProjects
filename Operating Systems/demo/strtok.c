#include <stdio.h>
#include <unistd.h>
int main() {
  printf("Main program started\n");
  char* argv[] = { "ls", "-l", NULL };
  if (execv("ls", argv) == -1)
    perror("Could not execve");
  return 1;
}
