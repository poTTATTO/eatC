#include<stdio.h>

int main(){
    int ch;
    ch = getc(stdin);

    if(ch != EOF){
        printf("읽은 문자 : %c\n", ch);
    }

    return 0;
}