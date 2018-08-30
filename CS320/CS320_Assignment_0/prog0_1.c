#include <stdio.h>
#define SPACE 50

int main(void) {
    char name[SPACE];
    char * ptr;

    // Header
    printf("Assignment #0-1, Andrew Christopher De Leon, andrewchristopherdeleon@gmail.com\n\n");

    // Program (Using fgets method)
    printf("What is your name?\n");
    ptr = fgets(name, SPACE, stdin);
    printf("Hello %s!", ptr);

    return 0;
}
