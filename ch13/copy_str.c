#include<stdio.h>
int copy_str(char* dst, int dst_size, char* src);

int main(){
    
    char dst[10];
    char src[] = "hello00000000000000000";

    char* src1 = NULL;

    int dst_size = sizeof(dst);
    printf("%d\n",copy_str(dst,dst_size, src1));

    printf("%s\n",dst);

    return 0;
    
}

int copy_str(char* dst, int dst_size, char* src){
    int i=0;

    if(dst==NULL || src==NULL)
       return -1;
    for(i=0; i < dst_size -1 && src[i] != '\0'; i++){
        dst[i] = src[i];
    }
    dst[i] = '\0';

    return i;
}