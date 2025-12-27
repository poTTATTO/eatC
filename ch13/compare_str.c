#include<stdio.h>

int compare_str(char* str1, char* str2);

int main(){

    char str1[] = {"hello "};
    char str2[] = "hello";

    int result = compare_str(str1, str2);
    if(1 == result)
        printf("두 문자열이 동일합니다.\n");
    else if(0 == result)
        printf("두 문자열이 동일하지 않습니다.\n");
    else
        puts("오류 발생");


    return 0;
}

int compare_str(char* str1, char* str2){
    
    if(str1==NULL || str2==NULL)
        return -1;
    
    int i;
    // int str1_size=0;
    // int str2_size=0;

    // for(i=0; str1[i] != '\0'; i++){
    //     str1_size++;
    // }
    
    // for(i=0; str2[i] != '\0'; i++){
    //     str2_size++;
    // }
    
    // if(str1_size != str2_size) return 0;
    
    for(i=0; str1[i] != '\0' && str2[i] != '\0'; i++){
        if(str1[i] != str2[i])
            return 0;
    }
    
    return (str1[i] == str2[i]);
}