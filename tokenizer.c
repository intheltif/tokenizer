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
  line_count = ZERO; //starts line count at zero;
  int zero = ZERO;
  start = 1;
  int tok_size, tok_size2;
   while (fgets(input_line, LINE, in_file) != NULL){
      line = input_line;  // Sets a global pointer to the memory location
                           // where the input line resides.
      int i;
      int line_size = 0; //start counting with 1.
      int str1 = zero; //used to get first element in token.
      int reset = zero; //used to reset count to zero.
      if(line_count == ZERO){
          clear_token(token);
      }
      if(token[str1] == "/0"){
        if(line_count != ZERO){  
            printf("---------------------------------------------------------");
        }
        printf("Statement #%d", start);
      }
      i = 0;
      while(line_size < strlen(input_line)){
        tok_size1 = strlen(token);
        get_token(token);
        tok_size2 = strlen(token);
        if(tok_size1 < tok_size2){
            printf("Lexeme %d is %s\n", count, token[count]);
            count++;
        }
        line_size++;
      }
      line_count++;
      for(i = 0; i < strlen(token); i++){
        if(token[i] == ";"){
            start++;
            count = reset;
            break;
        }
      }
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
*
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
*/
void get_token(char *token_ptr){
    int i = 0;
    int j;
    int empty = strlen(token_ptr);
    get_non_White(line);
    char *holder;
    if(empty != 0){
        char *prvTok = token_ptr[empty-1];
        holder = line[i];
        while(line[i] == ('0'|'1'|'2'|'3'|'4'|'5'|'6'|'7'|'8'|'9') && i < strlen(line)){
            if(holder == prvTok){
              break;  
            }else{
                holder = strcat(holder, line[i]);
            }
            i++;
        }
        i++;
    }else if(empty == 0){
        i = 0;
    } 
    if(line[i] == ('0'|'1'|'2'|'3'|'4'|'5'|'6'|'7'|'8'|9')){
        holder = line[i];
        j = i + 1;
        while(line[j] == ('0'|'1'|'2'|'3'|'4'|'5'|'6'|'7'|'8'|9')){
            holder = strcat(holder,line[j];
            j++;
        }
    }else if(line[i] == "+"){
        token[empty] = line[i];    
    }else if(line[i] == "-"){
        token[empty] = line[i];
    }else if(line[i] == "*"){
        token[empty] = line[i];
    }else if(line[i] == "/"){
        token[empty] = line[i];
    }else if(line[i] == "("){
        token[empty] = line[i];
    }else if(line[i] == ")"){
        token[empty] = line[i];
    }else if(line[i] == "^"){
        token[empty] = line[i];
    }else if(line[i] == "="){
        if(line[i+1] == "="){
            token[empty] = "==";
        }else{
            token[empty] = line[i];
        }
    }else if(line[i] == "<"){
        if(line[i+1] == "="){
            token[empty] = "<=";
        }else{
            token[empty] = line[i];
        }
    }else if(line[i] == ">"){
        if(line[i+1] == "="){
            token[empty] = ">=";
        }else{
            token[empty] = line[i];
        }
    }else if(line[i] == "!"){
        if(line[i+1] == "="){  
            token[empty] = "!=";
        }else{
        token[empty] = line[i];
        }
    }else if(line[i] == ";"){
        token[empty] = line[i];
    }else{ 
        printf("===> %s\n", line[i]);
        printf("Lexical error: not a lexeme\n");
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


void get_non_white() {
    int i = 0;
    int j;
    while(i < strlen(line)){
        if(line[i] != " " && line[i] != "\n" && line[i] != "\0") {
            for(j = i; j < strlen(row); j++){
                line[j] = line[j+1];
            }
        }
        i++;
    }
}





