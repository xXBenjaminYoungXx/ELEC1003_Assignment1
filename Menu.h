#include<stdio.h>

int menu(void);
<<<<<<< HEAD
/**
menu returns an integer that is inputted by the user.
*/
int menu(void){
    int menuChoice = 0;
    printf("Rotation:\nEnter (1) to encrypt message\nEnter (2) to decrypt message\nSubstitution:\nEnter (3) to encrypt message\nEnter (4) to decrypt message\nRotation with no key:\nEnter (5) to decrypt\n");
=======

int menu(void){
    int menuChoice = 0;
    printf("Rotation:\nEnter (1) to encript message\nEnter (2) to decript message\nSubstitution:\nEnter (3) to encript message\nEnter (4) to decript message\n");
>>>>>>> 6b901b4edd026428e1ecde3c1c3801728c8527fe
    scanf("%d", &menuChoice);
    return menuChoice;
}
