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
        } else if (key == game_conf.put) {
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
        else if (key == 224) {
            char ch;
            ch = getch();
            if(ch == 72) {
                for(int i = 1; i <= game_conf.attack; i++) {
                    game_state.array[game_state.x_pos - i][game_state.y_pos] = ' ';
                }
            }
            else if(ch == 80) {
                for(int i = 1; i <= game_conf.attack; i++) {
                    game_state.array[game_state.x_pos + i][game_state.y_pos] = ' ';
                }
            }
            else if(ch == 77) {
                for(int i = 1; i <= game_conf.attack; i++) {
                    game_state.array[game_state.x_pos][game_state.y_pos + i] = ' ';
                }
            }
            else if(ch == 75) {
                for(int i = 1; i <= game_conf.attack; i++) {
                    game_state.array[game_state.x_pos][game_state.y_pos - i] = ' ';
                }
            }
        }


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
    int flag = 0;
    while (time_left > 0) {
        x_countTime = clock(); // update timer difference
        x_milliseconds = x_countTime - x_startTime;
        x_seconds = (x_milliseconds / (CLOCKS_PER_SEC));//-(x_minutes*60);
        time_left = count_down_time_in_secs - x_seconds; // subtract to get difference

        //fflush(stdout);
        system("cls");
        /* if there were a Solidblock or a wall */
        if (game_conf.raindb!=0)
            raindb();

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
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

            getchar();
            getchar();
            break;
        }

            /* if the character richs the target it will win */
        else if (game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos + game_state.y_change] ==
                 game_conf.target) {
            system("cls");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            printf("YOU WON :)");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

            getchar();
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
                    game_conf.daethblock || game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos +
                                                                                                     game_state.y_change +
                                                                                                     1] ==
                                            game_conf.target ||
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

            /* Object to the Target */
        else if (game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos + game_state.y_change] ==
                 game_conf.object) {
//            while (game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos + game_state.y_change] !=
//                   game_conf.target) {
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
                    game_conf.rpoint) {
                    game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos +
                                                                             game_state.y_change] = game_conf.object;
                } else {
                    game_state.array[game_state.x_pos + game_state.x_change + 1][game_state.y_pos +
                                                                                 game_state.y_change] = game_conf.object;
                    game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos +
                                                                             game_state.y_change] = game_conf.character;
                    game_state.array[game_state.x_pos + game_state.x_change - 1][game_state.y_pos +
                                                                                 game_state.y_change] = ' ';
                    if(game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos + game_state.y_change] == game_conf.target) {
                        system("cls");
                        printf("OBJECT GOT THE TARGET!");
                    }

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
                    game_conf.rpoint) {
                    game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos +
                                                                             game_state.y_change] = game_conf.object;
                } else {
                    game_state.array[game_state.x_pos + game_state.x_change - 1][game_state.y_pos +
                                                                                 game_state.y_change] = game_conf.object;
                    game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos +
                                                                             game_state.y_change] = game_conf.character;
                    game_state.array[game_state.x_pos + game_state.x_change + 1][game_state.y_pos +
                                                                                 game_state.y_change] = ' ';
                    if(game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos + game_state.y_change] == game_conf.target) {
                        system("cls");
                        printf("OBJECT GOT THE TARGET!");
                    }

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
                                                                             game_state.y_change] = game_conf.object;
                } else {
                    game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos +
                                                                             game_state.y_change +
                                                                             1] = game_conf.object;
                    game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos +
                                                                             game_state.y_change] = game_conf.character;
                    game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos +
                                                                             game_state.y_change - 1] = ' ';
                    if(game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos + game_state.y_change] == game_conf.target) {
                        system("cls");
                        printf("OBJECT GOT THE TARGET!");
                    }

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

                    game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos +
                                                                             game_state.y_change -
                                                                             1] ==
                    game_conf.rpoint) {
                    game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos +
                                                                             game_state.y_change] = game_conf.object;
                } else {
                    game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos +
                                                                             game_state.y_change -
                                                                             1] = game_conf.object;
                    game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos +
                                                                             game_state.y_change] = game_conf.character;
                    game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos +
                                                                             game_state.y_change + 1] = ' ';
                    if(game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos + game_state.y_change] == game_conf.target) {
                        system("cls");
                        printf("OBJECT GOT THE TARGET!");
                    }

                }
            }
