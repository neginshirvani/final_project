//
// Created by alisa on 7/1/2019.
//
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include <windows.h>
void main_menu(){
    printf("WELCOME!\n");
    printf("******************************************\n");
    printf("*                                        *\n");
    printf("*  1. Open game.                         *\n");
    printf("*  2. Best score game.                   *\n");
    printf("*  3. Setting.                           *\n");
    printf("*  ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
    printf("4. Exit.");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

    printf("                              *\n");

    printf("*                                        *\n");
    printf("******************************************\n");
    int ch=getchar();

}
void setting(){
    printf("******************************************\n");
    printf("* -->setting :                           *\n");
    printf("*  1. change theme                       *\n");
    printf("*  2. change font                        *\n");
    printf("*  3. Back to menu                       *\n");
    printf("*                                        *\n");
    printf("******************************************\n");
}
