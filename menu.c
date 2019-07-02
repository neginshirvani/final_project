//
// Created by alisa on 7/2/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "gameconf.h"
#include "read_file.h"
#include "Gameread.h"
#include "read_file.h"
#include "menu.h"
#include "functions.h"
extern struct game_conf_struct game_conf;


void main_menu(){
    char ch = 0;
    while(ch!='4'){
        system("cls");
        printf("\n");
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
                game_read();
                read_file();
                game_time(game_conf.time);
                break;

            case '2':

                break;

            case '3':
                settings();
                break;
            case '4':
                exit(0);

        }
    }
    settings();
}
void theme(){

}
void font(){

}
void settings(){
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
        switch (ch) {
            case '1':
                theme();
                break;

            case '2':
                font();
                break;

        }
    }
}