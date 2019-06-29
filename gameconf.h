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
    char attack; //
    char exitt; // exit key
    char put; // if player enter this char one deathblock place in it's pos
    int put_num; // specified how mane put player can enter
    char opp; // enemy char
    char rpoint; // shape of rpoint
    int rpoint_num,rpoint_score; // rpoint info
    int time; // time of game
};

struct game_state_struct{
    int x;
    int y;
};