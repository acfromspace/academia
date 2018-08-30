#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 65

int main(void) {
    // Header
    printf("Assignment #1-2, Andrew Christopher De Leon, andrewchristopherdeleon@gmail.com\n");

    char string[MAX];
    char *p;

    // take user input
    printf("> ");
    fgets(string, MAX, stdin);

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
