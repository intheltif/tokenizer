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
int valid; //Global booleen for it token is a lexeme.
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

  //Prints usage message if user doesn't provide correct input.
  if (argc != 3) {
    printf("Usage: tokenizer inputFile outputFile\n");
    exit(1);
  }

  /* The user specified input filename */
  in_file = fopen(argv[1], "r");
  if (in_file == NULL) {
    fprintf(stderr, "ERROR: could not open %s for reading\n", argv[1]);
    exit(1);
  }

  /* The user specified output filename */
  out_file = fopen(argv[2], "w");
  if (out_file == NULL) {
    fprintf(stderr, "ERROR: could not open %s for writing\n", argv[2]);
    exit(1);
  }
  /* Keeps track of the number of lines of input. */
  line_count = 0;
  /* Represents the current statement number. */
  start = 1;
  /* Amount of lexemes found in the current statement. */
  count = 0;
  /*Checks if this is the next statement. Used to check <=, ==, etc. */
  int next_stat = TRUE;
  /* A few counter variables. See their usage below. */
  int line_size, length, blank_line, size; 

   while (fgets(input_line, LINE, in_file) != NULL){
      
      line = input_line;  // Sets a global pointer to the memory location
                           // where the input line resides.

      //get's the number of spaces in a line.
      line_size = get_non_white(); 
      //gets the length of the current line of input.
      length = strlen(input_line);
      //if blank_line is zero then then line is just whitespace.
      blank_line = length - line_size;

      if((line_count == 0 || next_stat == TRUE)){ 
          clear_token(token);
      }
      //if next_stat is true and blank_line is not equal to 0, then prints.
      if(next_stat && blank_line != 0){  
        if(line_count != 0){  
            fprintf(out_file, "---------------------------------------------------------\n");
        }
        fprintf(out_file, "Statement #%d\n", start);
      }
      //While loop gets tokens of line and out puts info.
      while(!(isspace(*line)) && *line != '\0'){
        valid = TRUE;
        get_token(token);
        if(valid == TRUE){
            fprintf(out_file, "Lexeme %d is %s\n", count, token);
            size = strlen(token);//gets length of token
            while(size > 0){//if token is more than size of 0 resets token to 0.
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
        if(*token == ';'){//end of statment.
            start++;
            count = 0;
            next_stat = TRUE;
            break; 
        }else if(line_size >= length){ //line_size it greater the input_line
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
                    }//ends if.
                }//ends while.
            }//ends if.
        }//ends else.      
      }//ends while.
      line_count++;
   }//ends while.
   fclose(in_file);
   fclose(out_file);
   return 0;
}

/**
* Gets a single input token from the current line of input, and adds it to
* the array that holds the currently processed token.
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
 * @param token_ptr Token_ptr is the array that is being cleared.
 */
void clear_token(char *token_ptr){    
    int i = 0;
    while( i < TSIZE){
        *token_ptr = '\0';
        i++;
        token_ptr++;
    }
}

/*
 * This function increments the line pointer past any whitespace it finds,
 * thus making it easier to parse input. 
 *
 * @return the number of whitespace characters that were found.
 */
int get_non_white() { 
    int i = 0;
    while(isspace(*line)){
        i++;
        line++;
    }
    return i;
} 

