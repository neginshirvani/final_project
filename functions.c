//
// Created by IDEA on 6/29/2019.
//

#include "functions.h"
#include "gameconf.h"
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

#include "read_file.h"

clock_t start;
//
// Created by IDEA on 6/29/2019.
//
#include <stdio.h>
#include "functions.h"

extern struct game_conf_struct game_conf;
extern struct game_state_struct game_state;


void movement_1() {
    //printf("GO to ie zendegi sagi sanati");
    while (kbhit()) {
        int key = getch();
        if (key == game_conf.left) {
            game_state.x_change = 0;
            game_state.y_change = -1;
        } else if (key == game_conf.right) {
            game_state.x_change = 0;
            game_state.y_change = 1;
        } else if (key == game_conf.up) {
            game_state.x_change = -1;
            game_state.y_change = 0;
        } else if (key == game_conf.down) {
            game_state.x_change = 1;
            game_state.y_change = 0;
        }
            /* now if the player wants to exit the game */
        else if (key == game_conf.exitt) {
            //system("cls");
            //break;
            exit(0);
        }
//        else if(key == game_conf.raindb) {
//            for(int index = 0 ; index <= game_conf.raindb ; index++) {
//                game_state.array[game_state.x_pos][game_state.y_pos] == game_conf.daethblock;
//            }
//        }
        else if (key == game_conf.put) {
            //for(int next_index = 0; next_index <= game_conf.put_num; next_index++) {
            if (game_conf.put_num > 0) {
                if (game_state.y_change == -1)
                    game_state.array[game_state.x_pos][(game_state.y_pos) + 1] = game_conf.daethblock;
                else if (game_state.y_change == 1)
                    game_state.array[game_state.x_pos][(game_state.y_pos) - 1] = game_conf.daethblock;
                else if (game_state.x_change == 1)
                    game_state.array[game_state.x_pos - 1][(game_state.y_pos)] = game_conf.daethblock;
                else if (game_state.x_change == -1)
                    game_state.array[game_state.x_pos + 1][(game_state.y_pos)] = game_conf.daethblock;
                game_conf.put_num--;
            }
        }

        /* now let's write something for the raindb :) I hope k narinm:/ */
        /* khb mn nemirinm vli khb nega aln inja b nazaram bayad vse in ye char arr dar nazar begirima:/ */
        /*else if(key == game_conf.raindb[0]) {
            for(int index = 0 ; index <= game_conf.raindb[2]) {
                game_state.array[game_state.x_pos][game_state.y_pos] == game_conf.raindb[1];
            }
        }*/
        //random_deathblock();

    }
}

void wait(float seconds) {
    clock_t endwait;
    endwait = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < endwait) {}
}

