#include<stdio.h>

int add(int a, int b) { return a + b;}
typedef int CAL_TPYES;         //  int를 CAL_TYPES로 별칭
typedef int (*Padd)(int, int); //  반환값이 int이고 인자 타입이 int, int인 함수 포인터를 
                               // Padd로 별칭
typedef int Arrays[30]; //int[30]짜리 배열을 Arrays로 별칭

int main(){
    CAL_TPYES a = 10;
    Arrays arr = {1,2,3,4,5,6,7,8,9,0};
    Padd ptr = add;

    printf("a : %d\n",a);
    printf("arr[3] : %d\n", arr[3]);
    printf("add(3,5) : %d\n", ptr(3,5));

    return 0;
}