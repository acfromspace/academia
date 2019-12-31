# README.md

**CS 570 Summer 2018**<br>
**Names:** Josh Villanueva, Anthony Savitt, kingofthenorth<br>
**Class usernames:** cssc1074, cssc1067, & cssc1066 (respectively)

## Assignment #1, Deck of Cards w/ Multiple Threads

### Files manifest:

*4 files in total.*
```
a1.c
a1.h
makefile
README.md
```

### Description:
a1.c uses a main function and a thread_task function. Main creates STACK.txt, the semaphore FLAG, creates 4 threads using pthreads. Thread_task for each thread, grabs the semaphore opens STACK.txt and prints its corresponding suit and card based on the amount of times it has written to the file.

### To Compile:
Change directory to "a1", type "make".

### To Clean:
Change directory to "a1", type "make clean".

### To Operate:
Change directory to "a1", type "player".

### Design decisions:
We designed according to the homework. We each took turns trying to create the a1.c file, but we decided to split up the work via functions and files instead.

### Extra features:
N/A

### Known bugs:
No known bugs

### Lessons Learned:
How to use and implement semaphores. How to use and implement concurrent threads. Creating, opening, writing and closing a file in C. Dynamics of creating a makefile and the etiquette to creating one w/ proper variables.
