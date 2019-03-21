/**
 * tokenizer.c - A simple token recognizer.
 *
 * NOTE: The terms 'token' and 'lexeme' are used interchangeably in this
 *       program.
 *
<<<<<<< HEAD
 * @author Carlee Yancey
 * @author Evert Ball
 * @version March 18, 2019
=======
 * @author Evert Ball
 * @author Carley Yancey
 * @version 03/25/2019
>>>>>>> c134f3da1af7af2b600cf33ed5b8508668b8f9cd
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

      // Add4 code here.
    
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
   // Add code here.
}

/*
 * This clears the array of the current elements that are in the array.
 *
 * @param arr Arr is the array that is being cleared.
 */
void clearTokens(char *arr){    
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



/**
 * A helper function that cycles through the current line untion it reaches a 
 * non-whitespace character.
 *
 */
void getNonWhitespace(){
    int i = 0;
    while(isspace(line[i])){
        //get next character
        i++;
    }
}

<<<<<<< HEAD
=======
/**
 * A helper function that cycles through the current line until it reaches a 
 * non-whitespace character.
 *
 */
void getNonWhitespace() {
    int i = 0;
    while(isspace(line[i])) {
        //get next character
        i++;
    }
}
>>>>>>> c134f3da1af7af2b600cf33ed5b8508668b8f9cd
