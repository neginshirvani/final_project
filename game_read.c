#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
char key_name [20];
int a[3];
char key;
void sep(char inp[]){

    char b;
    int j=0;
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

            key=inp[i];

            i++;
        }

    }

}
void fill_info(){
    if(strcmp(key_name,"solidblock")==0||strcmp(key_name,"solid_block")==0) {
        solidb = key;
        printf("%c",solidb);

    }
    if(strcmp(key_name,"deathblock")==0||strcmp(key_name,"death_block")==0) {
        daethblock = key;
        printf("%c",daethblock);
    }
    if(strcmp(key_name,"moveblock")==0||strcmp(key_name,"move_block")==0){
        moveblock=key;
        printf("%c",moveblock);
    }
    //////////////////////////////
    if(strcmp(key_name,"rpoint")==0){
        moveblock=key;
        printf("%c",moveblock);
    }
    if(strcmp(key_name,"moveblock")==0||strcmp(key_name,"move_block")==0){
        moveblock=key;
        printf("%c",moveblock);
    }
    if(strcmp(key_name,"moveblock")==0||strcmp(key_name,"move_block")==0){
        moveblock=key;
        printf("%c",moveblock);
    }

}
int main(){

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

}
