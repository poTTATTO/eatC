#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv){

    char* endp;

    int first = strtol(argv[1], &endp, 10);
    int second = strtol(argv[3], &endp, 10);

    if('+' == *argv[2])
        printf("%d\n", first + second);
    else if('-' == *argv[2])
        printf("%d\n", first - second);
    else if('/' == *argv[2] && second != 0)
        printf("%f\n", (double)first/second);
    else if('*' == *argv[2])
        printf("%d\n", first * second);

    return 0;
}