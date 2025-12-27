#include<stdio.h>

int main(){
    int num;
    char name[20];
    
    fscanf(stdin, "%d %19s", &num, name);

    printf("나이 : %d\n", num);
    printf("이름 : %s\n", name);

    return 0;
}
