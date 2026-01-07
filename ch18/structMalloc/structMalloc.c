#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Something{
    int a,b;
};

int main(){
    struct Something* p;
    char input[10];
    char* endPtr;
    
    int size, i;
    int num;
    do{

    fputs("원하는 배열의 크기 : ", stdout);
    fgets(input, sizeof(input), stdin);
    num = strtol(input, &endPtr, 10);
     if(input[strcspn(input, "\n")] == '\0'){
        while(getchar() != '\n');
    }
    
    input[strcspn(input, "\n")] = '\0';
    }while(num<=0);

    p = (struct Something*)malloc(sizeof(int) * num);

    for(int i=0; i<num; i++){
        printf("p[%d].a : ", i);
        memset(input, 0, sizeof(input));
        fgets(input, sizeof(input), stdin);
        p[i].a = strtol(input, &endPtr, 10);
        
        printf("p[%d].b : ", i);
        memset(input, 0, sizeof(input));
        fgets(input, sizeof(input), stdin);
        p[i].b = strtol(input, &endPtr, 10);
        
    }
    putchar('\n');
    for(int i=0; i<num; i++){
        printf("p[%d].a : %d\n", i, p[i].a);
        printf("p[%d].b : %d\n", i, p[i].b);
    }

    free(p);

    return 0;
}