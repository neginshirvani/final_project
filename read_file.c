//
// Created by alisa on 6/28/2019.
//

#include "read_file.h"
#include "Gameread.h"
#include "gameconf.h"
#include<stdio.h>
#include <stdlib.h>
#include "functions.h"
#include <conio.h>
#include <windows.h>

extern struct game_conf_struct game_conf;
extern struct game_state_struct game_state;



void read_file () {
    FILE *map;
//    printf("please enter your map name ... \n");
//    char map_name[50];
//    scanf("%s",map_name);
//    map = fopen(map_name, "r");
    map = fopen("map-pacman.txt", "r");
    char c;
    int i = 0;
    int j = 0;
    while ((c = fgetc(map)) != EOF) {
        game_state.array[i][j] = c;
        /* position of the character */
        if (c == game_conf.character) {
            //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
            game_state.x_pos = i;
            game_state.y_pos = j;
        }
        if (c == game_conf.target) {
            //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            game_state.target_x = i;
            game_state.target_y = j;
        }
        if (c == game_conf.opp) {
            game_state.opp_x = i;
            game_state.opp_y = j;
        }
        ++j;
        if (c == '\n') {
            game_state.array[i][j-1]='\0';
            ++i;
            j = 0;
        }
    }

    game_state.width = i - 1;
    game_state.length = j;
    printf("%d %d", game_state.width, game_state.length);

    fclose(map);
    //random_deathblock();
    game_state.array[i][j] = '\0';
    i = j = 0;
    for (j=0;game_state.array[i][j]!=game_conf.wall;++j){   // finding first block of map
        if(game_state.array[i][j]=='\n'){
            ++i;
            j=0;
        }
    }
    j=0;

    int ch;
    while(game_state.array[i][j]!='\0'){

        putchar(game_state.array[i][j]);
        ch=game_state.array[i][j];
        ++j;
        if(ch=='\n'){
            ++i;
            j=0;
        }
    }
}
