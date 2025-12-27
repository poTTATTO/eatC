#include<stdio.h>

void reverse(char* str, int str_size);

int main(){
    char str[100];

    fscanf(stdin, "%99[^\n]s", str);

    reverse(str,sizeof(str));

    return 0;

}

void reverse(char* str, int str_size){
    if(str==NULL)
        return;
    
    int i=0;
    while(str[i] != '\0'&& i < str_size -1){
        i++;
    }

    for(i = i-1; i>=0; i--){
        printf("%c",str[i]);
    }
    putchar('\n');
    
}