// main.c

#include "a2.h"        /* Function prototypes */
#include <dirent.h>    /* ? */
#include <errno.h>     /* errno */
#include <stdio.h>     /* printf, stderr, fprintf */
#include <stdlib.h>    /* exit */
#include <string.h>    /* strlen */
#include <sys/types.h> /* creat, pid_t */
#include <sys/stat.h>  /* mkdir */
#include <time.h>      /* supposed to be used for formatdate */
#include <unistd.h>    /* _exit, fork */

int main(int argc, const char *argv[])
{
  while (1)
  {
    int option;

    printf("=============== CS 570 Summer 2018 Assignment #2 ===============\n\n");
    printf("1. Create new directory files\n");
    printf("2. Create new regular files\n");
    printf("3. Read from a file (print out to stdout)\n");
    printf("4. Write to a file in either insert, append, or overwrite mode\n");
    printf("5. Print file status (print out to stdout)\n");
    printf("6. Print directory listing (contents of dir file) (print out to stdout)\n");
    printf("0. Exit\n\n");

    printf("Select an option: ");
    scanf("%d", &option);

    printf("\nYou entered: %d\n\nNow entering the switch statement.\n\n", option);

    switch (option)
    {
    case 1:
      printf("Option #1 chosen!\n\n");
      createDirectory();
      break;
    case 2:
      printf("Option #2 chosen!\n\n");
      createRegularFile();
      break;
    case 3:
      printf("Option #3 chosen!\n\n");
      readFromFile();
      break;
    case 4:
      printf("Option #4 chosen!\n\n");
      writeFiles();
      break;
    case 5:
      printf("Option #5 chosen!\n\n");
      printFileStatus();
      break;
    case 6:
      printf("Option #6 chosen!\n\n");
      printDirectoryListing();
      break;
    case 0:
      printf("Exiting program...\n\n");
      return (0);
    default:
      printf("ERROR! Shutting down program.\n\n");
      exit(0);
    }
  }
}