#include<stdio.h>

int main(){
    FILE* fp = fopen("a.txt", "r");

    fgetc(fp);
    fgetc(fp);
    fgetc(fp);
    fgetc(fp);

    fseek(fp, 0, SEEK_SET);
    printf("다시 파일 처음에서 입력 받는다면 : %c\n", fgetc(fp));

    fclose(fp);
    return 0;
}