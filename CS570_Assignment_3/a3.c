// a3.c

#include "a3.h"        /* Function prototypes */
#include <dirent.h>    /* ? */
#include <errno.h>     /* errno */
#include <stdio.h>     /* printf, stderr, fprintf */
#include <stdlib.h>    /* exit */
#include <string.h>    /* strlen */
#include <sys/types.h> /* creat, pid_t */
#include <sys/wait.h>  /* wait */
#include <time.h>      /* supposed to be used for formatdate */
#include <unistd.h>    /* _exit, fork */

#define DEFAULT 25
#define BUF_SIZE 12
#define PIPE_SIZE 2

// Global arrays
int pfd1[PIPE_SIZE];
int pfd2[PIPE_SIZE];
char buf[BUF_SIZE];

void wallClock()
{
  // Temp buffer to get termination string
  char str1[BUF_SIZE];

  strcpy(str1, "time to die");

  printf("\nChild 1 process executing...\n");

  time_t now;
  struct tm *lcltime;

  // Close unused pipes
  if (close(pfd1[0]) == -1)
  {
    printf("Error closing reading end of pipe 1\n");
    _exit(1);
  }

  if (close(pfd2[1]) == -1)
  {
    printf("Error closing writing end of pipe 2\n");
    _exit(1);
  }

  if (close(pfd1[1]) == -1)
  {
    printf("Error closing writing end of pipe 1\n");
    _exit(1);
  }

  // Show current time
  for (;;)
  {

    now = time(NULL);
    lcltime = localtime(&now);

    // Read message from child 2 process
    int status = read(pfd2[0], buf, 12);

    // Compare buffer
    int ret = strcmp(str1, buf);

    // If not end print current status and buffer
    if (ret != 0)
    {
      // Printf("Read status: %d, Buffer= %s\n", status, buf);
      printf("The time is %d:%d:%d\n", lcltime->tm_hour, lcltime->tm_min, lcltime->tm_sec);
      // Show ever second
      sleep(1);
    }

    // If end signal came in
    if (ret == 0)
    {
      // Close writing end
      if (close(pfd2[0]) == -1)
      {
        printf("Error closing writing end of pipe 2\n");
        _exit(1);
      }

      // Return back to parent
      printf("End of Wall Clock(child 1) process...\n");
      exit(1);
    }
  }
}

void countdownTimer(int start)
{
  // String signal to end process
  strcpy(buf, "time to die.");

  printf("\nChild 2 process executing...\n");

  // Close unused pipes
  if (close(pfd2[0]) == -1)
  {
    printf("Error closing reading end of pipe 2\n");
    _exit(1);
  }

  if (close(pfd1[1]) == -1)
  {
    printf("Error closing writing end of pipe 1\n");
    _exit(1);
  }

  if (close(pfd1[0]) == -1)
  {
    printf("Error closing reading end of pipe 1\n");
    _exit(1);
  }

  // Countdown timer
  for (; start > 0; start--)
  {
    printf("Count Down: 00:0%d\n", start);
    // Send signal to child 1 process not to end
    write(pfd2[1], "not dead yet", 12);
    // Count down every second
    sleep(1);
  }

  // Signal to sibling to DIE
  write(pfd2[1], buf, sizeof(buf));

  // Close pipe 2 writing end
  if (close(pfd2[1]) == -1)
  {
    printf("Error closing writing end of pipe 2");
    _exit(EXIT_FAILURE);
  }

  // Back to main
  printf("Count Down: 0\n");
  printf("End of Count Down(child 2) process...\n");
  exit(1);
}

// /* ~~~~~~~~~~~~~~~~~~~~~~~~~~ OPTION 1 ~~~~~~~~~~~~~~~~~~~~~~~~~~ */

// // To remove the directory in terminal, "rm -r NAME_OF_DIRECTORY"
// void createDirectory(void)
// {
//   char new_directory[MAX_LENGTH];
//   int status;

