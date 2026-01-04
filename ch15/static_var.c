#include<stdio.h>
int* function(){
    static int a;
    return &a;
}

int main(){
    int* pa = function();
    printf("%d\n", *pa);
    return 0;
}