#include<stdio.h>

int main(){
    int ch = fgetc(stdin);
    printf("%c\n",(char)ch);

    if(ch=='#'){ 
        ungetc(ch, stdin); //'#'이면 다시 버퍼에 넣기
        printf("%c",getchar());
    }

    return 0;
}