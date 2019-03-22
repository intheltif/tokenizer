/**
 * tokenizer.c - A simple token recognizer.
 *
 * NOTE: The terms 'token' and 'lexeme' are used interchangeably in this
 *       program.
 *
 * @author Evert Ball
 * @author Carley Yancey
 * @version 03/25/2019
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tokenizer.h"

// global variables
char *line;             // Global pointer to line of input

/**
* This is the main method for the toKenizer class.
*/
int main(int argc, char* argv[]) {
   char  token[TSIZE];      /* Spot to hold a token, fixed size */
   char  input_line[LINE];  /* Line of input, fixed size        */
   FILE  *in_file = NULL;        /* File pointer                     */
   FILE  *out_file = NULL;
   int   line_count,        /* Number of lines read             */
         start,             /* start of new statement           */
         count;             /* count of tokens                  */

  if (argc != 3) {
    printf("Usage: tokenizer inputFile outputFile\n");
    exit(1);
  }

  in_file = fopen(argv[1], "r");
  if (in_file == NULL) {
    fprintf(stderr, "ERROR: could not open %s for reading\n", argv[1]);
    exit(1);
  }

  out_file = fopen(argv[2], "w");
  if (out_file == NULL) {
    fprintf(stderr, "ERROR: could not open %s for writing\n", argv[2]);
    exit(1);
  }
 
   while (fgets(input_line, LINE, in_file) != NULL)
   {
      line = input_line;  // Sets a global pointer to the memory location
                           // where the input line resides.
      printf("Statement %d", statement_count);
      get_token(token);
      count++;
      printf("Token %d is %s\n", count, token);
      clear_token(token);
    
   }

   fclose(in_file);
   fclose(out_file);
   return 0;
}

/**
* Description
*
* @param token_ptr Token_ptr is the array that holds the token.
*/
void get_token(char *token_ptr){

    int i;
    char token[TSIZE];

    while(line != NULL) {

        j = 0;

        for(i = 0; i < strlen(line); i++) {

            if(line[i] != " " && line[i] != "\n" && line[i] != "\0") {

                switch(line[j]) {

                       case '+':
                            *token = line[j];
                            printf("Lexeme %i is +\n", i);
                            break;

                       case '-':
                            token = line[j];
                            printf("Lexeme %i is -\n", i);
                            break;

                       case '*':
                            token = line[j];
                            printf("Lexeme %i is *\n", i);
                            break;
                       case '/':
                            token = line[j];
                            printf("Lexeme %i is /\n", i);
                            break;
                       case '(':
                            token = line[j];
                            printf("Lexeme %i is (\n", i);
                            break;
                       case ')':
                            token = line[j];
                            printf("Lexeme %i is )\n", i);
                            break;
                       case '^':
                            token = line[j];
                            printf("Lexeme %i is ^\n", i);
                            break;
                       case '=':
                            if( line[j+1] == "=") {
                                token = "==";
                                printf("Lexeme %i is %s\n", i, token);
                                i++;
                                break;
                            } else {
                                token = line[j];
                                printf("Lexeme %i is %s\n", i, token);
                                break;
                            }
                       case '<':
                            if( line[j+1] == "=") {
                                token = "<=";
                                printf("Lexeme %i is %s\n", i, token);
                                i++;
                                break;
                            } else {
                                token = line[j];
                                printf("Lexeme %i is %s\n", i, token);
                                break;
                            }
                       case '>':
                            if( line[j+1] == "=") {
                                token = ">=";
                                printf("Lexeme %i is %s\n", i, token);
                                i++;
                                break;
                            }
                            else{
                                token = line[j];
                                printf("Lexeme %i is %s\n", i, token);
                                break;
                            }
                       case '!':
                            if( line[j+1] == "=") {
                                token = "!=";
                                i++;
                                break;
                            } else {
                                token = line[j];
                                break;
                            }
                       case [0-9]+:
                            
                            break;
                       case ';':
                            token = line[j];
                            break;
                    }
            }
            j++
        }
    }

}

/*
 * This clears the array of the current elements that are in the array.
 *
 * @param arr Arr is the array that is being cleared.
 */
void clear_token(char *arr){    
    int i;
    for(i = 0; i <= TSIZE - 1; i++){
        arr[i] = '\0';
    }
}



/*
 * This writes to a file and prints out the information about the token in a
 * certian statement.
 *
 * @param arr Arr is the array that is holding the tokens that will be printed.
 */
void printToken(char *arr){
    
}


void putThisSomewhere() {
}
