#include<stdio.h>

int main(){
    FILE* fp = fopen("some_data.txt", "r+");
    char c;

    if(fp == NULL){
        printf("안열림\n");
        return 0;
    }
    int diff = 'a'-'A';
    while((c=fgetc(fp)) != EOF){
        if(c >= 'a' && c<= 'z'){
            fseek(fp, -1, SEEK_CUR);
            fputc(c-diff, fp);
        /*
        쓰기 - 읽기 모드 전환을 위해서는 무조건 fseek 함수와 같은 
        파일 위치 지정자 설정 함수들을 호출 해야함
        */

        fseek(fp, 0, SEEK_CUR);
        }else if(c>= 'A' && c<='Z'){
            fseek(fp, -1, SEEK_CUR);
            fputc(c + diff, fp);
            fseek(fp, 0, SEEK_CUR);
        }
    }

    fclose(fp);

    return 0;
}