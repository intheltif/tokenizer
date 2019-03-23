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
int valid;
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
  int tok_size1, tok_size2;
  clear_token(token);
   while (fgets(input_line, LINE, in_file) != NULL){
      line = input_line;  // Sets a global pointer to the memory location
                           // where the input line resides.
      int i;
      int line_size = get_non_white(); //start counting with 1.
      int str1 = zero; //used to get first element in token.
      int reset = zero; //used to reset count to zero.
      int count = 0;      
      if(line_count == ZERO){
          clear_token(token);
      }
      if(token[str1] == '\0'){
        if(line_count != ZERO){  
            printf("---------------------------------------------------------\n");
        }
        printf("Statement #%d\n", start);
      }
      i = 0;
      while(!(isspace(*line))){
         //line_size = get_non_white();
         valid = TRUE;
         get_token(token);
         if(line_size >= LINE){
             break;
         }
         if(valid == TRUE){
            printf("lexeme %d is %s\n", count, token);
            line_size++;         
         }
         if(valid == FALSE){
            printf("===> %c\n", *line);
            printf("Lexical error: not a lexeme\n");
            line_size++;
         }
         if(valid == TRUE){
             count++;
         }
         if(*token == ';'){
             start++;
             count = reset;
             clear_token(token);
             break;
         }else{
            *line++;
            if(line_size <= LINE){
                while(isspace(*line)){
                    *line++;
                    line_size++;
                    if(line_size <= LINE){
                        break;
                    }
                }
           }
         }      
      }
      line_count++;
        if(*token == ';'){
            start++;
            count = reset;
            clear_token(token);
            line_size = 0;
            break;
        }
     // }
      //clear_token(token);
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
    int i = 0;
    int empty = strlen(token_ptr);
    if(isdigit(*line)){
        *token_ptr = *line;
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
        if(*line++ == '='){
            *token_ptr = '=';
            *token_ptr++ = '=';
        }else{
            *token_ptr = *line;
        }
    } else if(*line == '<'){
        if(*line++ == '='){
            *token_ptr = '<';
            *token_ptr++ = '=';
        }else{
            *token_ptr = *line;
        }
    }else if(*line == '>'){
        if(*line++ == '='){
            *token_ptr = '>';
            *token_ptr++ = '=';
        }else{
            *token_ptr = *line;
        }
    }else if(*line == '!'){
        if(*line++ == '='){  
            *token_ptr = '!';
            *token_ptr++ = '=';
        }else{
            *token_ptr = *line;
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


int get_non_white() {
    int i = 0;
    while(isspace(*line)){
        i++;
        *line++;
    }
    return i;

}


    
         //while(line_size < strlen(input_line)){
        //tok_size1 = strlen(token);
        //get_token(token);
        //tok_size2 = strlen(token);
        //if(tok_size1 < tok_size2){
          //  printf("Lexeme %d is %c", count, token[count]);
           // if(token[count + 1] == '='){
             //   printf("=");
               // count++;
               
