CS 320 Notes 02282017

How do I make data structures that grow?
    What do I do with memory when I''m done?
    // We have something that cleans up our garbage

What is a vector?
    An array that fits any # of elements.

What do we need?
    Resize.

Functions
    Set/get
    Add
    Clear/Remove
    Constructor // Initialize
    Size

Pass By Value
    The value of the thing is what you pass

******************************
#include <Stdio.h>
#include <stdlib.h>

struct ll {
    struct ll* list;
}

int main()
{
    struct ll head;
    struct ll *next;
    struct ll *cur;
    cur = &head;
    for(;;) {
        cur -> list = (struct ll*)malloc(sizeofstruct ll));
        cur = cur->list;
        free(cur);
        cur = next;
    }
}
******************************
vector.c

#include "vector.h"
#include <stdlib.h>

struct vector CreateVector() {
    struct vector NewVec;
    NewVec.length = 0; // # user has added
    NewVec.capacity = 50; // # one can put in the container
    NewVec.data = (int*) malloc (sizeof(int)*NewVec.capacity);
    return NewVec;
}

void VectorAdd(struct vector *Vec, int d) {
    if(Vec->length >= Vec->capacity) {
        //Don't have enough space
        int *ptr = (int*)malloc(sizeof(int)*Vec->capacity*2);
        // -> means follow this
        for (int i = 0; i < Vec->length; i++) {
            ptr[i] = Vec->data[i];
        }
        free(Vec->data);
        Vec->data = ptr;
        Vec->capacity = Vec->capacity * 2;
        }
    }
    Vec->data[Vec.length] = d;
    Vec->length++;
}

void VectorSet(struct vector Vec,int idx, int d) {

}
******************************
vector.h

#include

struct vector {

}
******************************
main.c

#include <stdio.h>
#include "vector.h"

int main()
{
    struct vector MyVector;
}

ADDTIONAL NOTES IN PHONE

ASSIGNMENT 2 *********************************************

#include <vector> is your best friend
It''s in C++