//   printf("Name your desired directory path (0 to exit program): ");
//   scanf("%s", &new_directory);
//   exitValidation(new_directory);
//   status = mkdir(new_directory, 0777);

//   if (status == -1)
//   {
//     printf("\nThis directory path already exists or is incorrect. Please try again\n\n");
//     createDirectory();
//   }
//   else
//   {
//     printf("\nDirectory '%s' was created!\n\n", new_directory);
//   }
// }

// /* ~~~~~~~~~~~~~~~~~~~~~~~~~~ OPTION 2 ~~~~~~~~~~~~~~~~~~~~~~~~~~ */

// void createRegularFile(void) //#2
// {
//   char new_rfile[MAX_LENGTH];
//   int status;
//   struct stat buffer;

//   printf("Name your desired file (0 to exit program): ");
//   scanf("%s", &new_rfile);
//   exitValidation(new_rfile);
//   int exist = stat(new_rfile, &buffer);

//   if (status == -1)
//   {
//     printf("\nThis file path is incorrect. Please try again\n");
//     createRegularFile();
//   }
//   else
//   {
//     if (exist == 0)
//     {
//       printf("\nThis file path already exists. Please try again.\n\n");
//       createRegularFile();
//     }
//     else
//     {
//       status = creat(new_rfile, 0777);
//       printf("\nFile '%s' was created!\n\n", new_rfile);
//       memset(new_rfile, 0, sizeof new_rfile);
//     }
//   }
// }

// /* ~~~~~~~~~~~~~~~~~~~~~~~~~~ OPTION 3 ~~~~~~~~~~~~~~~~~~~~~~~~~~ */

// void readFromFile()
// {
//   FILE *fp;
//   char filename[MAX_LENGTH];
//   char c;

//   printf("Enter file to read (0 to exit program): ");
//   scanf("%s", &filename);
//   exitValidation(filename);
//   fp = fopen(filename, "r");

//   // If file does not exist, keep repeating till user puts a file that does exist.
//   while (fp == NULL)
//   {
//     printf("\nCannot open file...\n\n");
//     readFromFile();
//   }

//   printf("\n========================================================= Beginning of file...\n\n");

//   c = fgetc(fp);

//   // While the file is not at the end keep printing the characters
//   while (c != EOF)
//   {
//     printf("%c", c);
//     c = fgetc(fp);
//   }

//   fclose(fp);

//   printf("\n\n========================================================= End of file...\n");

//   shadow(filename);

//   return;
// }

// /* ~~~~~~~~~~~~~~~~~~~~~~~~~~ OPTION 4 ~~~~~~~~~~~~~~~~~~~~~~~~~~ */

// void writeFiles(void)
// {
//   int option, offset;
//   char filename[MAX_LENGTH];
//   char appending_text[MAX_LENGTH];

//   printf("Select your preference...\n\n");
//   printf("1. Append to an existing file\n");
//   printf("2. Overwrite an existing file\n");
//   printf("3. Insert to a new file\n");
//   printf("0. Exit\n\n");

//   printf("Select an option: ");
//   scanf("%d", &option);

//   printf("\nYou entered: %d\n\nNow entering the switch statement.\n\n", option);

//   switch (option)
//   {
//   case 1:

//     printf("Option #1 chosen!\n\n");

//     printf("Name the file path you would like to append: ");
//     scanf("%s", &filename);
//     printf("\nType below what you would like to append: ");
//     scanf("%d", &appending_text);
//     fgets(appending_text, 100, stdin);

//     FILE *out = fopen(filename, "a");
//     fprintf(out, "%s\n", appending_text);
//     fclose(out);

//     sortOutput(filename);
//     shadow(filename);

//     memset(filename, 0, sizeof filename);
//     memset(appending_text, 0, sizeof appending_text);

//     break;

