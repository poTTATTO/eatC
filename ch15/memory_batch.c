#include<stdio.h>

int global = 3;
int main(){
    int i;
    char* str = "Hello Baby";
    char arr[20] = "WHATTHEHECK";

    printf("global : %p\n",&global);
    printf("i : %p\n", &i);
    printf("str : %p\n", str);
    printf("arr : %p\n",arr);
    return 0;
}