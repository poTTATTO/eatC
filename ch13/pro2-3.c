#include<stdio.h>

int same_str(char* str1, char* str2,int maxlen);

int main(){
    char str1[] = "hello";
    char str2[] = "hello";
    int maxlen = sizeof(str1)>sizeof(str2) ? sizeof(str1) : sizeof(str2);
    int flag = same_str(str1, str2, maxlen);
    if(1 == flag){
        printf("두 문자열이 같습니다.\n");
    }else if(0 == flag){
        printf("두 문자열이 다릅니다.\n");
    }else{
        printf("문자열이 잘못됐습니다.\n");
    }

    return 0;
}

int same_str(char* str1, char* str2, int maxlen){
    if(str1==NULL || str2==NULL)
        return -1;
    if(str1==str2)
        return 1;

    int count=0;
    while((*str1 || *str2) && count < maxlen){
        if(*str1 != *str2)
            return 0;
        str1++;
        str2++;
        count++;
    }

    if(count>=maxlen)
        return 0;

    return (*str1 == *str2);
}