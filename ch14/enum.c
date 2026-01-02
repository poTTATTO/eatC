//열거형
#include<stdio.h>

enum { RED, BLUE, WHITE, BLACK };
int main(){
    int palette = RED;
    switch(palette){
        case RED: 
            puts("palette : RED");
            break;
        case BLUE:
            puts("palette : BLUE");
            break;
        case WHITE:
            puts("palette : WHITE");
            break;
        case BLACK:
            puts("palette : BLACK");
            break;
    }

    return 0;
}