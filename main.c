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
void encriptSubstitution(char String1[], char sub[]);
void decripSubstitution(char String1[], char sub[]);



//----------------------------------------------------------------------------------------------------------------------------------
//TODO: scanf is currently being used as a debugger
//TODO: hard code file I/O, usese # to symbolise key
int main(){
    //Declare file pointers
    //FILE *Input;

    //Input = fopen("Input", "r");

    int menuChoice = 3;//This will be used to store users menu choice
    int key = 0;
    char String1[10000]={66,69,78};
    char Sub[26]={90,89,88,87,86,85,84,83,82,81,80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65};
    char waste[100];

    //fscanf(Input, "%d", &menuChoice);

    //fscanf(Input, "%d", &key);

    //fscanf(Input, "%[^\n]s", &String1);

    //fscanf(Input, "%s", &Sub);

    //scanf("%d\n", &menuChoice);
    //scanf("%d\n", &key);


    //Following changes strings to uppercase
    for(int count = 0; count<10000; count++){
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
        //Encryption of a message with a substitution cipher given message text and alphabet substitution
        case 3: encriptSubstitution(String1, Sub);
            break;
        //Decryption of a message encrypted with a substitution cipher given cipher text and substitutions
        case 4: decripSubstitution(String1, Sub);
            break;
        //Decryption of a message encrypted with a rotation cipher given cipher text only
        case 5:
            break;
        //Decryption of a message encrypted with a substitution cipher given cipher text only
        case 6:
            break;
        default:
            break;
    }
    //fclose(Input);
    return 0;
}

//----------------------------------------------------------------------------------------------------------------------------------
/**
This function executes code that takes static string input and encripts using cypher key.

*/

void encripRotation(char String1[], int key){
    //E(m) = (m+k)mod26
    for(int count = 0; count<10000; count++){
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
    int add = 0;
    for(int count = 0; count<10000; count++){
        if((String1[count]-65)-key<0){
            add = 26;
        }
        if(String1[count]>=65&&String1[count]<=90){
            String1[count] = 65+(((String1[count])-65)-key)%26 + add;
        }
        add = 0;
    }
    printf("%s", String1);
}
//----------------------------------------------------------------------------------------------------------------------------------
/**
This function executes code that takes static string input and encrips using substitution string.

*/
void encriptSubstitution(char String1[], char sub[]){

    for(int count = 0; count<10000; count++){
        switch (String1[count]-64){
        case 1: String1[count]=sub[0];
            break;
        case 2: String1[count]=sub[1];
            break;
        case 3: String1[count]=sub[2];
            break;
        case 4: String1[count]=sub[3];
            break;
        case 5: String1[count]=sub[4];
            break;
        case 6: String1[count]=sub[5];
            break;
        case 7: String1[count]=sub[6];
            break;
        case 8: String1[count]=sub[7];
            break;
        case 9: String1[count]=sub[8];
            break;
        case 10: String1[count]=sub[9];
            break;
        case 11: String1[count]=sub[10];
            break;
        case 12: String1[count]=sub[11];
            break;
        case 13: String1[count]=sub[12];
            break;
        case 14: String1[count]=sub[13];
            break;
        case 15: String1[count]=sub[14];
            break;
        case 16: String1[count]=sub[15];
            break;
        case 17: String1[count]=sub[16];
            break;
        case 18: String1[count]=sub[17];
            break;
        case 19: String1[count]=sub[18];
            break;
        case 20: String1[count]=sub[19];
            break;
        case 21: String1[count]=sub[20];
            break;
        case 22: String1[count]=sub[21];
            break;
        case 23: String1[count]=sub[22];
            break;
        case 24: String1[count]=sub[23];
            break;
        case 25: String1[count]=sub[24];
            break;
        case 26: String1[count]=sub[25];
            break;
        default: break;
        }
    }
    printf("%s", String1);
}
//----------------------------------------------------------------------------------------------------------------------------------
/**
This function executes code that takes static string input and decrips using substitution string.

*/
void decripSubstitution(char String1[], char sub[]){
    for(int count = 0; count<10000; count++){
        //if string1 is equal to a characte in sub, it becomes sub pointer + 65
        }
    }
    printf("%s", String1);
}
