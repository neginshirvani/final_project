#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "menu.h"
#include "read_file.h"
#include "Gameread.h"
#include "gameconf.h"
#include "functions.h"
#include <windows.h>
extern struct game_conf_struct game_conf;
void welcome(){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    printf("   ____                        ____ __________ _____       ___________  ___________ ___          ____ __________ \n"
           "   \\   \\          __          /   /|          ||   |      |          ||   _____   ||   \\        /   ||          |\n"
           "    \\   \\        /  \\        /   / |    ______||   |      |    ______||  |     |  ||    \\      /    ||    ______|\n"
           "     \\   \\      /    \\      /   /  |   |______ |   |      |   |       |  |     |  ||     \\    /     ||   |______ \n"
           "      \\   \\    /      \\    /   /   |          ||   |      |   |       |  |     |  ||      \\__/      ||          |\n"
           "       \\   \\  /   /\\   \\  /   /    |    ______||   |      |   |       |  |     |  ||   |\\      /|   ||    ______|\n"
           "        \\   \\/   /  \\   \\/   /     |   |_______|   |_____ |   |______ |  |     |  ||   | \\____/ |   ||   |_______\n"
           "         \\      /    \\      /      |          ||         ||          ||  |_____|  ||   |        |   ||          |\n"
           "          \\____/      \\____/       |__________||_________||__________||___________||___|        |___||__________|\n");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    printf("\n\n               LOADING ...          ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    int i;

    for ( i = 0; i < 50; ++i) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN|BACKGROUND_GREEN);
        int j=i;
        printf("|");
        wait(0.05);
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}
int main() {
    game_conf.theme_num=15;
    for (int i = 0; i <50 ; ++i) {
        system("cls");
        welcome();
    }
    welcome();
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