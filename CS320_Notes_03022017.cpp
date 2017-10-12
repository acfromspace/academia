b.

#include "Tokenizer.hpp"

int main() {
    Tokenizer facetstring* vals = foo.GetTokens();
}

vals will be pointing to two elements
1. non-null string -> "Hello"
2. non-null integer -> "3"

Stack program will use
    g++ prog2_3.cpp Tokenizer.cpp Stack.cpp -o prog2_3

Vector is going to need:
    POINTER to elements (array of those elements)
    LENGTH capacity
    ADD put element at end (resize internal array)
    REMOVE from a particular index (expensive)
    SET set value for particular index
    GET get value

Deconstructors delete the unneeded memory

5 files, vector.hpp, vector.cpp, vector.c, main.cpp, main.c

vector.hpp **********

class vector {
    private:
        int *data;
        int length;
        int capacity;
    public:
        vector(); // constructor
        vector(int c);
        ~vector();
        void Add(int d);
        int Remove(int idx);
        void set(int idx, int d);
        int get(int idx);
        int size();
}

vector.cpp **********

vector::vector() {
    this->length = 0;
    this->capacity = 10;
    this->data = new int [this->capacity];
    // we use 'new' instead of malloc since it is c++
}

vector::vector(c) {
    this->length = 0;
    this->capacity = c;
    this->data = new int [this->capacity];
    // we use 'new' instead of malloc since it is c++
}

vector::~vector() {
    delete[] this->data;
}

void vector::Add(int d) {
    if(this->lgenth >= this->capacity) {
        // make bigger
        int * data = new int [this->capacity*2];
        for(int i = 0; i < this->length; i++) {
            data[i] = this->data[i];
        }
        delete this->data;
        this->data = data;
        this->capacity = this->capacity*2;
    }
    this->data[this->length] = d;
    this->length++;
}

int vector::remove(int idx) {
    if(idx < 0 || idx >= this->length) {
        return;
    }
    int val = this->data[idx];
    for(int i = idx; i < this->length; i++) {
        this->data[i] = this->data[i+1];
    }
    this->length--;
    return val;
}

vector::set(int idx, int d) {
    if(idx < 0 || idx >= this->length) {
        return;
        // return bails out of the whole function
    }

    this->data[idx] = d;
}

vector::get(int idx) {
    if(idx < 0 || idx >= this->length) {
        return -1;
        // return bails out of the whole function
    }
    return this->data[idx];
}

int vector

vector.c ********** // in phone notes, c program

main.cpp **********
#include "vector.hpp"
#include <iostream>

using namespace std;

int main() {
    vector vec();

    for(int i = 0; i < 10; i++) {
        vec.Add(i*2);
    }
    vec.set(0,3);
    // if vec is the first argument to set then the other arguments are 0, 3
    for(int i = 0; i < vec.size(); i++) {
        cout << vec.get(i) << endl;
    }
    // 3 errors
}

**************************************************************
BASH BACK TO LUA