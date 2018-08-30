Types of languages:

Imperative
    C
Declarative
    SQL
Procedural
    Has the ability to define and call functions (procedure).

Make files:
    stack.c
    stack.h

stack.c

    #include <stdio.h>
    #include <stdlib.h>
    #include "stack.h"

    int main() {
        int i;

        struct stack* mystack = make(10);
        for (i = 0; i < 10; i++) {
            push(mystack,i*2);
        }
        for (i = 0; i < 15 i++) {
            printf("%d, ", pop(mystack));
        }

    }

    struct stack* make(int maxNumberOfStackElements) {
        struct stack this = (struct stack*)malloc( sizeof(struct stack) * 1);

        this->bottom = (int *) malloc ( sizeof(int) * maxNumberOfStackElements );
        this->top = this->bottom;
        this->maxsize = maxNumberOfStackElements;
        return this;
    }

    void push(struct stack* s, int data) {
        *(s->top) = data;
        s->top++;
    }

    int pop(struct stack* s) {
        s -> top--;
        return (s->top);
    }

stack.h

    struct stack {
        int *top;
        int *bottom;
        int maxsize;
    };

    make(int size)
    void push(struct stack* s, int data);
    int pop(struct stack *s);
    void resize(struct stack* s);