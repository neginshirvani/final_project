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
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), game_conf.theme_num);
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
                best_score();

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
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), game_conf.theme_num);
    char ch = 0;
    while (ch!='4') {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), game_conf.theme_num);
        system("cls");
        printf("\n******************************************\n");
        printf("* -->theme :                             *\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        printf("*  1. mode 1                             *\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), game_conf.theme_num);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
        printf("*  2. mode 2                             *\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        printf("*  3. normal mode                        *\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), game_conf.theme_num);
        printf("*  4. back to menu                       *\n");
        printf("*                                        *\n");
        printf("******************************************\n");
        ch=getchar();
        getchar();
        switch (ch){
            case '1':
                game_conf.theme_num=10;
                //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                break;

            case '2':
                game_conf.theme_num=9;
                //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                break;
            case '3':
                game_conf.theme_num=15;
                //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                break;
        }
    }

}

void settings(){
    char ch = 0;
    while (ch!='2') {
        system("cls");

        printf("\n******************************************\n");
        printf("* -->theme :                             *\n");
        printf("*                                        *\n");
        printf("*  1. change theme                       *\n");
        printf("*  2. Back to menu                       *\n");
        printf("*                                        *\n");
        printf("*                                        *\n");
        printf("******************************************\n");
        ch=getchar();
        getchar();
        switch (ch) {
            case '1':
                theme();
                break;

            case '2':

                break;

        }
    }
}
void best_score(){
    system("cls");
    FILE *score=fopen("score.txt","r");
    int i ;
    char b;
    for ( i = 0; (b=fgetc(score))!=EOF ; ++i) {
        printf("%c",b);
    }

    printf("\npress enter to back to menu ... ");
    getchar();
}