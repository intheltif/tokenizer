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

#include <ctype.h>
// global variables
char *line;             // Global pointer to line of input
int valid;
/**
* This is the main method for the tokenizer class.
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

  line_count = 0;; //starts line count at zero;
  start = 1;
  count = 0;
  int next_stat = TRUE;
  int line_size, length, same, size; 
   while (fgets(input_line, LINE, in_file) != NULL){
      
      line = input_line;  // Sets a global pointer to the memory location
                           // where the input line resides.

      //get's the number of spaces in a line
      line_size = get_non_white(); 
      //gets the length of the current line of input
      length = strlen(input_line);
      //what is same? maybe change this var name
      same = length - line_size;

      if((line_count == 0 || next_stat == TRUE)){ //next_stat is the next statement
          clear_token(token);
      }
      
      if(*token == '\0' && same != 0){
        if(line_count != 0){  
            fprintf(out_file, "---------------------------------------------------------\n");
        }
        if(next_stat){
            fprintf(out_file, "Statement #%d\n", start);
        }
      }
      while(!(isspace(*line)) && *line != '\0'){
         valid = TRUE;
         get_token(token);
         if(valid == TRUE){
            fprintf(out_file, "lexeme %d is %s\n", count, token);
            size = strlen(token);
            while(size > 0){
                token[size]= '\0';
                size--;
            }
            line_size++;
            count++;         
         }
         if(valid == FALSE){ 
            if(*line != '\0'){
                fprintf(out_file, "===> '%c'\n", *line);
                fprintf(out_file, "Lexical error: not a lexeme\n");
            }
            line_size++;
         }
         if(*token == ';'){
            start++;
            count = 0;
            next_stat = TRUE;
            break; 
         }else if(line_size >= length){
             break;
         }else{
            line++;
            next_stat = FALSE;
            if(line_size < length){
                while(isspace(*line)){
                    line++;
                    line_size++;
                    if(line_size < length && !(isspace(*line))){
                        break;
                    }else if(line_size > length && !(isspace(*line))){
                        break;
                    }else if(line_size > length){
                        break;
                    }
                }
           }
         }      
      }
      line_count++;
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
    valid = TRUE;
    if(isdigit(*line)){
        *token_ptr = *line;
        line++;
        while(isdigit(*line)){
            token_ptr++;
            *token_ptr = *line;
            line++;
        }
        if(!(isdigit(*line))){
            line--;
        }
    }else if(*line == '+'){ 
        *token_ptr = *line;
    }else if(*line == '-'){
        *token_ptr = *line;
    }else if(*line == '*'){
        *token_ptr = *line;
    }else if(*line == '/'){
        *token_ptr = *line;
    }else if(*line == '('){
        *token_ptr = *line;
    }else if(*line == ')'){
        *token_ptr = *line;
    }else if(*line == '^'){
        *token_ptr = *line;
    }else if(*line == '='){
        *token_ptr = *line;
        line++;
        if(*line == '='){
            token_ptr++;
            *token_ptr = *line; 
        }
        else{
            line--;
        }
    } else if(*line == '<'){
        *token_ptr = *line;
        line++;
        if(*line == '='){
            token_ptr++;
            *token_ptr = *line; 
        }
        else{
            line--;
        }
    }else if(*line == '>'){
        *token_ptr = *line;
        line++;
        if(*line == '='){
            token_ptr++;
            *token_ptr = *line; 
        }
        else{
            line--;
        }
    }else if(*line == '!'){
        *token_ptr = *line;
        line++;
        if(*line == '='){  
            token_ptr++;
            *token_ptr = *line; 
        }
        else{
            line--;
        }
    }else if(*line == ';'){
        *token_ptr = *line;
    }else{
        valid = FALSE; 
    }
}

/*
 * This clears the array of the current elements that are in the array.
 *
 * @param arr Arr is the array that is being cleared.
 */
void clear_token(char *token_ptr){    
    int i = 0;
    while( i < TSIZE){
        *token_ptr = '\0';
        i++;
        token_ptr++;
    }
}


void clear_line(char *row){
}
/*
 * This writes to a file and prints out the information about the token in a
 * certian statement.
 *
 * @param arr Arr is the array that is holding the tokens that will be printed.
 */
void printToken(char *arr){
    
}


int get_non_white() { 
    int i = 0;
    while(isspace(*line)){
        i++;
        line++;
    }
    return i;

} 

void reset_line(){
}
