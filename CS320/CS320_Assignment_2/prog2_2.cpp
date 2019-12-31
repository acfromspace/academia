#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <iostream>
#include <limits>
#include "Tokenizer.cpp"
#include "Tokenizer.hpp"

#define STR_TOKEN 1
#define INT_TOKEN 2

int main(int argc,char **argv)
{
	char in[100];
	char token1[256],token2[256];
    int userMax;

    int counter = 0;
	int running = 1;

	printf("Assignment #2-2, kingofthenorth, kingofthenorth@gmail.com\n");

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
