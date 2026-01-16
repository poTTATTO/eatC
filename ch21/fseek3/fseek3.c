#include<stdio.h>

int main(){
    FILE* fp = fopen("some_data.txt", "r");
    char data[10];
    char c;

    if(fp == NULL){
        printf("file open error!\n");
        return 0;
    }

    fseek(fp, -1, SEEK_END);
    c=fgetc(fp);
    printf("파일의 마지막 문자 : %c\n",c);

    fclose(fp);

    return 0;
}