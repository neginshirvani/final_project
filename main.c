#include <stdio.h>
#include "read_file.h"
#include "Gameread.h"
#include "gameconf.h"
#include "functions.h"
#include <conio.h>
#include "menu.h"
extern struct game_conf_struct game_conf;

int main() {
    main_menu();
    game_read();
    read_file();
    game_time(game_conf.time);


    // printf("Hello, World!\n");
//    while(kbhit()){
//        char c ;
//
//    }
    return 0;

}