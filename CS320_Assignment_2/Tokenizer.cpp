#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include "Tokenizer.hpp"

Tokenizer::Tokenizer() {
    this->length = 0;
    this->capacity = 10;
    this->data = new int [this->capacity];
}

Tokenizer::Tokenizer(s) {
    this->length = 0;
    this->capacity = s;
    this->data = new int [this->capacity];
}

Tokenizer::~Tokenizer() {
    delete[] this->data;
}

int Tokenizer::numbers_only(char* s) {
    int i = 0;
	for(i = 0; i < strlen(s); i++){
		if(!isdigit(s[i])){
			return 0;
		}
	}
	return 1;
}

int Tokenizer::count_tokens(char* in) {
    int cmdline = 0;
	char part[256];
	int count = 0;
	int i = 0;
	while(cmdline < strlen(in)-1){
		sscanf(in+cmdline," %s %n",part,&i);
		cmdline += i;

		if(strlen(part) > 0){
			count++;
		}
	}
	return count;
}

void Tokenizer::print_all_token_types(char* in) {
    int cmdline = 0;
	int i = 0;
	char part[256];
	while(cmdline < strlen(in)-1){
		sscanf(in + cmdline," %s %n",part,&i);
		cmdline += i;
		if(strlen(part) > 0){
			if(!numbers_only(part))
			{
				printf("STR ");
			}
			else
			{
				printf("INT ");
			}
		}
	}
}

void Tokenizer::print_token_type(char *tkn) {
	if(strlen(tkn) > 0){
		if(!numbers_only(tkn))
		{
			printf("STR ");
		}
		else
		{
			printf("INT ");
		}
	}
}

int Tokenizer::get_token_type(char *tkn) {
	if(!numbers_only(tkn))
	{
		return STR_TOKEN;
	}
	else
	{
		return INT_TOKEN;
	}
}

void Tokenizer::get_token(char* in,char* out, int n) {
	int cmdline = 0;
	int i = 0;
	int tknnum = 0;
	while(cmdline < strlen(in)-1){
		sscanf(in + cmdline," %s %n",out,&i);
		cmdline += i;
		if(strlen(out) > 0){
			tknnum++;
			if(tknnum > n){
				return;
			}
		}
	}
}

