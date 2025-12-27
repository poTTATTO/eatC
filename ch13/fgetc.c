#include<stdio.h>

int main(){
    int ch;
    if((ch = fgetc(stdin)) != EOF){ //문자를 하나읽어 EOF가 아닐 때만 처리
        printf("입력 : %c\n",(char)ch); // fgetc의 반환형은 int이므로 형변환 필요
    }
    return 0;
}