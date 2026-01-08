#include<stdio.h>

int main(){
    FILE* fp = fopen("a.txt","w");
    if(fp == NULL) return 0;

    fputs("hello world", fp);

    fclose(fp);

    fp = fopen("a.txt","r");
    if(fp == NULL) return 0;

    char c;
    int cnt=0;
    while((c=fgetc(fp)) != EOF){
        ++cnt;
    }

    printf("파일의 크기는 %d bytes\n", cnt);

    fclose(fp);
    return 0;


}