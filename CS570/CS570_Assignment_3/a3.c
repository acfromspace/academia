// a3.c
// Contains the functions as listed in "a3.h"

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

void wallClock()
{
  // Temp buffer to get termination string
  char clockstring[b_size];

  strcpy(clockstring, "times up...");

  printf("Child 1 process executing...\n");

  time_t ltime;
  struct tm *newtime;

  // Show current time
  for (;;)
  {
    // Get the time in seconds
    time(&ltime);

    // Convert to structure
    newtime = localtime(&ltime);

    // Read message from child 2 process
    int status = read(pipe2[0], buffstring, b_size);

    // Compare buffer
    int areTheyTheSame = strcmp(clockstring, buffstring);

    // If not, end print current status and buffer
    if (areTheyTheSame != 0)
    {
      printf("%s\n", asctime(newtime));

      // Show every second
      sleep(1);
    }

    // If so, print termination
    if (areTheyTheSame == 0)
    {
      // Return back to parent
      printf("End of wall clock function...\n");
      printf("Program will be terminated. Have a nice day!\n");
      exit(1);
    }
  }
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void countdownTimer(int initial)
{
  int hour, min, sec;

  printf("Child 2 process executing...\n");

  // Countdown timer
  // Method for displaying countdown cited from:
  // http://www.psychocodes.in/c-program-to-convert-seconds-into-hours-minutes-and-seconds.html

  for (; initial > 0; initial--)
  {
    if (initial > 3600)
    {
      min = initial / 60;
      sec = initial % 60;
      hour = min / 60;
      min = min % 60;
      printf("Count down: %d hour %d mins %d secs \n", hour, min, sec);
    }
    else
    {
      min = initial / 60;
      sec = initial % 60;
      printf("Count down: %d mins %d secs\n", min, sec);
    }

    // Send signal to child 1 process not to end
    write(pipe2[1], "still counting", b_size);

    // Count down every second
    sleep(1);
  }

  // Signal to other process to terminate
  strcpy(buffstring, "times up...");
  write(pipe2[1], buffstring, sizeof(buffstring));

  // Alarm notification
  printf("ALARM! ALARM! ALARM!\n");
  printf("End of countdown timer function...\n");
}