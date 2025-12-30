#include<stdio.h>

int main(){

    char array[100][30];

    char (*parray)[30] = array;

    fgets(parray[3], 30, stdin);

    printf("%s", parray[3]);
    printf("%c\n", *parray[3]);
    printf("%c\n", parray[3][0]);
    printf("%c\n", parray[3][1]);

    return 0;
}