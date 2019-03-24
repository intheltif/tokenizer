Author: Carlee Yancey 
Author: Evertt Ball
Version: March 18, 2019

Project Two: A Lexer
input_errors.txt
output_errors.txt
tokenizer.c
tokenizer.h

This program is lexer. It takes in an input file and breaks down the lines 
into meaningful tokens. Then outputs to a file  showing the the tokens accepted 
or if there was an error with the token. 

#Usage 
To compile 
    gcc -Wall tokenizer.c -o tokenizer
 
To Run 
    ./tokenizer input_errors.txt output_erros.txt

#Output to a file

If there are no errors found.(Normal output)
    
    Statment #<number of Statment>
    Lexeme <number of Lexeme> is <the Token found>
    <Repeats until end of statment>
    ---------------------------------------------------------
    <Repeats if another statment is found>
    Statment #<number of Statment>
    Lexeme <number of Lexeme> is <the Token found>
    <Repeats until end of statment>

If there is an error found.(Error output)
     
     ==> <the token not reconized>
     Lexical error: not a lexeme
    <Repeats normal output until end of statment>


#Bugs 
Currently there are no bugs in this program.
