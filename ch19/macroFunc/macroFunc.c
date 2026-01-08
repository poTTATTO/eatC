#include<stdio.h>
#define square(x)(x*x)


int main(int argc, char** argv){
    // printf("square(3) : %d\n", square(3));

    // printf("square(3) : %d\n", square(3 + 1));
    printf("1 / square(3) : %f", 1.0 / square(2));
    return 0;
}