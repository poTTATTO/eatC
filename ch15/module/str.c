#include"str.h"

void copy_str(char* dst, char* src){
    while(*src){
        *dst = *src;
        src++;
        dst++;

    }
    *dst ='\0';
}
int compare_str(char* str1, char* str2){
    if(str1 == NULL || str2 == NULL){
        return -1;
    }
    int length1 = strlen(str1);
    int length2 = strlen(str2);

    if(length1 <= 0 || length2 <=0){
        return -1;
    }

    if(length1 == length2){
        for(int i=0; i<length1; i++){
            if(*str1 != *str2){
                return 0;
            }
            str1++;
            str2++;
        }
        return 1;
    }else{
        return 0;
    }

}