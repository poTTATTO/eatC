//전역 변수 초기화

#include<stdio.h>

int global;

int function(){
    global++;
    return 0;
}

int main(){
    function();
    printf("%d\n",global);
    return 0;
}