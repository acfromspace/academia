// a2.c

// Learn vim, emac

#include "a2.h"
#include <stdio.h>

int main(int argc, const char *argv[])
{
  int option;

  printf("CS 570 Summer 2018 Assignment #2 running...\n\n");
  printf("1. Create new directory files\n");
  printf("2. Create new regular files\n");
  printf("3. Create child process to write sorted output\n");
  printf("4. Create child process to shadow write/read regular files\n");
  printf("5. Read from a file (print out to stdout)\n");
  printf("6. Write to a file in either insert, append, or overwrite mode\n");
  printf("7. Print file status (print out to stdout)\n");
  printf("8. Print directory listing (contents of dir file) (print out to stdout)\n");
  printf("9. Exit\n\n");

  printf("Select an option 1-9: ");
  scanf("%d", &option);

  printf("\nYou entered: %d\n\n", option);

  printf("Entering switch statement.\n\n");

  switch (option)
  {
  case 1:
    printf("Option #1 chosen!\n");
    break;
  case 2:
    printf("Option #2 chosen!\n");
    break;
  case 3:
    printf("Option #3 chosen!\n");
    break;
  case 4:
    printf("Option #4 chosen!\n");
    break;
  case 5:
    printf("Option #5 chosen!\n");
    break;
  case 6:
    printf("Option #6 chosen!\n");
    break;
  case 7:
    printf("Option #7 chosen!\n");
    break;
  case 8:
    printf("Option #8 chosen!\n");
    break;
  case 9:
    break;
  default:
    printf("ERROR! Shutting down program.\n\n");
  }

  printf("\nEnd of program.\n");

  return 0;
}