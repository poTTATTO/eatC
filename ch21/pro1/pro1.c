#include<stdio.h>
#include<string.h>

int main(){
    char path[30];
    printf("경로를 입력하시옹그르르 움씻 : "); 


    if(fgets(path, sizeof(path), stdin) == NULL){
        return 1;
    }
    path[strcspn(path, "\n")] = '\0';
    FILE* fp = fopen(path, "w");
    if(fp == NULL){
        return 1;
    }

    fputs("a", fp);

    fclose(fp);
    return 0;
    
}