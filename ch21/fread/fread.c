#include<stdio.h>

int main(){
    FILE* fp = fopen("a.txt", "r");
    char buf[20];

    if(fp == NULL){
        printf("READ ERROR!! \n");
        return 0;
    }
    fgets(buf, 20, fp);
    printf("입력받은 내용 : %s\n", buf);
    fclose(fp);

    return 0;
}