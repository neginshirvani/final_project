


int length;
int width;


int arr[1000][1000];
int mapp(int y , int x){

    int i = 0 ;
    int j = 0 ;
    int z = 0 ;
    int k = 0 ;
    system("cls") ;


    for(i = 0 ; i < x + 1 ; ++i){
        arr[z][i] = '!' ;
    }
    z += 1 ;

    for (z = 1 ; z < y + 1 ; ++z) {
        arr[z][0] = '!' ;
        for(k = 1 ; k < x - 1 ; ++k){
                arr[z][k] = ' ' ;
        }
        arr[z][x - 1] = '!' ;
    }

    for(i = 0 ; i < x + 1 ; ++i){
        arr[z - 2][i] = '!' ;
    }


}

int show_mapp(int y , int x){
    system("cls") ;
    int i, j;
    for (j=0;j<y;++j){
        for (i=0;i<x;++i){
            putchar(arr[j][i]);
        }
        putchar('\n') ;
    }
}


int map_maker() {
    int length,width;
    FILE *file = fopen("map-pacman.txt", "r");
    fscanf(file, "%d", &length);
    fscanf(file, "%d", &width);
    fclose(file);
}

int main() {
   show_mapp(length, width);
}


