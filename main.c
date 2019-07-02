#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "menu.h"
#include "read_file.h"
#include "Gameread.h"
#include "gameconf.h"
#include "functions.h"
extern struct game_conf_struct game_conf;
void welcome(){
    printf("   ____                        ____ __________ _____       ___________  ___________ ___          ____ __________ \n"
           "   \\   \\          __          /   /|          ||   |      |          ||   _____   ||   \\        /   ||          |\n"
           "    \\   \\        /  \\        /   / |    ______||   |      |    ______||  |     |  ||    \\      /    ||    ______|\n"
           "     \\   \\      /    \\      /   /  |   |______ |   |      |   |       |  |     |  ||     \\    /     ||   |______ \n"
           "      \\   \\    /      \\    /   /   |          ||   |      |   |       |  |     |  ||      \\__/      ||          |\n"
           "       \\   \\  /   /\\   \\  /   /    |    ______||   |      |   |       |  |     |  ||   |\\      /|   ||    ______|\n"
           "        \\   \\/   /  \\   \\/   /     |   |_______|   |____ _|   |______ |  |     |  ||   | \\____/ |   ||   |_______\n"
           "         \\      /    \\      /      |          ||         ||          ||  |_____|  ||   |        |   ||          |\n"
           "          \\____/      \\____/       |__________||_________||__________||___________||___|        |___||__________|\n");

    printf("\n\n               LOADING ...");
    int i;

    for ( i = 0; i < 70; ++i) {
        printf("|");
        wait(0.05);
    }
}
int main() {
    //welcome();
    main_menu();
//    game_read();
//    read_file();
//    game_time(game_conf.time);
  // printf("Hello, World!\n");
//    while(kbhit()){
//        char c ;
//
//    }



}