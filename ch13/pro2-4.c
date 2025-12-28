#include<stdio.h>

int find_str(char* dst, int dst_size, char* src, int src_legnth);

int main(){

    char str1[100] = "hello my name is babamba";
    char str2[50] = "lo";
    int str2_length=0;
    for(int i=0; i < sizeof(str2) -1 && str2[i] !='\0'; i++){
        str2_length++;
    }


    printf("result : %d\n", find_str(str1, sizeof(str1), str2, str2_length));
    return 0;
}

int find_str(char* dst,int dst_size, char* src, int src_length){
    if(dst==NULL||src==NULL||src_length<=0)
        return -1;

    int i=0,j=0;
    while(i <= dst_size - src_length && dst[i] !='\0'){

        if(dst[i] == src[0]){
            for(j=1; j<src_length; j++){
                if(dst[i+j] != src[j]){
                    break;
                }
            }
            if(j == src_length)
                return i;
        }
        i++;
    }

    return -1;
    
}