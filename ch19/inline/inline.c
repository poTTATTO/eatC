#include<stdio.h>

// static inline int square(int a){ return a* a;}
static inline int some_function(int a){
    if(a==0)
        return 1;
    else if(a==1)
        return 3;
    else{
        return a*2;
    }
}

int main(){
    int a=4;
    printf("%d\n", a==0? 1 : (a==1 ? 3 : a*2));
    return 0;
}