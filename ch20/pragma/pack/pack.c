#include<stdio.h>
#pragma pack(1)
struct Weird{
    char arr[2];
    int i;
};

int main(){
    struct Weird a;
    printf("size of a :%ld\n", sizeof(a));

    return 0;
}