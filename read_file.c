//
// Created by alisa on 6/28/2019.
//

#include "read_file.h"
#include "Gameread.h"
#include "gameconf.h"
#include<stdio.h>
#include <stdlib.h>
char array[1000][1000];

extern struct game_conf_struct game_conf;

void read_file () {
    FILE *map;
    map = fopen("map-pacman.txt", "r");
    char c;
    int i = 0;
    int j = 0;
    while ((c = fgetc(map)) != EOF) {
        array[i][j] = c;
        ++j;
        if (c == '\n') {
            ++i;
            j = 0;
        }
    }
    fclose(map);
    array[i][j] = '\0';
    i = j = 0;
    for (j=0;array[i][j]!='#';++j){   // finding first block of map
        if(array[i][j]=='\n'){
            ++i;
            j=0;
        }
    }
    j=0;
    int ch;
    while(array[i][j]!='\0'){

        putchar(array[i][j]);
        ch=array[i][j];
        ++j;
        if(ch=='\n'){
            ++i;
            j=0;
        }
    }
}
