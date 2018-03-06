#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

class Tokenizer {
    private:
        int *data;
        int length;
        int capacity;
    public:
        Tokenizer();
        Tokenizer(int s);
        ~Tokenizer();
        int numbers_only(char* s);
        int count_tokens(char* in);
        void print_all_token_types(char* in);
        void print_token_type(char *tkn);
        int get_token_type(char *tkn);
        void get_token(char* in,char* out, int n);
}