//   case 2:
//     printf("Option #2 chosen!\n\n");
//     printf("Name the file you would like to overwrite: ");
//     scanf("%s", &filename);
//     printf("\nType your new text below: ");
//     scanf("%d", &appending_text);
//     fgets(appending_text, 100, stdin);

//     FILE *fp = fopen(filename, "w");

//     if (fp == NULL)
//     {
//       printf("\nCouldn't open file. Try again.\n");
//       writeFiles();
//     }
//     else
//     {
//       fprintf(fp, "%s\n", appending_text);
//       fclose(fp);
//     }

//     sortOutput(filename);
//     shadow(filename);

//     break;

//   case 3:
//     /* Currently does not work but does not produce any errors for me:
//     * Must be a very tiny error perhaps pertaining to lseek use.
//     * This program currently produces no errors but just make the file in question
//     * blank.
//     */
//     printf("Option #3 chosen!\n\n");

//     FILE *fd;

//     printf("Name the file you would like to insert bytes into: ");
//     scanf("%s", &filename); //select name of file
//     printf("\nEnter the bit number you'd like to start at: ");
//     scanf("%d", &offset); //enter offset bit # desired
//     printf("\nType your new text below: ");
//     scanf("%d", &appending_text); //select text to be added at specified file spot
//     fgets(appending_text, 100, stdin);

//     fd = fopen(filename, "w");
//     // Opens for reading + writing.
//     // I think the problem has to do with the write mode probably and finding the right one
//     // now that i think about it.
//     // Since it is supposed to insert at nth point and not overwrite.

//     // Also tried fseek but got some results.
//     // All it does is make the file blank.
//     // Has to be just a small error
//     fseek(fd, offset, SEEK_SET);

//     fprintf(fd, "%s\n", appending_text);
//     fclose(fd);

//     sortOutput(filename);
//     shadow(filename);

//     break;

//   case 0:
//     printf("Exiting program...\n\n");
//     exit(0);

//   default:
//     printf("ERROR! Shutting down program.\n\n");
//     exit(0);
//   }
// }

// /* ~~~~~~~~~~~~~~~~~~~~~~~~~~ OPTION 5 ~~~~~~~~~~~~~~~~~~~~~~~~~~ */

// void printFileStatus()
// {
//   struct stat sb;
//   char filename[MAX_LENGTH];
//   char atime[200];
//   int status;

//   printf("Enter file name (0 to exit program): ");
//   scanf("%s", &filename);
//   exitValidation(filename);
//   status = stat(filename, &sb);

//   while (status < 0)
//   {
//     printf("\nCannot get status of file...\n");
//     printFileStatus();
//   }

//   printf("\nFile status for %s...\n", filename);
//   printf("\n======================= File information =======================\n\n");
//   printf("File size: %d bytes\n", sb.st_size);

//   printf("Number of hard links: %d\n", sb.st_nlink);

//   strcpy(atime, ctime(&sb.st_mtime));
//   printf("Last modification = %s", atime);
//   memset(atime, 0, sizeof atime);

//   strcpy(atime, ctime(&sb.st_atime));
//   printf("Last access = %s", atime);
//   memset(atime, 0, sizeof atime);

//   strcpy(atime, ctime(&sb.st_ctime));
//   printf("Last status change = %s\n", atime);
//   memset(atime, 0, sizeof atime);
// }

// /* ~~~~~~~~~~~~~~~~~~~~~~~~~~ OPTION 6 ~~~~~~~~~~~~~~~~~~~~~~~~~~ */

// void printDirectoryListing()
// { //8.Print directory listing (contents of dir file) (print out to stdout)
//   DIR *dirp;
//   struct dirent *file;
//   char dirname[MAX_LENGTH];

//   printf("Enter directory name or filepath (0 to exit program): ");
//   scanf("%s", &dirname);
//   exitValidation(dirname);
//   dirp = opendir(dirname);

//   while (dirp == NULL)
//   {
//     printf("\nCannot open directory...\n\n");
//     printDirectoryListing();
//   }

