//
// Created by alisa on 6/29/2019.
//

#ifndef C_FINAL_PROJECT_GAMECONF_H
#define C_FINAL_PROJECT_GAMECONF_H

#endif //C_FINAL_PROJECT_GAMECONF_H
struct game_conf_struct {
    char solidb; //stop player move
    char daethblock; // player lose the game
    int raindb; // number of death block in game
    char moveblock; // player can push this block
    char wall; //wall
    char up, down, left, right; // movement
    char character; //player's char
    char target; // the goal that if specified obj reaches it player win
    char object; // win obj
    int  attack; //
    char exitt; // exit key
    char put; // if player enter this char one deathblock place in it's pos
    int put_num; // specified how mane put player can enter
    char opp; // enemy char
    char rpoint; // shape of rpoint
    int rpoint_num,rpoint_score; // rpoint info
    int time; // time of game


    int theme_num;

};

struct game_state_struct{
    int x_pos;
    int y_pos;
    int x_change;
    int y_change;
    char array[1000][1000];
    int width;
    int length;
    int target_x;
    int target_y;
    int opp_x;
    int opp_y;
    int raindbb[100][2];
    int raindb_x;
    int raindb_y;

};
