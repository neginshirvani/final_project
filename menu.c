//
// Created by alisa on 7/1/2019.
//
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include <windows.h>

int  main_menu(){
    char ch = 0;
    while(ch!='4'){
        system("cls");
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
        ch=getchar();
        getchar();
        switch (ch){
            case '1':

                break;

            case '2':

                break;

            case '3':
                setting();
                break;
            case '4':
//                exit(0);
                break;
        }
    }
    setting();

}
void setting(){
    char ch = 0;
    while (ch!='3') {
        system("cls");

        printf("\n******************************************\n");
        printf("* -->setting :                           *\n");
        printf("*                                        *\n");
        printf("*  1. change theme                       *\n");
        printf("*  2. change font                        *\n");
        printf("*  3. Back to menu                       *\n");
        printf("*                                        *\n");
        printf("******************************************\n");
        ch=getchar();
        getchar();
        switch (ch){
            case '1':
                theme();
                break;

            case '2':
                font();
                break;

        }
    }
}
void theme(){

}
void font(){

}
