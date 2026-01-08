#include<stdio.h>
#include<string.h>

int main(){
    int arr[10] = {1,2,3,4,5};
    int arr2[10] = {1,2,3,4,5};

    if(memcmp(arr,arr2,5)==0){
        puts("일치");
    }else
        puts("불일치");

    return 0;
}