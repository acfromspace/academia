// a1.c

#include "a1.h"
#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>

FILE *fp;
sem_t FLAG;
pid_t pid;

int main( int argc, const char* argv[] ) {

  // Create file, print PID, close
  fp = fopen("STACK.txt","w");
  pid = getpid();
  fprintf(fp, "PID: %d\n", pid);
  fclose(fp);

  // Create semaphore
  sem_init(&FLAG, 0, 4);

  //array for thread ids
  int i[4];
  i[0] = 0;
  i[1] = 1;
  i[2] = 2;
  i[3] = 3;

  // Create threads
  pthread_t thread1;
  pthread_t thread2;
  pthread_t thread3;
  pthread_t thread4;
  pthread_create (&thread1, NULL, (void *) &thread_task, (void*) &i[0]);
  pthread_create (&thread2, NULL, (void *) &thread_task, (void*) &i[1]);
  pthread_create (&thread3, NULL, (void *) &thread_task, (void*) &i[2]);
  pthread_create (&thread4, NULL, (void *) &thread_task, (void*) &i[3]);

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
  pthread_join(thread3, NULL);
  pthread_join(thread4, NULL);

  sem_destroy(&FLAG);

  printf("Threads finished\n");

  return 0;
}

void thread_task(void * ptr){

  int thID;
  thID = *((int *) ptr);  //cast from thread ID from pointer to int

  int startDelay;
  char *suit = malloc(10);

// Set suit and time delay for each thread
  if(thID==1) {
    strcpy(suit,"Diamond");
    startDelay = 125000;
  }
  else if(thID==2) {
    strcpy(suit,"Club");
    startDelay = 250000;
  }
  else if(thID==3) {
    strcpy(suit,"Heart");
    startDelay = 500000;
  }
  else {
    strcpy(suit,"Spade");
    startDelay = 750000;
  }

  int i;
  for(i = 1;i <= 13;i++) {
      usleep(startDelay);
      sem_wait(&FLAG);
      fp = fopen("STACK.txt","a");

      switch(i){
        case 1:fprintf(fp,"%s A\n",suit);
          break;
        case 11:fprintf(fp, "%s J\n",suit);
          break;
        case 12:fprintf(fp, "%s Q\n",suit);
          break;
        case 13:fprintf(fp, "%s K\n",suit);
          break;
        default:fprintf(fp, "%s %d\n",suit,i);
          break;
    }

	  fprintf(stdout, "Thread %d is running\n", thID);
	  fclose(fp);
	  sem_post(&FLAG);

  }

    // Frees unused whitespaces to prevent memory leaks
    free(suit);

}
