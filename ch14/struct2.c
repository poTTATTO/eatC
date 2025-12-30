#include<stdio.h>
#include<string.h>

char copy_str(char *dst, const char* src);

struct Books{
    char name[30];
    char auth[30];
    char publ[30];
    int borrowed;
};

int main(){
    struct Books Harry_Potter;

    copy_str(Harry_Potter.name, "Harry Potter");
    copy_str(Harry_Potter.auth, "J.K Rolling");
    copy_str(Harry_Potter.publ, "Scholastic");
    Harry_Potter.borrowed = 0;

    printf("책 이름 : %s\n", Harry_Potter.name);
    printf("저자 이름 : %s\n",Harry_Potter.auth);
    printf("출판사 이름 : %s\n", Harry_Potter.publ);


    return 0;
}

char copy_str(char* dst, const char* src){
    if(dst == NULL || src == NULL){
        return 0;
    }
    int length = strlen(src);
    int i;
    for(i=0; i<length; i++){
        dst[i] = src[i];
    }
    
    dst[i] = '\0'; //널문자 무조건 생각
    return 1;
}