//   while ((file = readdir(dirp)) != NULL)
//   {
//     printf("%s\n", file->d_name);
//   }

//   closedir(dirp);
// }

// /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~ Sorted ~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

// // Alphabetical order of output, and reverse order of the alphabetical order
// // When user is done writing...
// // Two child processes create
// // 1 will create a new file and populate it with the contents written in alphabetical order
// // 2 will create a new file and populate it with the contents written in reverse order

// void sortOutput(char filename[])
// {
//   // Instantiate process id with a data type
//   pid_t pid1, pid2;

//   // Creates child process
//   pid1 = fork();

//   // Compares the process being run
//   if (pid1 < 0)
//   {
//     /* Error:
//     *  When fork() returns -1, an error happened
//     *  (ex: number of processes reached the limit).
//     */
//     fprintf(stderr, "can't fork, error %d\n", errno);
//     exit(EXIT_FAILURE);
//   }
//   else if (pid1 == 0)
//   {
//     /* Child process:
//     *  When fork() returns 0, we are in the child process.
//     */
//     printf("Child 'alphabetical' process: ID %d\n", getpid());

//     // Alphabetical order code
//     FILE *fptr1, *fptr2;
//     char *fn = malloc(strlen(filename + MAX_LENGTH));
//     char tempList[MAX_LENGTH][MAX_LENGTH];
//     int i, index = 0;

//     // Open file you want to copy
//     fptr1 = fopen(filename, "r");

//     // If file does not exist, exit the program
//     if (fptr1 == NULL)
//     {
//       exit(0);
//     }

//     // Goes through file and separates by new line
//     while (index < MAX_LENGTH && fgets(tempList[index], sizeof(*tempList), fptr1) != NULL)
//     {
//       char *n = strchr(tempList[index], '\n');
//       if (n != NULL)
//         *n = 0;
//       if (*(tempList[index])) /* don't insert blank lines */
//         ++index;
//     }

//     // Sorts the array through comparison function that is user created
//     qsort(tempList, index, sizeof tempList[0], cmp_str);

//     // Copied file will be appended w/ ".alpha.txt" towards the end
//     sprintf(fn, "%s.alpha.txt", filename);

//     // New .alpha.txt file will get ready to write, if it exists, overwrite
//     fptr2 = fopen(fn, "w");

//     for (i = 0; i < index; i++)
//     {
//       fputs(tempList[i], fptr2);
//     }

//     // Close files
//     fclose(fptr1);
//     fclose(fptr2);

//     // Free memory from malloc
//     free(fn);

//     exit(0); // Ends child process when done executing code
//   }
//   else
//   {
//     /* When fork() returns a positive number, we are in the parent process
//     *  (the fork return value is the PID of the newly created child process)
//     */
//     printf("\nParent 'alphabetical' process: ID %d\n", getpid());

//     wait(1); // Waits for child process to complete before progressing
//   }

//   pid2 = fork();

//   // Compares the process being run
//   if (pid2 < 0)
//   {
//     /* Error:
//     *  When fork() returns -1, an error happened
//     *  (ex: number of processes reached the limit).
//     */
//     fprintf(stderr, "can't fork, error %d\n", errno);
//     exit(EXIT_FAILURE);
//   }
//   else if (pid2 == 0)
//   {
//     /* Child process:
//     *  When fork() returns 0, we are in the child process.
//     */
//     printf("Child 'reverse' process: ID %d\n", getpid());

//     // Reverse order code
//     FILE *fptr1, *fptr2;
//     char *fn = malloc(strlen(filename + MAX_LENGTH));
//     char tempList[MAX_LENGTH][MAX_LENGTH];
//     int i, index = 0;

//     // Open file you want to copy
//     fptr1 = fopen(filename, "r");

//     // If file does not exist, exit the program
//     if (fptr1 == NULL)
//     {
//       exit(0);
//     }

