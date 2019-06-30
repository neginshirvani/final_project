//
// Created by alisa on 6/29/2019.
//

#include "Gameread.h"
#include "gameconf.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern struct game_conf_struct game_conf;
char key_name [20];
int key_number;
char key[30];
void sep(char inp[]){

    char b;
    int c=0;
    int i;
    for ( i = 0; inp[i]!='='; ++i) {
        key_name[i]=inp[i];
    }
    key_name[i]='\0';
    int k=0;
    for(k=0;key_name[k]!='\0';k++) {
        if (key_name[k] >= 'A' && key_name[k] <= 'Z') {
            key_name[k] = key_name[k] + 32;
        }
    }
    i++;
    key_number=0;
    while(inp[i]!='\0'){

        key[c]=inp[i];
        i++;
        c++;
//        if(inp[i]>='0' && inp[i]<='9'){
//
//            key_number=key_number * 10 + inp[i]- '0';
//
//            i++;
//
//        }
//        else{
//            if (inp[i]==',')
//                i++;
//            key[c]=inp[i];
//
//            i++;
//            c++;
//        }


    }
    key[c] = '\0';

}
void fill_info(){
    if(strcmp(key_name,"solidblock")==0||strcmp(key_name,"solid_block")==0) {
        game_conf.solidb = key[0];
        // printf("%c\n",game_conf.solidb);
    }
    else if(strcmp(key_name,"deathblock")==0||strcmp(key_name,"death_block")==0) {
        game_conf.daethblock = key[0];
        // printf("%c\n",game_conf.daethblock);
    }
    else if(strcmp(key_name,"moveblock")==0||strcmp(key_name,"move_block")==0){
        game_conf.moveblock=key[0];
        // printf("%c\n",game_conf.moveblock);
    }
    else if(strcmp(key_name,"wall")==0){
        game_conf.wall=key[0];
        // printf("%c\n",game_conf.wall);
    }
    else if(strcmp(key_name,"up")==0){
        game_conf.up=key[0];
        // printf("%c\n",game_conf.up);
    }
    else if(strcmp(key_name,"down")==0){
        game_conf.down=key[0];
        // printf("%c\n",game_conf.down);
    }
    else if(strcmp(key_name,"left")==0){
        game_conf.left=key[0];
        // printf("%c\n",game_conf.left);
    }
    else if(strcmp(key_name,"right")==0){
        game_conf.right=key[0];
        // printf("%c\n",game_conf.right);
    }
    else if(strcmp(key_name,"target")==0){
        game_conf.target=key[0];
        // printf("%c\n",game_conf.target);
    }
    else if(strcmp(key_name,"character")==0){
        game_conf.character=key[0];
        // printf("%c\n",game_conf.character);
    }
    else if(strcmp(key_name,"object")==0){
        game_conf.object=key[0];
        // printf("%c\n",game_conf.object);
    }
    else if(strcmp(key_name,"time")==0){
        int i=0;
        key_number=0;
        while(key[i]!='\0'){
            if(key[i]>='0' && key[i]<='9'){

                key_number=key_number * 10 + key[i]- '0';

                i++;

            }
        }

        game_conf.time=key_number;
        //printf("%d\n",game_conf.time);
    }

    else if(strcmp(key_name,"rpoint")==0||strcmp(key_name,"e_point")==0) {
        int i = 0;
        game_conf.rpoint = key[i];
        i += 2;
        // printf("%c\n",game_conf.rpoint);
        key_number=0;
        while (key[i]!=','){
            if(key[i]>='0' && key[i]<='9'){

                key_number=key_number * 10 + key[i]- '0';

                i++;

            }

        }
        game_conf.rpoint_score=key_number;
        //printf("%d\n",game_conf.rpoint_score);
        key_number=0;
        i++;
        while (key[i]!='\0'){
            if(key[i]>='0' && key[i]<='9'){

                key_number=key_number * 10 + key[i]- '0';

            }

            i++;

        }
        game_conf.rpoint_num=key_number;
        //printf("%d\n",game_conf.rpoint_num);

    }


    else if(strcmp(key_name,"opp")==0){
        game_conf.opp=key[0];
        // printf("%c\n",game_conf.opp);
    }

    else if(strcmp(key_name,"attack")==0){
        int i=0;
        key_number=0;

        while (key[i]!='\0'){
            if(key[i]>='0' && key[i]<='9'){

                key_number=key_number * 10 + key[i]- '0';

            }

            i++;

        }
        game_conf.attack=key_number;
        //printf("%d\n",game_conf.attack);
    }

    else if(strcmp(key_name,"put")==0){
        int i=0;
        game_conf.put=key[i];
        // printf("%c\n",game_conf.put);
        key_number=0;
        i+=2;
        while (key[i]!='\0'){
            if(key[i]>='0' && key[i]<='9'){

                key_number=key_number * 10 + key[i]- '0';

            }

            i++;

        }
        game_conf.put_num=key_number;
        //printf("%d\n",game_conf.put_num);
    }


    else if(strcmp(key_name,"raindb")==0){
        game_conf.exitt=key[0];
        int i=0;
        key_number=0;
        while(key[i]!='\0'){
            if(key[i]>='0' && key[i]<='9'){

                key_number=key_number * 10 + key[i]- '0';

                i++;

            }
        }
        game_conf.raindb=key_number;
        //printf("%d\n",game_conf.raindb);
    }

    else if(strcmp(key_name,"exit")==0){
        game_conf.exitt=key[0];
        // printf("%c\n",game_conf.exitt);
    }


}
void game_read(){

    FILE *file=fopen("game-pacman.txt","r");
    char line[30];
    char b;
    int i=0;
    while((b=fgetc(file))!=EOF){

        if((b!=' ')&&(b!='\n')){

            line[i]=b;

            i++;
        }

        else if (b=='\n'){
            line[i]='\0';

            sep(line);
            fill_info();
            i=0;

        }

    }

    line[i]='\0';

    sep(line);
    fill_info();

}
