//
// Created by IDEA on 6/29/2019.
//

#include "functions.h"
#include "gameconf.h"
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
clock_t start ;
//
// Created by IDEA on 6/29/2019.
//
#include <stdio.h>
#include "functions.h"
extern struct game_conf_struct game_conf;
extern struct game_state_struct game_state;


void movement_1(){
    while(kbhit()) {
        int key = getch();
        if(key == game_conf.left) {
            game_state.x_change = -1;
            game_state.y_change = 0;
        }
        else if(key == game_conf.right) {
            game_state.x_change = 1;
            game_state.y_change = 0;
        }
        else if(key == game_conf.up) {
            game_state.x_change = 0;
            game_state.y_change = -1;
        }
        else if(key == game_conf.down) {
            game_state.x_change = 0;
            game_state.y_change = 1;
        }
        /* now if the player wants to exit the game */
        else if(key == game_conf.exitt) {
            break;
        }
        else if(key == game_conf.raindb) {
            for(int index = 0 ; index <= game_conf.raindb ; index++) {
                game_state.array[game_state.x_pos][game_state.y_pos] == game_conf.daethblock;
            }
        }
        else if(key == game_conf.put) {
            for(int next_index = 0; next_index <= game_conf.put_num; next_index++) {
                game_state.array[game_state.x_pos][game_state.y_pos] == game_conf.daethblock;
            }
        }

        /* now let's write something for the raindb :) I hope k narinm:/ */
        /* khb mn nemirinm vli khb nega aln inja b nazaram bayad vse in ye char arr dar nazar begirima:/ */
        /*else if(key == game_conf.raindb[0]) {
            for(int index = 0 ; index <= game_conf.raindb[2]) {
                game_state.array[game_state.x_pos][game_state.y_pos] == game_conf.raindb[1];
            }
        }*/


    }
}


int game_time(float seconde){
    seconde = game_conf.time;
    while(seconde  > 0){
        fflush(stdout) ;
        if(clock() - start > 500){

            /* if there were a Solidblock or a wall */
            if(game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos + game_state.y_change] == game_conf.solidb || game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos + game_state.y_change] == game_conf.wall)
                game_state.array[game_state.x_pos][game_state.y_pos]  = game_conf.character;

            /* if the block were a deathblock the game will end */
            else if(game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos + game_state.y_change] == game_conf.daethblock) {
                /* first clean the screen then print game over and then come out */
                system("cls");
                printf("GAME OVER!");
                break;
            }

            /* if the character richs the target it will win */
            else if(game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos + game_state.y_change] == game_conf.target) {
                system("cls");
                printf("YOU WON :)");
                break;
            }
            /* if there were a moveblock there */
            else if(game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos + game_state.y_change] == game_conf.moveblock) {
                if(game_state.x_change == 1) {
                    game_state.array[game_state.x_pos + game_state.x_change + 1][game_state.y_pos + game_state.y_change] = game_conf.moveblock;
                    game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos + game_state.y_change] = game_conf.character;
                }
                else if(game_state.x_change == -1) {
                    game_state.array[game_state.x_pos + game_state.x_change - 1][game_state.y_pos + game_state.y_change] = game_conf.moveblock;
                    game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos + game_state.y_change] = game_conf.character;
                }
                else if(game_state.y_change == 1) {
                    game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos + game_state.y_change + 1] = game_conf.moveblock;
                    game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos + game_state.y_change] = game_conf.character;
                }
                else if(game_state.y_change == -1) {
                    game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos + game_state.y_change - 1] = game_conf.moveblock;
                    game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos + game_state.y_change] = game_conf.character;
                }
            }
            else if(game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos + game_state.y_change] == game_conf.rpoint) {
                game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos + game_state.y_change] == game_conf.character;
                random_point(1);
            }


            /* if the block is an object block the thing I understood is that object and the target are the same:/ */
            /* Or maybe it is some thing that it should move toward the target:/ */




            else {
                game_state.y_pos += game_state.y_change;
                game_state.x_pos += game_state.x_change;
                game_state.array[game_state.x_pos][game_state.y_pos]  = game_conf.character;
                game_state.array[ game_state.x_pos - game_state.x_change][game_state.y_pos - game_state.y_change]  = ' ';
            }


            seconde -= 0.2;
            printf("\ntime remaining : %.1f" , seconde);
            start = clock();
        }
    }
}


int random_point(int n){

    int i  = 0 ;
    int random_x = 0 ;
    int random_y = 0 ;

    while(i < n){
        random_x = rand() % game_state.width;
        random_y = rand() % game_state.length;
        if(game_state.array[random_x][random_y] == ' '){
            game_state.array[random_x][random_y] = game_conf.rpoint ;
            ++i;
        }
    }


}