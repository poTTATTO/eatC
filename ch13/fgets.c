#include<stdio.h>

int main(){
    char str[10];

    if(fgets(str, sizeof(str), stdin)!=NULL){
        printf("%s\n",str);
    }

    return 0;
}