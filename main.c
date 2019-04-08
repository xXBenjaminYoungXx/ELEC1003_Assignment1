/*
User: Benjamin Young
Student ID: c3330653
Email: BenjaminYoung7198@gmail.com
NOTE: The code has been editted on codeblocks and committed on github
-UPPERCASE should be only input, (ADV: turn all cases into uppercase if lower case detected.)
-
Method List:


note if stdio is used loss of marks will occur
TODO: Use common comments and pseudo to structure program
TODO: Use functions to run respective menu options, and functions within those
to execute code required to encript/decript information.
*/

#include <stdio.h>

//----------------------------------------------------------------------------------------------------------------------------------

void encripRotation();


//----------------------------------------------------------------------------------------------------------------------------------

int main(){

    int menuChoice = 0;//This will be used to store users menu choice

    //TODO: scanf is currently being used as a debugger
    //TODO: hard code file I/O, usese # to symbolise key
    scanf("%d", &menuChoice);

    //Switch Statement
    switch(menuChoice){

        //Encryption of a message with a rotation cipher given the message text and rotation amoun
        case 1: encripRotation();
            break;
        //Decryption of a message encrypted with a rotation cipher given cipher text and rotation amount
        case 2:

            break;
        case 3://Encryption of a message with a substitution cipher given message text and alphabet substitution

            break;
        case 4://Decryption of a message encrypted with a substitution cipher given cipher text and substitutions

            break;
        case 5://Decryption of a message encrypted with a rotation cipher given cipher text only

            break;
        case 6://Decryption of a message encrypted with a substitution cipher given cipher text only

            break;
        default:

            break;
    }

    return 0;
}

//----------------------------------------------------------------------------------------------------------------------------------
/**
This function executes code that takes static string input and encripts using cypher key.

*/

void encripRotation(char String1[]){
    int cypherKey = 0;
    char String1[100];

    scanf("%d\n", &cypherKey);
    scanf("%[^\n]s", &String1);


}


