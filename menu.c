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
#include <conio.h>

extern struct game_conf_struct game_conf;
struct user
{
    char user[50];
    char pass[50];

    long int roll;

    struct user *link;
}*start=NULL,*tmp,*ptr;
char userin=0;
void log_menu(){

    int i;
    while (userin!='3') {
        system("cls");
        printf(" 1. login\n");
        printf(" 2. signup\n");
        userin=getchar();
        switch (userin) {
            case '1':
                login();
                break;

            case '2':
                signup();
                break;

            case '3':
                main_menu();
                break;
        }

    }
    main_menu();
}

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
       // getchar();
        switch (ch){
            case '1':
                map_menu();
//                game_read();
//                read_file();
//                game_time(game_conf.time);
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
void map_menu(){
    char ch = 0;
    while(ch!='5'){
        system("cls");
        printf("******************************************\n");
        printf("*                                        *\n");
        printf("*  1. game 1                             *\n");
        printf("*  2. game 2                             *\n");
        printf("*  3. game 3                             *\n");
        printf("*  4. user game                          *\n");
        printf("*  5. back to menu                       *\n");
        printf("*                                        *\n");
        printf("******************************************\n");
        ch=getchar();
       // getchar();
        switch (ch){
            case '1':

                game_read("game-pacman.txt");
                read_file("map-pacman.txt");
                game_time(game_conf.time);
                break;

            case '2':
                game_read("game2-pacman.txt");
                read_file("map2-pacman.txt");
                game_time(game_conf.time);

                break;

            case '3':
                game_read("game3-pacman.txt");
                read_file("map3-pacman.txt");
                game_time(game_conf.time);
            case '4':
                printf("please enter your info name ... \n");
                char info_name[50];
                scanf("%s",info_name);

                printf("please enter your map name ... \n");
                char map_name[50];
                scanf("%s",map_name);
                game_read(info_name);
                read_file(map_name);
                game_time(game_conf.time);
            case '5':
                break;

        }
    }
    printf("******************************************\n");
    printf("*                                        *\n");
    printf("*  1. game 1                             *\n");
    printf("*  2. game 2                             *\n");
    printf("*  3. game 3                             *\n");
    printf("*  4. user game                          *\n");
    printf("*                                        *\n");
    printf("******************************************\n");
}
void signup(){
        system("cls");
        char nam[50],cit[50],subj[30];
        tmp=(struct user*)malloc(sizeof(struct user));
        printf("\nEnter Student name:" );
        fflush(stdin);
        gets(nam);
        strcpy(tmp->user, nam);
        printf("\nEnter subject of student: ");
        fflush(stdin);
        gets(subj);
        strcpy(tmp->pass, subj);
        printf("\nEnter City of student: ");
        fflush(stdin);
        gets(cit);
        scanf("%ld", &(tmp->roll));
        fflush(stdin);
        tmp->link=NULL;
        if(start==NULL)
        {
            start=tmp;
        }
        else
        {
            ptr=start;
            while(ptr!=NULL)
            {
                ptr=ptr->link;
                ptr->link=tmp;
            }
        }
        printf("\n success \n press enter to go to login menu");
        userin=0;
        getchar();
}
void login(){
    char userid[]="admin",password[]="admin",p[15],u[15];
    int n=1,a,b;
    printf("\nYou have  three chances to enter");

    while(n<=3)
    {
        printf("\nUSER ID: ");
        scanf("%s",u);
        printf("\nPASSWORD: ");
        scanf("%s",p);
        a=strcmp(u,userid);
        b=strcmp(p,password);
        if(a==0&&b==0)
        {
            printf("\nYou have logged in successfully.");
            userin='3';
            break;

        }
        else
        {
            printf("\nWrong PASSWORD and/or USER ID. Now you have % d more chance/s.",3-n);
        }

        n++;
    }
    if(n==4)
        exit(0);

};