int game_time(float timee) {
    float count_down_time_in_secs = timee;
    float x_seconds = 0;
    float x_milliseconds = 0;
    //  float totaltime=0;
    float time_left = 0;
    clock_t x_startTime, x_countTime;
    x_startTime = clock();
    time_left = count_down_time_in_secs - x_seconds;
    while (time_left > 0) {
        x_countTime = clock(); // update timer difference
        x_milliseconds = x_countTime - x_startTime;
        x_seconds = (x_milliseconds / (CLOCKS_PER_SEC));//-(x_minutes*60);
        time_left = count_down_time_in_secs - x_seconds; // subtract to get difference

        //fflush(stdout);
        system("cls");
        /* if there were a Solidblock or a wall */

        if (game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos + game_state.y_change] ==
            game_conf.solidb ||
            game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos + game_state.y_change] ==
            game_conf.wall)
            game_state.array[game_state.x_pos][game_state.y_pos] = game_conf.character;

            /* if the block were a deathblock the game will end */
        else if (game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos + game_state.y_change] ==
                 game_conf.daethblock) {
            /* first clean the screen then print game over and then come out */
            system("cls");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
            printf("GAME OVER!");
            getchar();
            break;
        }

            /* if the character richs the target it will win */
        else if (game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos + game_state.y_change] ==
                 game_conf.target) {
            system("cls");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            printf("YOU WON :)");
            getchar();
            break;
        }
            /* if there were a moveblock there */
        else if (game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos + game_state.y_change] ==
                 game_conf.moveblock) {
            if (game_state.x_change == 1) {
                if (game_state.array[game_state.x_pos + game_state.x_change + 1][game_state.y_pos +
                                                                                 game_state.y_change] ==
                    game_conf.wall ||
                    game_state.array[game_state.x_pos + game_state.x_change + 1][game_state.y_pos +
                                                                                 game_state.y_change] ==
                    game_conf.solidb ||
                    game_state.array[game_state.x_pos + game_state.x_change + 1][game_state.y_pos +
                                                                                 game_state.y_change] ==
                    game_conf.daethblock ||
                    game_state.array[game_state.x_pos + game_state.x_change + 1][game_state.y_pos +
                                                                                 game_state.y_change] ==
                    game_conf.target ||
                    game_state.array[game_state.x_pos + game_state.x_change + 1][game_state.y_pos +
                                                                                 game_state.y_change] ==
                    game_conf.rpoint) {
                    game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos +
                                                                             game_state.y_change] = game_conf.moveblock;
                } else {
                    game_state.array[game_state.x_pos + game_state.x_change + 1][game_state.y_pos +
                                                                                 game_state.y_change] = game_conf.moveblock;
                    game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos +
                                                                             game_state.y_change] = game_conf.character;
                    game_state.array[game_state.x_pos + game_state.x_change - 1][game_state.y_pos +
                                                                                 game_state.y_change] = ' ';
                }
            } else if (game_state.x_change == -1) {
                if (game_state.array[game_state.x_pos + game_state.x_change - 1][game_state.y_pos +
                                                                                 game_state.y_change] ==
                    game_conf.wall ||
                    game_state.array[game_state.x_pos + game_state.x_change - 1][game_state.y_pos +
                                                                                 game_state.y_change] ==
                    game_conf.solidb ||
                    game_state.array[game_state.x_pos + game_state.x_change - 1][game_state.y_pos +
                                                                                 game_state.y_change] ==
                    game_conf.daethblock ||
                    game_state.array[game_state.x_pos + game_state.x_change - 1][game_state.y_pos +
                                                                                 game_state.y_change] ==
                    game_conf.target ||
                    game_state.array[game_state.x_pos + game_state.x_change - 1][game_state.y_pos +
                                                                                 game_state.y_change] ==
                    game_conf.rpoint) {
                    game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos +
                                                                             game_state.y_change] = game_conf.moveblock;
                } else {
                    game_state.array[game_state.x_pos + game_state.x_change - 1][game_state.y_pos +
                                                                                 game_state.y_change] = game_conf.moveblock;
                    game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos +
                                                                             game_state.y_change] = game_conf.character;
                    game_state.array[game_state.x_pos + game_state.x_change + 1][game_state.y_pos +
                                                                                 game_state.y_change] = ' ';
                }
            } else if (game_state.y_change == 1) {
                if (game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos +
                                                                             game_state.y_change + 1] ==
                    game_conf.wall || game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos +
                                                                                               game_state.y_change +
                                                                                               1] ==
                                      game_conf.solidb ||
                    game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos +
                                                                             game_state.y_change + 1] ==
                    game_conf.daethblock ||
                    game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos +
                                                                             game_state.y_change + 1] ==
                    game_conf.daethblock ||
                    game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos +
                                                                             game_state.y_change + 1] ==
                    game_conf.rpoint) {
                    game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos +
                                                                             game_state.y_change] = game_conf.moveblock;
                } else {
                    game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos +
                                                                             game_state.y_change +
                                                                             1] = game_conf.moveblock;
                    game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos +
                                                                             game_state.y_change] = game_conf.character;
                    game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos +
                                                                             game_state.y_change - 1] = ' ';
                }
            } else if (game_state.y_change == -1) {
                if (game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos +
                                                                             game_state.y_change - 1] ==
                    game_conf.wall || game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos +
                                                                                               game_state.y_change -
                                                                                               1] ==
                                      game_conf.solidb ||
                    game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos +
                                                                             game_state.y_change - 1] ==
                    game_conf.daethblock ||
                    game_state.array[game_state.x_pos + game_state.x_change - 1][game_state.y_pos +
                                                                                 game_state.y_change] ==
                    game_conf.target || game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos +
                                                                                                 game_state.y_change -
                                                                                                 1] ==
                                        game_conf.rpoint) {
                    game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos +
                                                                             game_state.y_change] = game_conf.moveblock;
                } else {
                    game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos +
                                                                             game_state.y_change -
                                                                             1] = game_conf.moveblock;
                    game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos +
                                                                             game_state.y_change] = game_conf.character;
                    game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos +
                                                                             game_state.y_change + 1] = ' ';
                }
            }
                /* if there were a moveblock there */
            else if (game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos +
                                                                              game_state.y_change] ==
                     game_conf.moveblock) {
                if (game_state.x_change == 1) {
                    game_state.array[game_state.x_pos + game_state.x_change + 1][game_state.y_pos +
                                                                                 game_state.y_change] = game_conf.moveblock;
                    game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos +
                                                                             game_state.y_change] = ' ';

                } else if (game_state.x_change == -1) {
                    game_state.array[game_state.x_pos + game_state.x_change - 1][game_state.y_pos +
                                                                                 game_state.y_change] = game_conf.moveblock;
                    game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos +
                                                                             game_state.y_change] = ' ';
                } else if (game_state.y_change == 1) {
                    game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos +
                                                                             game_state.y_change +
                                                                             1] = game_conf.moveblock;
                    game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos +
                                                                             game_state.y_change] = ' ';
                } else if (game_state.y_change == -1) {
                    game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos +
                                                                             game_state.y_change -
                                                                             1] = game_conf.moveblock;
                    game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos +
                                                                             game_state.y_change] = ' ';
                }
            }
        }

            /*else if (
                   game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos + game_state.y_change] ==
                   game_conf.rpoint) {
               game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos + game_state.y_change] =
               game_conf.character;
               game_state.array[game_state.x_pos][game_state.y_pos] = ' ';

//                if(game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos + game_state.y_change] != ' ') {
//                    game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos + game_state.y_change] = game_conf.moveblock;
//                }
           }*/
        else if (game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos + game_state.y_change] ==
                 game_conf.rpoint) {
            game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos +
                                                                     game_state.y_change] = game_conf.character;
            game_state.array[game_state.x_pos][game_state.y_pos] = ' ';
            random_point(1);
            ++game_conf.rpoint_score;
            //printf("%d", game_conf.rpoint_score);
        }


            /* if the block is an object block the thing I understood is that object and the target are the same:/ */
            /* Or maybe it is some thing that it should move toward the target:/ */




        else {
            game_state.y_pos += game_state.y_change;
            game_state.x_pos += game_state.x_change;
            game_state.array[game_state.x_pos][game_state.y_pos] = game_conf.character;
            game_state.array[game_state.x_pos - game_state.x_change][game_state.y_pos - game_state.y_change] = ' ';
        }

        show_map();


        printf("\nTime remaining %.2f ", time_left);
        wait(0.02);
    }


}
//int game_time(float left_time){
//
//    while(left_time  > 0){
//        fflush(stdout) ;
//        //system("cls");
//        if(clock() - start > 500){
//
//            /* if there were a Solidblock or a wall */
//            if(game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos + game_state.y_change] == game_conf.solidb || game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos + game_state.y_change] == game_conf.wall)
//                game_state.array[game_state.x_pos][game_state.y_pos]  = game_conf.character;
//
//            /* if the block were a deathblock the game will end */
//            else if(game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos + game_state.y_change] == game_conf.daethblock) {
//                /* first clean the screen then print game over and then come out */
//                system("cls");
//                printf("GAME OVER!");
//                break;
//            }
//
//            /* if the character richs the target it will win */
//            else if(game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos + game_state.y_change] == game_conf.target) {
//                system("cls");
//                printf("YOU WON :)");
//                break;
//            }
//            /* if there were a moveblock there */
//            else if(game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos + game_state.y_change] == game_conf.moveblock) {
//                if(game_state.x_change == 1) {
//                    game_state.array[game_state.x_pos + game_state.x_change + 1][game_state.y_pos + game_state.y_change] = game_conf.moveblock;
//                    game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos + game_state.y_change] = ' ';
//                }
//                else if(game_state.x_change == -1) {
//                    game_state.array[game_state.x_pos + game_state.x_change - 1][game_state.y_pos + game_state.y_change] = game_conf.moveblock;
//                    game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos + game_state.y_change] = ' ';
//                }
//                else if(game_state.y_change == 1) {
//                    game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos + game_state.y_change + 1] = game_conf.moveblock;
//                    game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos + game_state.y_change] = ' ';
//                }
//                else if(game_state.y_change == -1) {
//                    game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos + game_state.y_change - 1] = game_conf.moveblock;
//                    game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos + game_state.y_change] = ' ';
//                }
//            }
//            else if(game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos + game_state.y_change] == game_conf.rpoint) {
//                game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos + game_state.y_change] == game_conf.character;
//                random_point(1);
//                ++game_conf.rpoint_score;
//            }
//
//
//            /* if the block is an object block the thing I understood is that object and the target are the same:/ */
//            /* Or maybe it is some thing that it should move toward the target:/ */
//
//
//
//
//            else {
//                game_state.y_pos += game_state.y_change;
//                game_state.x_pos += game_state.x_change;
//                game_state.array[game_state.x_pos][game_state.y_pos]  = game_conf.character;
//                game_state.array[ game_state.x_pos - game_state.x_change][game_state.y_pos - game_state.y_change]  = ' ';
//            }
//
//            show_map();
//            left_time -= 0.2;
//            printf("\ntime remaining : %.2f" , left_time);
//
//            start = clock();
//        }
//    }
//}


