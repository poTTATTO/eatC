#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

int main(){
    char buf[30];
    char *endPtr;
    long value;

    printf("숫자를 입력하세요 : ");

    if(fgets(buf, sizeof(buf), stdin) == NULL) return -1;

    errno = 0;
    value = strtol(buf, &endPtr,10);

    if(errno == ERANGE){
        printf("숫자가 너무 큽니다.\n");
    }else if(buf == endPtr){
        printf("숫자가 없습니다.\n");
    }else if(*endPtr != '\n' && *endPtr != '\0'){
        printf("숫자 뒤에 이상한 것(%s)이 섞여있습니다. \n",endPtr);
    }

    printf("입력된 숫자 : %ld\n", value);
    

    return 0;
}