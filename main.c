/*
User: Benjamin Young
Student ID: c3330653
Email: BenjaminYoung7198@gmail.com
NOTE: The code has been editted on codeblocks and committed onto github
Method List:


note if stdio is used loss of marks will occur
TODO: Use common comments and pseudo to structure program
TODO: Use functions to run respective menu options, and functions within those
to execute code required to encript/decript information.
*/

#include <stdio.h>
#include <string.h>
#include "Menu.h"

//----------------------------------------------------------------------------------------------------------------------------------

void encripRotation(char String1[], int key);
void decripRotation(char String1[], int key);
void encriptSubstitution(char String1[], char sub[]);
void decripSubstitution(char String1[], char sub[]);
void decripRotNoKey(char String1[]);

//----------------------------------------------------------------------------------------------------------------------------------

int main(){
    //Declare file pointers
    FILE *Input;
    //Associating "Input" with input file as a refrence
    Input = fopen("Input", "r");
    //Variables are declared
    int key;
    char String1[10000];//Texts to be translated
    char Sub[27];//Key for substitution encription/decription
    char waste;//Used as a way to tet i/o working
    //Input /File input
    //printf("Rotation:\nEnter (1) to encript message\nEnter (2) to decript message\nSubstitution:\nEnter (3) to encript message\nEnter (4) to decript message\n");
    //scanf("%d", &menuChoice);
    fscanf(Input, "%c", &waste);
    fscanf(Input, "%d", &key);
    fscanf(Input, "%c", &waste);
    fgets(String1, 10000, Input);
    fgets(Sub, 27, Input);
    /*printf("%d\n", menuChoice);
    printf("%d\n", key);
    printf("%s", String1);
    printf("%s\n", Sub);*/
    //Following changes 'string1' to uppercase
    for(int count = 0; count<10000; count++){
        if(String1[count]>=97&&String1[count]<=122){
            String1[count] = String1[count] - 32;
        }
    }
    //Following changes 'Sub' to uppercase
    for(int count = 0; count<27; count++){
        if(Sub[count]>=97&&Sub[count]<=122){
            Sub[count] = Sub[count] - 32;
        }
    }
    //Allows key inputs above 26
    key = key%26;

    if(key<0){
        key = key + 26;
    }
    //Switch Statement to determine which function to run
    switch(menu()){
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
    FILE *Output;
    Output = fopen("Output", "w");
    for(int count = 0; count<10000; count++){
        if(String1[count]>=65&&String1[count]<=90){
            String1[count] = 65+(((String1[count])-65)+key)%26;
        }
    }
    printf("Encription: \n");
    printf("%s", String1);
    fprintf(Output, "%s", String1);
}
//----------------------------------------------------------------------------------------------------------------------------------
/**
This function executes code that takes static string input and decripts using cypher key.

*/
void decripRotation(char String1[], int key){
    //E(m) = (m+k)mod26
    FILE *Output;
    Output = fopen("Output", "w");
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
    printf("Decription: \n");
    printf("%s", String1);
    fprintf(Output, "%s", String1);
}
//----------------------------------------------------------------------------------------------------------------------------------
/**
This function executes code that takes static string input and encrips using substitution string.

*/
void encriptSubstitution(char String1[], char sub[]){
    FILE *Output;
    Output = fopen("Output", "w");
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
    printf("Encription: \n");
    printf("%s", String1);
    fprintf(Output, "%s", String1);
}
//----------------------------------------------------------------------------------------------------------------------------------
/**
This function executes code that takes static string input and decrips using substitution string.

*/
void decripSubstitution(char String1[], char sub[]){
    FILE *Output;
    Output = fopen("Output", "w");
    for(int count = 0; count<strlen(String1); count++){
        //if string1 is equal to a character in sub, it becomes sub pointer + 65
        for(int count2 = 0; count2<26; count2++){
            if(String1[count]==sub[count2]){
                String1[count]=count2 + 65;
                count2 =100;
            }
        }
    }
    printf("Decription: \n");
    printf("\n%s", String1);
    fprintf(Output, "%s", String1);
}
//----------------------------------------------------------------------------------------------------------------------------------
/**
This function executes code that takes static string input and decrips through rotation method.

*/
void decripRotNoKey(char String1[]){

}

