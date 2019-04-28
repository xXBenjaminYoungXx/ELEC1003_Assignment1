#include<stdio.h>
//---------------------------------------------------------------------------------------------------------------------------------------
/*
Benjamin Young
c3330653
BenjaminYoung7198@gmail.com
Program description comments are given in 'main.c'
*/
//---------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------
int menu(void);
void encrypRotation(char String1[], int key);
void decrypRotation(char String1[], int key, int itter);
void encryptSubstitution(char String1[], char sub[]);
void decrypSubstitution(char String1[], char sub[]);
void decrypRotNoKey(char String1[]);
//---------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------

/**
Takes no arguments
Used printf and scanf for I/O. An if statement is used to detect if integer is valid.
Returns an integer of range 1-5 that is inputted by the user.
*/
int menu(void){
    while(1){
        int menuChoice = 0;
        printf("Rotation:\nEnter (1) to encrypt message\nEnter (2) to decrypt message\nSubstitution:\nEnter (3) to encrypt message\nEnter (4) to decrypt message\nRotation with no key:\nEnter (5) to decrypt\n");
        scanf("%d", &menuChoice);
        if(menuChoice>0&&menuChoice<6){
            return menuChoice;
        }
        printf("\nError: Only 0-5 permitted.\n");
    }
}

//----------------------------------------------------------------------------------------------------------------------------------
/**
Takes arguments:
    -char array (String1)[text to be encrypted]
    -interger (key)[the value at which the alphabet is rotated]
This function looks at each individual char value, and adds the key value to encrypt the message
Returns nothing.
*/

void encrypRotation(char String1[], int key){
    //E(m) = (m+k)mod26
    FILE *Output;
    Output = fopen("Output", "w");
    //replace char in String[count] by adding key, only do this if char is within alphabet
    for(int count = 0; count<10000; count++){
        if(String1[count]>=65&&String1[count]<=90){
            String1[count] = 65+(((String1[count])-65)+key)%26;
        }
    }
    printf("Encryption: \n");
    printf("%s\n", String1);
    fprintf(Output, "Encryption:\n%s", String1);
}
//----------------------------------------------------------------------------------------------------------------------------------
/**
Takes arguments:
    -char array (String1) [text to be decripted]
    -int key [the value of which the alphabet was rotated]
    -int itter [if file output should be printed, 1 if yes, 2 if no]
The exact same proccess as encryptRotation, however key value is minused and char values below 65 are adjusted.
returns nothing
*/
void decrypRotation(char String1[], int key, int itter){
    //E(m) = (m+k)mod26
    FILE *Output;
    Output = fopen("Output", "w");
    int add = 0;
    for(int count = 0; count<10000; count++){
        if((String1[count]-65)-key<0){//if negative add 26 to get respective key value
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
Takes arguments:
    -char array (String1)  [text to be encrypted]
    -char array (Sub) [26 long char key]
Finds value of String char and replaces with respective char value in sub. It utilised Sub[]'s pointer to do this.
Returns Nothing

*/
void encryptSubstitution(char String1[], char sub[]){
    FILE *Output;
    Output = fopen("Output", "w");
    //replace String[count] with respective char
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
    fprintf(Output, "Encryption:\n%s", String1);
}
//----------------------------------------------------------------------------------------------------------------------------------
/**
Takes arguments:
    -char array (String1)  [text to be decrypted]
    -char array (Sub) [26 long char key]
compares each string1 char value with sub value, and once found to be equivelent,
sub's pointer value is used to get respective char value.
Returns Nothing
*/
void decrypSubstitution(char String1[], char sub[]){
    FILE *Output;
    Output = fopen("Output", "w");
    for(int count = 0; count<strlen(String1); count++){
        //if string1 is equal to a character in sub, it becomes sub pointer + 65
        for(int count2 = 0; count2<26; count2++){//Look at char value String1[count], and find on sub[]
            if(String1[count]==sub[count2]){//When found, the String1 char value then becomes the counter value
                String1[count]=count2 + 65;//This counter value needs to be adjusted as to match ASCII values
                count2 =100;//This is done to exit the second for loop as chr value has been matched
            }
        }
    }
    printf("Decryption: \n");
    printf("%s\n", String1);
    fprintf(Output, "Decryption:\n%s", String1);
}
//----------------------------------------------------------------------------------------------------------------------------------
/**
Takes arguments:
    -char array (String1)  [text to be decripted]
This function executes code that takes static string input and decrips through rotation method.
A Known problem is that it assumes standard english is used via assuming e to be the most, or second most common char.
This is not always the case e.g: Benjamin Young has n as the most common char.
I have decided not to 'brute' force this, which will result in the printing of 26 text sets, and tackled the problem with the method above.
A standard alphabet char array is used.
Returns Nothing
*/
void decrypRotNoKey(char String1[]){
    //To do this find most common letter, then suggest its e, apply same rotation to other texts
    int key = 0;//used for attept 1
    int key2 = 0;//used for attept 2
    int key3 = 0;
    int alphabet[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};//used to tally
    char alphabetChar[26] = {65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90};//used as standard alphabet
    int biggest = 0;//used to track biggest
    int biggest2 = 0;
    int biggest3 = 0;
    int biggestCount=0;//used to track pointer with biggest value
    int biggestCount2 = 0;
    int biggestCount3 = 0;

    //Tally up variable count
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
        case 6: alphabet[5]+=1;
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
    //Now to see which was highest count, second highest count and third highest count
    for(int count = 0; count<26;count++){
        if(alphabet[count]>biggest){//Transfere values for biggest 3 and 2 then adjust biggest
            biggest3 = biggest2;
            biggestCount3 = biggestCount2;

            biggest2 = biggest;
            biggestCount2 = biggestCount;

            biggest = alphabet[count];
            biggestCount = count;
        }
        else if(alphabet[count]>biggest2){//Transfere values for biggest 3 then adjust biggest2
            biggest3 = biggest2;
            biggestCount3 = biggestCount2;

            biggest2 = alphabet[count];
            biggestCount2 = count;
        }
        else if(alphabet[count]>biggest3){
            biggest3 = alphabet[count];
            biggestCount3 = count;
        }
    }
    //if 0 is biggest, A is most common, hence key == 4
    //if 1 is beiggest B is most common, hence key == 3
    //if 5 e is common key = 0, if f is common key =25
    for(int count = 0; count<26; count++){
        //Key is diffrence of biggest char to e
        if(biggestCount == count){
            key = alphabetChar[count]-69;
        }
        if(biggestCount2 == count){
            key2 = alphabetChar[count]-69;
        }
        if(biggestCount3 == count){
            key3 = alphabetChar[count]-69;
        }
    }
    if(key<0){
        key = key + 26;
    }
    if(key2<0){
        key2 = key2 + 26;
    }
    if(key3<0){
        key3 = key3 + 26;
    }
    //Second string used as argument for second attept, and third attempt
    char String2[10000];
    char String3[10000];
    for(int count = 0; count<strlen(String1);count++){
        String2[count] = String1[count];
        String3[count] = String1[count];
    }
    decrypRotation(String1,key, 2);
    printf("Decryption attempt 2:\n\n");
    decrypRotation(String2,key2, 2);
    printf("Decryption attempt 3:\n\n");
    decrypRotation(String3,key3, 2);

    FILE *Output;
    Output = fopen("Output", "w");
    fprintf(Output, "Decryption Attempt 1:\n%s\nDecryption Attempt 2:\n%s\nDecryption Attempt 3:\n%s", String1, String2, String3);
}
//----------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------
/**
*/
