#include<stdio.h>

int merge_str(char* dst, int dst_size, char* str);
int main(){

    char dst[100] = "hello my name is ";
    char str[] = "babamba";
    printf("%d\n", merge_str(dst,sizeof(dst),str));

    printf("%s\n", dst);

    return 0;
}

int merge_str(char* dst, int dst_size, char* str){
    if(dst == NULL || str == NULL)
        return -1;

    int i,j;
    for(i=0; i < dst_size -1 && dst[i] != '\0'; i++){}

    for(j=0; i<dst_size -1 && str[j] != '\0'; i++,j++){
        dst[i] = str[j];
    }
    dst[i] = '\0';

    return i;
}