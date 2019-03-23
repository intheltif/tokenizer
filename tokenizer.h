/**
 * Header file for the tokenizer project 
 *
 * @author Carlee Yancey
 * @author Evert Ball
 * @version date
 */
/* Constants */
#define LINE 100
#define TSIZE 20
#define TRUE 1
#define FALSE 0

#define ZERO 0
/**
* add comment
*/
void get_token(char *);   

void printToken(char *);

void clear_token(char *);

void clear_line(char *);
void reset_line();
int get_non_white();
