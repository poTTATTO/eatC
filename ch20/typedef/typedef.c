#include<stdio.h>

int main(){
    int input;
    int a,b;

    while(1){
        printf("--- 계산기 ---\n");
        puts("1. 덧셈");
        puts("2. 뺄셈");
        puts("3. 종료");

        scanf("%d",&input);

        switch(input){
            case 1: 
                printf("두 수 : "); 
                scanf("%d%d", &a, &b);
                printf("%d 와 %d 의 합 %d\n",a,b,a+b);
                break;
            case 2:
                printf("두 수 : "); 
                scanf("%d%d", &a, &b);
                printf("%d 와 %d 의 차 %d\n",a,b,a-b);
                break;
            default: break;
            }

        }

    return 0;
}