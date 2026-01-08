#include<stdio.h>

int main(){
    FILE* fp = fopen("a.txt","r");

    char c;

    while((c=fgetc(fp)) != EOF){
        printf("%c", c);
    }

    fclose(fp);
    return 0;
}