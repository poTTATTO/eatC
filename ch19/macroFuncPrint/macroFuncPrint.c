#include<stdio.h>
#define PrintVariableName(var) printf(#var "\n");


int main(int argc, char** argv){
    int a;
    PrintVariableName(a);

    return 0;
}