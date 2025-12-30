#include<stdio.h>

struct Human{
    int age;
    int height;
    int weight;
};

int main(){
    struct Human Babamba;

    Babamba.age = 99;
    Babamba.height = 185;
    Babamba.weight = 80;

    printf("나이 : %d\n", Babamba.age);
    printf("키 : %d\n",Babamba.height);
    printf("몸무게 : %d\n", Babamba.weight);

    return 0;
}