//            if(game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos + game_state.y_change] == game_conf.target) {
//                system("cls");
//                printf("OBJECT GOT THE TARGET!");
            //}
        }
            //}
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

        else if (game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos +
                                                                          game_state.y_change] ==
                 game_conf.rpoint) {
            game_state.array[game_state.x_pos + game_state.x_change][game_state.y_pos +
                                                                     game_state.y_change] = game_conf.character;
            game_state.array[game_state.x_pos][game_state.y_pos] = ' ';
            random_point(1);
            game_conf.userscore+=game_conf.rpoint_score;
            //printf("%d", game_conf.rpoint_score);
        }


            /* if the block is an object block the thing I understood is that object and the target are the same:/ */
            /* Or maybe it is some thing that it should move toward the target:/ */




        else {
            game_state.y_pos += game_state.y_change;
            game_state.x_pos += game_state.x_change;
            game_state.array[game_state.x_pos][game_state.y_pos] = game_conf.character;
            game_state.array[game_state.x_pos - game_state.x_change][game_state.y_pos -
                                                                     game_state.y_change] = ' ';
        }

        show_map();


        printf("\nTime remaining %.2f ", time_left);
        wait(0.02);
    }


}


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



int random_deathblock() {
    int y = 4;
    int random_x = 0;
    int i = 0;

    for (i = 0; i < game_conf.raindb; i++) {
        random_x = rand() % game_state.length;
        if (random_x == 0) {
            random_x = rand() % game_state.length;
        }
        game_state.raindbb[i][0] = 4;
        game_state.raindbb[i][1] = random_x;

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

//
        }


    }
    game_state.raindb_x = y;
    game_state.raindb_y = random_x;


}

////////////////////////////////////////////////rain
int raindb() {

    for (int i = 0; i < game_conf.raindb; i++) {

        if(game_state.raindbb[i][0] >= game_state.width) {
            game_state.array[game_state.raindbb[i][0]][game_state.raindbb[i][1]] = ' ';
            game_state.raindbb[i][0]=4;
            game_state.array[game_state.raindbb[i][0]][game_state.raindbb[i][1]] = game_conf.daethblock;

        } else {
            if(game_state.array[game_state.raindbb[i][0] + 1][game_state.raindbb[i][1]] != game_conf.wall || game_state.array[game_state.raindbb[i][0] + 1][game_state.raindbb[i][1]] != game_conf.solidb) {
                game_state.raindbb[i][0]++;
                game_state.array[game_state.raindbb[i][0]][game_state.raindbb[i][1]] = game_conf.daethblock;
                game_state.array[game_state.raindbb[i][0] - 1][game_state.raindbb[i][1]] = ' ';
            }

        }

    }


}

/* attack mizane jlosho khali mikone */
int attack() {
    int n = game_conf.attack;
    int i = 0;
    while (n > 0) {
        if (game_state.y_change == -1)
            game_state.array[game_state.x_pos][(game_state.y_pos) + game_conf.attack] = ' ';
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
            game_state.array[game_state.opp_x][game_state.opp_y] = game_conf.opp;
        } else
            ++game_state.opp_y;
        game_state.array[game_state.opp_x][game_state.opp_y] = game_conf.opp;
    }

    while (game_state.opp_x != game_state.target_x) {
        if (game_state.opp_x > game_state.target_x) {
            --game_state.opp_x;
            game_state.array[game_state.opp_x][game_state.opp_y] = game_conf.opp;
        } else
            ++game_state.opp_x;
        game_state.array[game_state.opp_x][game_state.opp_y] = game_conf.opp;
    }

    if (game_state.opp_y == game_state.target_y && game_state.opp_x == game_state.target_x) {
        printf("THE COMPUTER WON");
    }
}

int show_map() {

    int i = 2;
    int j = 3;

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
//    system("COLOR 3");
    //random_deathblock();
    printf("       score : %d",game_conf.userscore);
    movement_1();
    //opp();

}