#include<stdio.h>

char* change_up_low(char* str, int str_size);
int main(){
    char str[100];

    fscanf(stdin, "%99[^\n]s", str);

    printf("%s\n", change_up_low(str, sizeof(str)));

    return 0;
}

char* change_up_low(char* str, int str_size){
    
    if(str == NULL)
        return NULL;
    int i=0;
    
    while(i < str_size -1 && str[i] != '\0'){
        int diff = 'a' - 'A';
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = str[i] + diff;
        }
        else if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] = str[i] - diff;
        }
        i++;
    }

    return str;
}