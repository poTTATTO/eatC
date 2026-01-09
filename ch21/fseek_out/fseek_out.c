#include<stdio.h>

int main(){
    FILE* fp = fopen("a.txt", "w");
    fputs("babmaba is an excellent C programmer",fp);
    fseek(fp, 0, SEEK_SET);
    fputs("is babamba",fp);
    fclose(fp);

    return 0;
}