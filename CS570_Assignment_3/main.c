// main.c

#include "a3.h"
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

#define DEFAULT 6
#define BUF_SIZE 12
#define PIPE_SIZE 2

// Global arrays
int pfd1[PIPE_SIZE];
int pfd2[PIPE_SIZE];
char buf[BUF_SIZE];

int main(int argc, const char *argv[])
{
  int time = DEFAULT;

  // Take on arguments sent in the command line
  if (argc == 2)
  {
    // Time is the second argument given from ASCII to integer
    // How the program goes is "tevent TIME", that means [0] [1], with [1] being time
    time = atoi(argv[1]);
  }

  // Create pipe 1 with error checking
  if (pipe(pfd1) == -1)
  {
    printf("Error opening pipe 1!\n");
    exit(1);
  }

  // Create pipe 2 with error checking
  if (pipe(pfd2) == -1)
  {
    printf("Error opening pipe 2!\n");
    exit(1);
  }

  printf("Pipes opened, now creating child processes!\n");

  // Child process 1 Wall_Clock
  switch (fork())
  {
  case -1:
    printf("Error forking child 1!\n");
    exit(1);

  case 0:
    wallClock();
    exit(1);

  default:
    break;
  }

  // Child 2 Countdown
  switch (fork())
  {
  case -1:
    printf("Error forking child 2!\n");
    exit(1);

  case 0:
    countdownTimer(time);
    exit(1);

  default:
    break;
  }

  printf("Parent closing pipes.\n");

  // Pipe close error checking
  if (close(pfd1[0]) == -1)
  {
    printf("Error closing reading end of the pipe 1\n");
    exit(EXIT_FAILURE);
  }

  if (close(pfd1[1]) == -1)
  {
    printf("Error closing writing end of the pipe 1\n");
    exit(EXIT_FAILURE);
  }

  if (close(pfd2[0]) == -1)
  {
    printf("Error closing reading end of the pipe 2\n");
    exit(EXIT_FAILURE);
  }

  if (close(pfd2[1]) == -1)
  {
    printf("Error closing writing end of the pipe 2\n");
    exit(EXIT_FAILURE);
  }

  printf("Parent waiting for children completion...\n");

  // Wait until child processes is terminated
  if (wait(NULL) == -1)
  {
    printf("Error wating, no child process is ended!\n");
    exit(EXIT_FAILURE);
  }
  if (wait(NULL) == -1)
  {
    printf("Error wating, no child process is ended!\n");
    exit(EXIT_FAILURE);
  }

  printf("Friendly message: Parent process finishing...\n");

  printf("Program completed.\n");
  exit(EXIT_SUCCESS);
}