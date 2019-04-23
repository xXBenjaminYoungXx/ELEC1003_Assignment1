#include<stdio.h>

int menu(void);

int menu(void){
    int menuChoice = 0;
    printf("Rotation:\nEnter (1) to encript message\nEnter (2) to decript message\nSubstitution:\nEnter (3) to encript message\nEnter (4) to decript message\n");
    scanf("%d", &menuChoice);
    return menuChoice;
}
