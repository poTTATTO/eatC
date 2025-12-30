#include<stdio.h>

struct TEST{
    int c;
    int* pointer;
};


int main(){
    struct TEST t;
    struct TEST* ptr = &t;

    int i=0;

    t.pointer = &i;

    *t.pointer = 3;

    printf("i : %d\n",i);

    *ptr->pointer = 4;

    printf("i : %d\n",i);

    return 0;
}