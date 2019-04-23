/*
User: Benjamin Young
Student ID: c3330653
Email: BenjaminYoung7198@gmail.com
NOTE: The code has been editted on codeblocks and committed onto github
//-------------------------------------------------------------------------------------------------------------------------------------
Program User Interface:(repeated in Input file)
 Menu options done through header file Menu.h:
    -Rotation:
        Enter (1) to encript message
        Enter (2) to decript message
    -Substitution:
        Enter (3) to encript message
        Enter (4) to decript message
    -Rotation no key:
        Enter (5) to decrypt
 The Input file data needs to be formated as follows:
1       #[ROTATION KEY]
2       [TEXT TO BE TRANSLATED]
3       [SUBSTITUTION KEY]

    Rotation Key:
    -Can be any integer. Will be moded by 26 and made positive

    Substitution key:
    -The substitution key needs to be exactly 26 characters long, can be upper or lowercase.
    -Should include one of every character in the alfabet, and no spaces.
    -Characters replace respective characters of standard alphabetical order.

    Cipher text:
    -The cipher text can be upto 10,000 charactes long, and can be upper or lower case.
    -Will always be printed in uppercase

    OUTPUT:
    -Printed in file Output and on terminal
//--------------------------------------------------------------------------------------------------------------------------------
Program Description:
    The Program requires the following header files:
        -stdio.h
        -string.h
        -Menu.h
            This headder file contains the function 'menu' at which requests the user input shown above
    Function/Method List:
        -int main()
            -The main function initialises Input file, reads data. Any strings containing lowercase letters
            are then modified such that the letters are capitalised. Rotation key is moddified to remain within
            0-25 range.

            -menu() (Menu.h) is then executed within switch condition, at which it returns an
            integer corresponding to the users input.

            -The returned integer is then pased through the switch statement that executes the respective function

        -void encrypRotation(char String1[], int key);
            -Takes String 'String1', which is the read string from Input file
            -Takes rotation key, which is an integer representing the rotaion of the cipher
            -Output file is initialised here.
            -All char values within 'String1' are modified accordingly to the key value
            -Resulting String is printed to terminal

        -void decrypRotation(char String1[], int key);
            -Takes same arguments as encrypRotation.
            -Output file is initialised here.
            -All char values within 'String1' are modified accordingly to the key value,
             however this is done in reverse to the encrypRotation function.
            -Resulting String is printed to terminal.


*/

#include <stdio.h>
#include <string.h>
#include "Menu.h"

//----------------------------------------------------------------------------------------------------------------------------------

void encrypRotation(char String1[], int key);
void decrypRotation(char String1[], int key, int itter);
void encryptSubstitution(char String1[], char sub[]);
void decrypSubstitution(char String1[], char sub[]);
void decrypRotNoKey(char String1[]);

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
        case 1: encrypRotation(String1, key);
            break;
        //Decryption of a message encrypted with a rotation cipher given cipher text and rotation amount
        case 2: decrypRotation(String1, key, 1);
            break;
        //Encryption of a message with a substitution cipher given message text and alphabet substitution
        case 3: encryptSubstitution(String1, Sub);
            break;
        //Decryption of a message encrypted with a substitution cipher given cipher text and substitutions
        case 4: decrypSubstitution(String1, Sub);
            break;
        //Decryption of a message encrypted with a rotation cipher given cipher text only
        case 5: decrypRotNoKey(String1);
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

