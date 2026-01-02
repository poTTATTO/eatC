// 멤버 쉽게 초기화
#include<stdio.h>

int print_status(struct Human human);
struct Human{
    int age;
    int height;
    int weight;
    int gender;
}Adam = {31,182,75,0}, Eve = {27,166,48,1};
//근데 이건 전역이라 문제가 생길 수 있음

