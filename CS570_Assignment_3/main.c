// main.c
// Driver for the program

#include "a3.h"     /* Function prototypes */
#include <stdio.h>  /* printf, stderr, fprintf */
#include <stdlib.h> /* exit */
#include <string.h> /* strcpy */
#include <time.h>   /* supposed to be used for formatdate */
#include <unistd.h> /* _exit, fork */

#define defaultTime 25 /* 25 seconds */
#define b_size 12      /* buffer size */
#define p_size 2       /* pipe size */

// Data structures implemented
int pipe1[p_size];
int pipe2[p_size];
char buffstring[b_size];

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

int main(int argc, const char *argv[])
{
  printf("=============== CS 570 Summer 2018 Assignment #3 ===============\n\n");

  int time = defaultTime;

  // Take on arguments sent in the command line
  if (argc == 2)
  {
    // Time is the second argument given from ASCII to integer
    // How the program goes is "tevent TIME", that means [pipe1] [pipe2], with [pipe2] being time
    time = atoi(argv[1]);
  }

  // Create pipe 1 with error checking
  if (pipe(pipe1) == -1)
  {
    printf("Error opening pipe 1!\n");
    exit(1);
  }

  // Create pipe 2 with error checking
  if (pipe(pipe2) == -1)
  {
    printf("Error opening pipe 2!\n");
    exit(1);
  }

  printf("Pipes opened, now creating child processes!\n");

  // Child 1 wallClock
  switch (fork())
  {
  case -1:
    printf("Error forking child 1!\n");
    exit(1);

  case 0:
    wallClock();

  default:
    break;
  }

  // Child 2 countdownTimer
  switch (fork())
  {
  case -1:
    printf("Error forking child 2!\n");
    exit(1);

  case 0:
    countdownTimer(time);

  default:
    break;
  }

  // Program complete
  return (0);
}