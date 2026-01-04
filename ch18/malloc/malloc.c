#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char** argv){
    int sizeOfArray;
    int* arr;
    char* end;
    char input[10];
    printf("만들고 싶은 배열의 원소의 수 : ");
    fgets(input, sizeof(input), stdin);
    sizeOfArray = (int)strtol(input, &end, 10);

    arr = (int*)malloc(sizeof(int) * sizeOfArray);
    printf("%d\n", sizeOfArray);
    free(arr);

    return 0;
}