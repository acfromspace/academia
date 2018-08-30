stack.h ****************************************************************************************************

stack.c ****************************************************************************************************

#include <stdlib.h>
#include "Stack.h"

int main()
{
    char buff[256];
    struct stack* mystack = make(10);
    fgets(buff, 256, stdin);
    numtok = counttokens(buff);
    mytokens = gettokens(buff);

    printf("nt: %d\n", numtok);

    for(int i = 0; i < numtok; i++) {
        printf("%s\n", mytokens[i]);
    }

    printstack(mystack);

****************************************************************************************************
    char **mytokens;

    struct stack* mystack = make(10);
    while(1) {
        mytokens = get2tokens();

        if(strcasecmp(mytokens[0],"push") == 0) {
            push(mystack,atoi(mytokens[1]));
        }

        printstack(mystack);
    }
****************************************************************************************************
}

void printstack(struct stack* s) {
    int *cur = s->bottom;
    while(cur != s-> {
        printf("%d ", *cur)
        cur++;
    })
}

struct stack* make(int maxNumberOfStackElements) {
    struct stack this = (struct stack*)malloc( sizeof(struct stack) * 1);

    this->bottom = (int *) malloc ( sizeof(int) * maxNumberOfStackElements );
    this->top = this->bottom;
    this->maxsize = maxNumberOfStackElements;
    return this;
}

inputhelpers.h ****************************************************************************************************

int counttokens(char* line)
char** gettokens(char* line)

inputhelpers.c ****************************************************************************************************

#include "inputhelpers.h"
#include <string.h>
#include <stdlib.h>

int counttokens(char* line) {
    char buff[256];
    char *token;
    int count = 0;

    strcpy(buff, line);
    token = strtok(buff, " ");

    while (token != NULL) {
        count++;
        token = strtok(null, " ");
    }

    return count;
}

char** gettokens(char* line) {
    char *buff = (char*) malloc(sizeof(char) * 256; // buff points at char
    strcpy(buff, line);

    int size = counttokens(line);
    char **tokens = (char **) malloc(sizeof(char) * size); // tokens points at char pointers

    while (int i = 0; i < size; i++) {
        if(i == 0) {
        tokens[i] = strtok(buff, " ");
        } else {
            tokens[i] = strtok(NULL, " ");
        }
    }

    return tokens;
}

char** get2tokens() {
    char line[256];
    int numtok;
    do {
        printf("> ");
        fgets(line, 256, stdin);
        line[strlen(line)-1] = 0;

        numtok = countTokens(line);
    } while(numtok != 2);

    return gettokens(line);
}

char** getSTR_INTtokens() {
    char **tokens;
    do {
        tokens = get2tokens();
        if(numbersonly(tokens[0]) == 0 && numbers_only(tokens[1]) == 1) {
            return tokens;
        }
    while(1);
    }
}

int numbers_only(char* s) {
    while(*s != NULL) {
        if(!isdigit(s)) {
            return 0;
        }
        s++;
    
    return 1;}
}

*************************************** gcc file1 file2 file3 (compile together)