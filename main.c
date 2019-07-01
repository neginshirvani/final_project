#include <stdio.h>
#include "read_file.h"
#include "Gameread.h"
#include "gameconf.h"
#include "functions.h"
#include <conio.h>
extern struct game_conf_struct game_conf;

int main() {
    
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