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
int a[3];
char key[2];
void sep(char inp[]){

    char b;
    int j=0;
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

    while(inp[i]!='\0'){

        if(inp[i]>='0' && inp[i]<='9'){

            a[j]=inp[i];
            j++;
            i++;

        }
        else{
            key[c]=inp[i];

            i++;
            c++;
        }

    }

}
void fill_info(){
    if(strcmp(key_name,"solidblock")==0||strcmp(key_name,"solid_block")==0) {
        game_conf.solidb = key[0];
        printf("%c",game_conf.solidb);

    }
    if(strcmp(key_name,"deathblock")==0||strcmp(key_name,"death_block")==0) {
        game_conf.daethblock = key[0];
        printf("%c",game_conf.daethblock);
    }
    if(strcmp(key_name,"moveblock")==0||strcmp(key_name,"move_block")==0){
        game_conf.moveblock=key[0];
        printf("%c",game_conf.moveblock);
    }
    ///
    if(strcmp(key_name,"wall")==0){
        game_conf.wall=key[0];
        printf("%c",game_conf.wall);
    }
    if(strcmp(key_name,"up")==0){
        game_conf.up=key[0];
        printf("%c",game_conf.up);
    }
    if(strcmp(key_name,"down")==0){
            game_conf.down=key[0];
        printf("%c",game_conf.down);
    }
    if(strcmp(key_name,"left")==0){
        game_conf.left=key[0];
        printf("%c",game_conf.left);
    }
    if(strcmp(key_name,"right")==0){
        game_conf.right=key[0];
        printf("%c",game_conf.right);
    }
    if(strcmp(key_name,"target")==0){
        game_conf.target=key[0];
        printf("%c",game_conf.target);
    }
    if(strcmp(key_name,"character")==0){
        game_conf.character=key[0];
        printf("%c",game_conf.character);
    }
    if(strcmp(key_name,"object")==0){
        game_conf.object=key[0];
        printf("%c",game_conf.object);
    }
//    if(strcmp(key_name,"put")==0){
//        game_conf.put=key;
//        printf("%c",game_conf.put);
//    }
//    if(strcmp(key_name,"exit")==0){
//        printf("\nrape\n");
//        game_conf.exitt=key;
//        printf("%c",game_conf.exitt);
//    }


}
void game_read(){

    FILE *file=fopen("game-pacman.txt","r");
    char line[30];
    char b;
    int i=0;
    while((b=fgetc(file))!=EOF){

        if((b!=' ')&&(b!='\n')){

            line[i]=b;
            printf("y");
            i++;
        }

        else if (b=='\n'){
            line[i]='\0';

            sep(line);
            fill_info();
            i=0;

        }
        break;

    }

}