int random_point(int n) {

    int i = 0;
    int random_x = 0;
    int random_y = 0;

    while (i < n) {
        random_x = rand() % game_state.width;
        random_y = rand() % game_state.length;
        if (game_state.array[random_x][random_y] == ' ') {
            game_state.array[random_x][random_y] = game_conf.rpoint;
            ++i;
        }
    }
}

/* in agar seda zade beshe va faal bashe kar mikone albate vli ye soal pish miad va
 * oonm inke agar tabe baqie esmesh farq kone chi:/*/
int random_deathblock() {
    int y = 4;
    int random_x = 0;
    int i = 0;
    //for (int j = 0; j < game_state.width; j++) {
    for (i = 0; i < game_conf.raindb; i++) {
        random_x = rand() % game_state.length;
        if (random_x == 0) {
            random_x = rand() % game_state.length;
        }
        game_state.raindbb[y][0] = random_x;
        game_state.raindbb[y][1] = 1;
//        getchar();
        if (game_state.array[y][random_x] == game_conf.wall ||
            game_state.array[y][random_x] == game_conf.daethblock ||
            game_state.array[y][random_x] == game_conf.solidb ||
            game_state.array[y][random_x] == game_conf.rpoint) {
            random_x = rand() % game_state.length;
            game_state.raindbb[y][0] = random_x;
            game_state.raindbb[y][1] = 1;
            game_state.array[y][random_x] = game_conf.daethblock;
        } else {
            game_state.array[y][random_x] = game_conf.daethblock;
        }
        game_state.raindb_x = y;
        game_state.raindb_y = random_x;
        raindb();
        /*for(int j = 4; j < game_state.width; j++) {
            game_state.array[j][random_x] = game_conf.daethblock;
            game_state.array[j - 1][random_x] = ' ';
        }*/
       // int j = 1;
//        int arz_zamin = game_state.width;
//        while(arz_zamin > 0) {
//            game_state.array[y + 1][random_x] = game_conf.daethblock;
//            game_state.array[y][random_x] = ' ';
//            arz_zamin--;
//
//        }

    }
//        game_state.array[y][random_x] = ' ';
//        game_state.array[y + 1][random_x] = game_conf.daethblock;
//    }
}
//    int i = 0;
//    int j = 1;
//    int n = game_conf.raindb;
//    int y = 1;
//    int random_x = rand() % game_state.width;
//    int flag = n;
//    while(n > 0) {
//        //for (i = 0; i <= flag; i++) {
//        game_state.array[y + j][random_x] = game_conf.daethblock;
//        j++;
//        game_state.array[y][random_x] = ' ';
//        n--;
//        if(game_state.array[random_x][random_y + j] == ' ') {
//            game_state.array[random_x][random_y + j] = game_conf.daethblock;
//        }


