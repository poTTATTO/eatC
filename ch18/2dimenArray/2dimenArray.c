#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int x, y;
    char* endPtr;
    char temp[10];
    fgets(temp, sizeof(temp), stdin);
    x = strtol(temp, &endPtr, 10);
    int** array = (int**)malloc(sizeof(int*) * x);
    
    memset(temp, 0, sizeof(char) * 10);

    fgets(temp, sizeof(temp), stdin);
    y = strtol(temp, &endPtr, 10);

    for(int i=0; i<x; i++){
        array[i] = (int*)malloc(sizeof(int) * y);
    }
    int cnt = 0;

    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            array[i][j] = ++cnt;
        }
    }
    
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            printf("%4d",array[i][j]);
        }
        putchar('\n');
    }

    //free 반드시

    for(int i=0; i<x; i++){
        free(array[i]);
    }

    free(array);

    //free 반드시

    return 0;





    

}