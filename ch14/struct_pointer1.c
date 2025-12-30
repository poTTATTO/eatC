#include<stdio.h>

struct test{
    int a, b;
};

int main(){
    struct test st;
    struct test *ptr;

    ptr = &st;

    (*ptr).a = 1;
    (*ptr).b = 2;

    ptr->a = 2;
    ptr->b = 1;

    printf("%d\n",st.a);
    printf("%d\n", st.b);
    return 0;
}