int raindb() {
    int arz_zamin = game_state.length;
    while(arz_zamin > 0) {
        game_state.array[game_state.raindb_x + 1][game_state.raindb_y] = game_conf.daethblock;
        game_state.array[game_state.raindb_x][game_state.raindb_y] = ' ';
        arz_zamin--;

    }
}
/* attack mizane jlosho khali mikone */
int attack() {
    int n = game_conf.attack;
    int i = 0;
    if (n > 0) {
        if (game_state.y_change == -1)
            game_state.array[game_state.x_pos][(game_state.y_pos) + game_conf.attack] = game_conf.daethblock;
        else if (game_state.y_change == 1)
            game_state.array[game_state.x_pos][(game_state.y_pos) - game_conf.attack] = game_conf.daethblock;
        else if (game_state.x_change == 1)
            game_state.array[game_state.x_pos - game_conf.attack][(game_state.y_pos)] = game_conf.daethblock;
        else if (game_state.x_change == -1)
            game_state.array[game_state.x_pos + game_conf.attack][(game_state.y_pos)] = game_conf.daethblock;
        n--;
    }
}


void opp() {
    while (game_state.opp_y != game_state.target_y) {
        if (game_state.opp_y > game_state.target_y) {
            --game_state.opp_y;
        } else
            ++game_state.opp_y;
    }

    while (game_state.opp_x != game_state.target_x) {
        if (game_state.opp_x > game_state.target_x) {
            --game_state.opp_x;
        } else
            ++game_state.opp_x;
    }

    if (game_state.opp_y == game_state.target_y && game_state.opp_x == game_state.target_x) {
        printf("THE COMPUTER WON");
    }
}

int show_map() {

    int i = 2;


    //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);

    // int ch;
    //random_deathblock();
    //raindb();
    while (i < game_state.width + 2) {
        puts(game_state.array[i]);
        i++;
//        putchar(game_state.array[i][j]);
//        ch = game_state.array[i][j];
//        ++j;
//        if (ch == '\n') {
//            ++i;
//            j = 0;
//        }
    }
    system("COLOR 3");
    //random_deathblock();

    movement_1();

}