void encrypRotation(char String1[], int key){
    //E(m) = (m+k)mod26
    FILE *Output;
    Output = fopen("Output", "w");
    for(int count = 0; count<10000; count++){
        if(String1[count]>=65&&String1[count]<=90){
            String1[count] = 65+(((String1[count])-65)+key)%26;
        }
    }
    printf("Encryption: \n");
    printf("%s\n", String1);
    fprintf(Output, "%s", String1);
}
//----------------------------------------------------------------------------------------------------------------------------------
/**
This function executes code that takes static string input and decripts using cypher key.

*/
void decrypRotation(char String1[], int key, int itter){
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
    printf("Decryption: \n");
    printf("%s\n", String1);
    if(itter==1){
        fprintf(Output, "Decription:\n%s", String1);
    }
}
//----------------------------------------------------------------------------------------------------------------------------------
/**
This function executes code that takes static string input and encrips using substitution string.

*/
void encryptSubstitution(char String1[], char sub[]){
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
    printf("Encryption: \n");
    printf("%s\n", String1);
    fprintf(Output, "%s", String1);
}
//----------------------------------------------------------------------------------------------------------------------------------
/**
This function executes code that takes static string input and decrips using substitution string.

*/
void decrypSubstitution(char String1[], char sub[]){
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
    printf("Decryption: \n");
    printf("%s\n", String1);
    fprintf(Output, "%s", String1);
}
//----------------------------------------------------------------------------------------------------------------------------------
/**
This function executes code that takes static string input and decrips through rotation method.

*/
void decrypRotNoKey(char String1[]){
    //To do this find most common letter, then suggest its e, apply same rotation to other texts
    int key = 0;
    int key2 = 0;
    int alphabet[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    char alphabetChar[26] = {65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90};
    int biggest = 0;
    int biggest2 = 0;
    int biggestCount=0;
    int biggestCount2 = 0;
    for(int count = 0; count<=strlen(String1); count++){
        switch (String1[count]-64){
        case 1: alphabet[0]+=1;
            break;
        case 2: alphabet[1]+=1;
            break;
        case 3: alphabet[2]+=1;
            break;
        case 4: alphabet[3]+=1;
            break;
        case 5: alphabet[4]+=1;
            break;
        case 6: alphabet[5]+=1;//
            break;
        case 7: alphabet[6]+=1;
            break;
        case 8: alphabet[7]+=1;
            break;
        case 9: alphabet[8]+=1;
            break;
        case 10: alphabet[9]+=1;
            break;
        case 11: alphabet[10]+=1;
            break;
        case 12: alphabet[11]+=1;
            break;
        case 13: alphabet[12]+=1;
            break;
        case 14: alphabet[13]+=1;
            break;
        case 15: alphabet[14]+=1;
            break;
        case 16: alphabet[15]+=1;
            break;
        case 17: alphabet[16]+=1;
            break;
        case 18: alphabet[17]+=1;
            break;
        case 19: alphabet[18]+=1;
            break;
        case 20: alphabet[19]+=1;
            break;
        case 21: alphabet[20]+=1;
            break;
        case 22: alphabet[21]+=1;
            break;
        case 23: alphabet[22]+=1;
            break;
        case 24: alphabet[23]+=1;
            break;
        case 25: alphabet[24]+=1;
            break;
        case 26: alphabet[25]+=1;
            break;
        default: break;
        }
    }
    //Now to see which was highest count
    for(int count = 0; count<26;count++){
        if(alphabet[count]>biggest){
            biggest2 = biggest;
            biggestCount2 = biggestCount;
            biggest = alphabet[count];
            biggestCount = count;
        }
        else if(alphabet[count]>=biggest2){
            biggest2 = alphabet[count];
            biggestCount2 = count;
        }
    }
    for(int count = 0; count<26; count++){
        if(biggestCount == count){//if 0 is biggest, A is most common, hence key == 4//if 1 is beiggest B is most common, hence key == 3//if 5 e is common key = 0, if f is common key =25
            key = alphabetChar[count]-69;//0-22,1-23,2-24,3-25,4-0,5-1, diffrence
        }
        if(biggestCount2 == count){
            key2 = alphabetChar[count]-69;
        }
    }
    if(key<0){
        key = key + 26;
    }
    if(key2<0){
        key2 = key2 + 26;
    }

    char String2[10000];

    for(int count = 0; count<strlen(String1);count++){
        String2[count] = String1[count];
    }
    decrypRotation(String1,key, 1);
    printf("Decryption attempt 2:\n\n");
    decrypRotation(String2,key2, 2);
}