//     // Goes through file and separates by new line
//     while (index < MAX_LENGTH && fgets(tempList[index], sizeof(*tempList), fptr1) != NULL)
//     {
//       char *n = strchr(tempList[index], '\n');
//       if (n != NULL)
//         *n = 0;
//       if (*(tempList[index])) /* don't insert blank lines */
//         ++index;
//     }

//     // Sorts the array through comparison function that is user created
//     qsort(tempList, index, sizeof tempList[0], cmp_str);

//     // Copied file will be appended w/ ".reverse.txt" towards the end
//     sprintf(fn, "%s.reverse.txt", filename);

//     // New .reverse.txt file will get ready to write, if it exists, overwrite
//     fptr2 = fopen(fn, "w");

//     for (i = index; i > 0; i--)
//     {
//       fputs(tempList[i], fptr2);
//     }

//     // Close files
//     fclose(fptr1);
//     fclose(fptr2);

//     // Free memory from malloc
//     free(fn);

//     exit(0); // Ends child process when done executing code
//   }
//   else
//   {
//     /* When fork() returns a positive number, we are in the parent process
//     *  (the fork return value is the PID of the newly created child process)
//     */
//     printf("\nParent 'reverse' process: ID %d\n", getpid());

//     wait(1); // Waits for child process to complete before progressing
//   }
// }

// int cmp_str(const void *lhs, const void *rhs)
// {
//   return strcmp(lhs, rhs);
// }

// /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~ Shadow ~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

// // Read/Write
// // Create child process
// // Copy the file parent is using
// // Update as the parent updates
// // Child file will be appended as FILE_NAME.bak
// // If it exists, overwrite

// void shadow(char filename[])
// {
//   // Instantiate process id with a data type
//   pid_t pid;

//   // Creates child process
//   pid = fork();

//   // Compares the process being run
//   if (pid < 0)
//   {
//     /* Error:
//     *  When fork() returns -1, an error happened
//     *  (ex: number of processes reached the limit).
//     */
//     fprintf(stderr, "can't fork, error %d\n", errno);
//     exit(EXIT_FAILURE);
//   }
//   else if (pid == 0)
//   {
//     /* Child process:
//     *  When fork() returns 0, we are in the child process.
//     */
//     printf("Child 'shadow' process: ID %d\n\n", getpid());

//     // Shadow order code
//     FILE *fptr1, *fptr2;
//     char *fn = malloc(strlen(filename + 5));
//     char c;

//     // Open file you want to copy
//     fptr1 = fopen(filename, "r");

//     // If file does not exist, exit the program
//     if (fptr1 == NULL)
//     {
//       exit(0);
//     }

//     // Copied file will be appended w/ ".bak" towards the end
//     sprintf(fn, "%s.bak", filename);

//     // New .bak file will get ready to write, if it exists, overwrite
//     fptr2 = fopen(fn, "w+");

//     // If file does not exist, exit the program
//     if (fptr2 == NULL)
//     {
//       exit(0);
//     }

//     // Copy file
//     while ((c = fgetc(fptr1)) != EOF)
//     {
//       fputc(c, fptr2);
//     }

//     // Close files
//     fclose(fptr1);
//     fclose(fptr2);

//     // Free memory from malloc
//     free(fn);

//     exit(0); // Ends child process when done executing code
//   }
//   else
//   {
//     /* When fork() returns a positive number, we are in the parent process
//     *  (the fork return value is the PID of the newly created child process)
//     */
//     printf("\nParent 'shadow' process: ID %d\n", getpid());

//     wait(1); // Waits for child process to complete before progressing
//   }
// }

// /* ~~~~~~~~~~~~~~~~~~~~~~~ Exit Validation ~~~~~~~~~~~~~~~~~~~~~~~ */

// void exitValidation(char filename[])
// {
//   // Compares the user input to "0" and if it is, exit the program
//   if (strcmp(filename, "0") == 0)
//   {
//     printf("\nExiting program...\n\n");
//     exit(0);
//   }
// }