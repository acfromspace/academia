Parse - Breaking up a document into potential meaningful components
    look at wow !that >> Wow look at that!

Token - A potentially meaningful chunk (quit)
    int x=3; (the equals sign splits)

Function Prototypes - A declaration of what function will look like when it is found.

prog1_1.c

    // string tokenizer

    char in[66]; // null terminator creates it +1 (just max out to not corrupt buffer)
    char token[256]; // 256 is safest bet
    int counter = 0;

    scanf("%65[\n]s", in); // only reads 65 characters

    fgets(in, 65, stdin); // actually reads 66 which include null terminator

    sscanf(int counter, "_%s_%n", token, &counter); // the _ means ignore all whitespace, so put before and after, %s
                                                 // token just has "hello" if typed in _ _ hello _ _ _ world

    printf("=%s=\n", token);

    char c = getch(); // get char
    if (c != ' ')
    {
        in[i] = c;
    }

hm?

    int ctr;
    int* ptr; // defines the pointer
    ptr = &ctr; // pointer points to the address
    *ptr = 3; // ptr = ctr's value

> gcc prog1_6.c -o prog1_6
> ./prog1_6 3 Hello world "dog and cat"

argv 2 -> 3
argv 3 -> hello
argv 4 -> world
argv 5 -> "dog and cat"

How to make modular functions in C?

int doubler(int x); // put all of your function prototypes to test.h (HEADER FILE)

#include "test.h"

int main(_)
{
    // function calls
    printf("%d\n", doubler(3));
}

int doubler (int x)
{
    return x * 2;
}

files:
    test.c
    test.h
    lib.c // put functions here (not function prototype)
(Use xed "name of program" to create a new file in the editor)

KISS
    keep it simple stupid