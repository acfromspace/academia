#include <stdio.h>
#include <string.h>
#define MAX 65

int main(void) {
    // Header
    printf("Assignment #1-1, Andrew Christopher De Leon, andrewchristopherdeleon@gmail.com\n");

    char string[MAX];
    char *p;

    fgets(string, MAX, stdin);

    p = strtok(string, " ");

    while (p != NULL) {
        printf("=%s=\n", p);
        p = strtok(NULL, " ");
    }

    return 0;
}
