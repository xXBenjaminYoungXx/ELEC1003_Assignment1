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
        -Should include one of every character in the alphabet, and no spaces.
        -Characters replace respective characters of standard alphabetical order.

    Cipher text:
        -The cipher text can be upto 10,000 charactes long, and can be upper or lower case.
        -Will always be printed in uppercase
        -Can not have [ENTER], must be on one line

    OUTPUT:
        -Printed in file Output and on terminal
        -If Two solutions are printed on terminal, only first solution will be printed on Output file
//--------------------------------------------------------------------------------------------------------------------------------
Program Description:
    The Program requires the following header files:
        -stdio.h
        -string.h
        -functionDef.h
            This headder file contains the function 'menu' at which requests the user input, as shown above, and all function definitions
    Function/Method List:
        -int main()
            -The main function initialises Input file, reads data. Any strings containing lowercase letters
            are then modified such that the letters are capitalised.
            -Rotation key is moddified to remain within 0-25 range.
            -menu() (Menu.h) is then executed within switch condition, at which it returns an
            integer corresponding to the users input.
            -The returned integer is then pased through the switch statement that executes the respective function

        -void encrypRotation(char String1[], int key);
            -Takes String 'String1', which is the read string from Input file
            -Takes rotation key, which is an integer representing the rotaion of the cipher
            -Output file is initialised here.
            -All char values within 'String1' are modified accordingly to the key value
            -Resulting String is printed to terminal and Output file.

        -void decrypRotation(char String1[], int key, int itter);
            -Takes same arguments as encrypRotation.
            -Additional argument itter (Itteration) is used to tell the function if Output should be printed on file.
            -itter==1 will print output on file itter!=1 will not print on file
            -Output file is initialised here.
            -All char values within 'String1' are modified accordingly to the key value,
             however this is done in reverse to the encrypRotation function.
            -Resulting String is printed to terminal, and Output file if conditions are met.

        -void encryptSubstitution(char String1[], char sub[]);
            -Takes arguments String1[](ie text), and sub[](Substitution key).
            -takes one char value of String1, and modifies to respective key char value
            -Resulting String is printed to terminal and Output file

        -void decrypSubstitution(char String1[], char sub[]);
            -Takes arguments String1[](ie cypher text), and sub[](Substitution key).
            -Takes one char value of string 1 and compares with sub[] value.
            -If same values are detected the String char value becomes the value of the pointer
             plus 65, to give it its respective char value.
            -Resulting String is printed to terminal and Output file

        -void decrypRotNoKey(char String1[]);
            -takes argument String[];
            -It begins by tallying the number of each diffrent char values, eng aaass, there are 3 a's and 2 s's.
            -It then assumes that the text is english, hence e is very likly to be the most common.
            -It then takes String[] common char value, and calculated diffrence from e char value
            -it then uses this to determine the rotation key, at which the function void decrypRotation(char String1[], int key, int itter);
             is called.
            -In addition to this, in the rare case that e isn't the most common letter, it is then assumed to be the second most
             common.
            -A second key is also calculated and parsed though function.
            -First attempt is printed to terminal and Output file.
            -Second attemp is printed to terminal.
*/

#include <stdio.h>
#include <string.h>
#include "functionDef.h"

//----------------------------------------------------------------------------------------------------------------------------------
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

    fscanf(Input, "%c", &waste);
    fscanf(Input, "%d", &key);
    fscanf(Input, "%c", &waste);
    fgets(String1, 10000, Input);
    fgets(Sub, 27, Input);

    //Following changes 'string1' to uppercase
    for(int count = 0; count<10000; count++){
        if(String1[count]>=97&&String1[count]<=122){
            String1[count] = String1[count] - 32;
        }
    }
    //Following changes 'Sub' string to uppercase
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
        default:
            break;
    }
    return 0;
}
//---------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------




