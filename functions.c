//
// Created by IDEA on 6/29/2019.
//

#include "functions.h"
#include "gameconf.h"

//
// Created by IDEA on 6/29/2019.
//
#include <stdio.h>
#include "functions.h"
extern struct game_conf_struct game_conf;

void movement_1(){
    while(kbhit()) {
        int key = getch();
        if(key == game_conf.left) {
            x1_pos -= 1;
        }
        else if(key == game_conf.right) {
            x1_pos += 1;
        }
        else if(key == game_conf.up) {
            y1_pos -= 1;
        }
        else if(key == game_conf.down) {
            y1_pos += 1;
        }

    }
}

void isSolid(int x, int y) {
    if(arr[x][y] == game_conf.solidb || arr[x][y] == game_conf.wall) {
        arr[x][y] = arr[x1_pos][y1_pos];
    }
}

void isDeath(int x, int y) {
    if(arr[x][y] == game_conf.daethblock) {
        system("cls");
        printf("GAME OVER");
    }
}

void isTarget(int x, int y) {
    if(arr[x][y] == game_conf.target) {
        system("cls");
        printf("YAAAAAAAY YOU WON!");
    }
}

/* wonder if it is correct or not */
void isMoveBlock(int x , int y) {
    if(arr[x][y] == game_conf.moveblock) {
        arr[x1_pos][y1_pos] = game_conf.moveblock;
    }
}

void isPut(int x, int y) {
    if(arr[x][y] == game_conf.put) {
        arr[x][y] == game_conf.daethblock;
    }
}

