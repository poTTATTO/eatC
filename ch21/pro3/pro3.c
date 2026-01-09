#include<stdio.h>

int main(){
    FILE* fpa = fopen("a.txt", "r");
    FILE* fpb = fopen("b.txt", "w");

    fseek(fpa, 0, SEEK_END); 
    int endA = ftell(fpa); //인덱스라 fseek 두번째 인자가 0임
    fseek(fpa, -1, SEEK_END);
    int ch;
    for(int i=0; i<endA; i++){
        fseek(fpa, -1 -i, SEEK_END);
        ch = fgetc(fpa);
        fputc(ch, fpb);
     }

    fclose(fpa);
    fclose(fpb);

    return 0;

}