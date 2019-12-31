#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <iostream>
#include <limits>

#define STR_TOKEN 1
#define INT_TOKEN 2

int numbers_only(char* s);
int count_tokens(char* in);
void print_all_token_types(char* in);
void print_token_type(char *tkn);
int get_token_type(char *tkn);
void get_token(char* in,char* out, int n);

int main(int argc,char **argv)
{
	char in[100];
	char token1[256],token2[256];
    int userMax;

    int counter = 0;
	int running = 1;

	printf("Assignment #2-1, kingofthenorth, kingofthenorth@gmail.com\n");

	while (running == 1) {
		printf("> ");
		fgets(in,66,stdin);
		if(strlen(in) > 65) { 
            printf("ERROR! Input string too long.\n");
        }
        else if(count_tokens(in) == 1)
            {
			    sscanf(in," %s ",token1);
			    if(strcasecmp("quit",token1) == 0)
                {
			    	running = 0;
			    }else{
			    	if(get_token_type(token1) == INT_TOKEN)
                    {
			    		printf("ERROR! Expected STR.\n");
			    	}else{
			    		print_token_type(token1);
			    		printf("\n");
			    	}
			    }
		    }else if(count_tokens(in) == 2){
			get_token(in,token1,0);
			get_token(in,token2,1);
			if(get_token_type(token1) == STR_TOKEN && get_token_type(token2) == INT_TOKEN){
				print_all_token_types(in);
				printf("\n");
			}else{
				printf("ERROR! Expected STR INT.\n");
			}
		}else{
			printf("ERROR! Incorrect number of tokens found.\n");
		}
	} // running is either 0 or 1, 1 is true, 0 is false, 0 is accomplished after "quit" is input

	return 0;
}

// Parse through and if it returns !isdigit, false
int numbers_only(char* s){
	int i = 0;
	for(i = 0; i < strlen(s); i++){
		if(!isdigit(s[i])){
			return 0;
		}
	}
	return 1;
}

// Parse through and count tokens separated by whitespace
int count_tokens(char* in){
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

// Returns counter for tokens
void get_token(char* in,char* out, int n){
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

// Prints string tokens as STR, int tokens as INT
void print_all_token_types(char* in){
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

// If token taken is either STR or INT, returns respective type
int get_token_type(char *tkn){
	if(!numbers_only(tkn))
	{
		return STR_TOKEN;
	}
	else
	{
		return INT_TOKEN;
	}
}

// Shows conversion for tokens
void print_token_type(char *tkn){
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
