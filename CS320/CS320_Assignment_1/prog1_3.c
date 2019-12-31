#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 65

int main(void) {
    // Header
    printf("Assignment #1-3, kingofthenorth, kingofthenorth@gmail.com\n");

    char string[MAX];
    char *p;
    int counter = 0;
    int foundLetter = 0;

    // take user input
    printf("> ");
    fgets(string, MAX, stdin);

    if (string[0] == ' ' || string[0] == '\n') {
        printf("ERROR! Incorrect number of tokens found.\n");

        int counter = 0;

        printf("> ");
        fgets(string, MAX, stdin);
    }

    for (int j = 0; j < strlen(string); j++) {
        if (string[j] == ' ') {
            foundLetter = 1;
        }
        else {
            // keeps track of whitespaces
            if (foundLetter == 1) {
                counter++;
            }
            foundLetter = 0;
        }

        if (counter > 1) {
            printf("ERROR! Incorrect number of tokens found.\n");

            int counter = 0;

            printf("> ");
            fgets(string, MAX, stdin);
        }
    }

    p = strtok(string, " ");

    // go through user input while not at the end
    while (p != NULL) {

        int cool = 0;
        
        // go through each character in a token
        for (int i = 0; i < strlen(p); i++) {
            if (isdigit(p[i])) {
                cool++;
            }
            else {
                break;
            }   
        }

        // final results after going through a token
        if (cool == strlen(p)) {   
            printf("INT ");
            p = strtok(NULL, " ");
        }
        else {
            printf("STR ");
            p = strtok(NULL, " ");
        }    
    }
    return 0;
}
