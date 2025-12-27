#include<stdio.h>

char inputOperator(); 
double inputNumber();
void plus(double*,double);
void minus(double*,double);
void multiply(double*,double);
void divide(double*,double);
void checkOp(char op, double* sum, double num);

int main(){
    double sum = 0;
    char op;
    double num;
    printf("%s","계산기 프로그램입니다.\n");

    while(1){

         printf("현재 값 : %f \n",sum);

        
        printf("%s", "곱하기 : *\n나누기 : /\n현재 값 초기화 : c\n예시 : + 2 or * 10\n : ");
        scanf(" %c %lf",&op, &num);
        
        checkOp(op, &sum, num);

        putchar('\n');
        printf("현재 값 : %f \n",sum);
       

        printf("%s","계속하려면 아무 키나 입력하고 끝내내면 q를 입력하세요 : ");
        scanf(" %c",&op);
        if(op == 'q') break;
       while(getchar() != '\n'); 
    }

    return 0;

}

void plus(double* sum, double num){
    *sum+=num;
}
void minus(double* sum, double num){
    *sum-=num;
}
void multiply(double* sum, double num){
    *sum *= num;
}
void divide(double* sum, double num){
    while(num<=0){
        printf("0보다 큰 값을 입력하세요 : ");
        scanf("%lf",&num);
    }

    *sum/=num;
}

void checkOp(char op, double* sum, double num){
    while(1){
    switch (op){
        case '+': plus(sum,num); break;
        case '-': minus(sum,num); break;
        case '*': multiply(sum,num); break;
        case '/': divide(sum,num); break;
        case 'c': *sum=0; break;
        default: printf("잘못된 입력!"); break;
        }
    break;   
    }
}

char inputOperator(){
    char op;

    scanf("%c",&op);

    return op;
}
