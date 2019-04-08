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

void encripRotation(char String1[], int key);
void decripRotation(char String1[], int key);


//----------------------------------------------------------------------------------------------------------------------------------
//TODO: scanf is currently being used as a debugger
//TODO: hard code file I/O, usese # to symbolise key
int main(){
    int menuChoice = 1;//This will be used to store users menu choice
    int key = 2;
    char String1[100];
    //scanf("%d\n", &menuChoice);
    //scanf("%d\n", &key);
    scanf("%[^\n]s", &String1);

    //Following changes strings to uppercase
    for(int count = 0; count<100; count++){
        if(String1[count]>=97&&String1[count]<=122){
            String1[count] = String1[count] - 32;
        }
    }

    //Switch Statement
    switch(menuChoice){

        //Encryption of a message with a rotation cipher given the message text and rotation amoun
        case 1: encripRotation(String1, key);
            break;
        //Decryption of a message encrypted with a rotation cipher given cipher text and rotation amount
        case 2: decripRotation(String1, key);
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

void encripRotation(char String1[], int key){
    //E(m) = (m+k)mod26
    for(int count = 0; count<100; count++){
        if(String1[count]>=65&&String1[count]<=90){
            String1[count] = 65+(((String1[count])-65)+key)%26;
        }
    }
    printf("%s", String1);
}
//----------------------------------------------------------------------------------------------------------------------------------
/**
This function executes code that takes static string input and decripts using cypher key.

*/
void decripRotation(char String1[], int key){
    //E(m) = (m+k)mod26
    for(int count = 0; count<100; count++){
        if(String1[count]>=65&&String1[count]<=90){
            String1[count] = 65+(((String1[count])-65)-key)%26;
        }
    }
    printf("%s", String1);
}
