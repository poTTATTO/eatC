#include<stdio.h>

int main(){
    FILE* fp = fopen("a.txt","r");
    fgetc(fp);//1
    fgetc(fp);//2
    fgetc(fp);//3
    
    fseek(fp, 0, SEEK_END);
    printf("%c",fgetc(fp));

    return 0;
}