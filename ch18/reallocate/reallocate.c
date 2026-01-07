#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char input[10];
    char* endPtr;
    int num;
    printf("%s", "할당하고 싶은 배열의 크기 : ");

    fgets(input, sizeof(input), stdin);
    num = strtol(input, &endPtr, 10);

    int* array = (int*)calloc(num, sizeof(int));
    if(array==NULL) return -1;
    
    int cnt=0;
    int i;
    for(i=0; i<num; i++){
        array[i] = ++cnt;
    }
    
    for(i=0; i<num; i++){
        printf("%3d",array[i]);
    }
    
    printf("%s", "더하고 싶은 원소의 수 ");
    memset(input, 0, sizeof(input));

    int num2;
    fgets(input, sizeof(input), stdin);
    num2 = (int)strtol(input, &endPtr, 10);
    int* array2;

    int* temp = (int*)calloc(num+num2, sizeof(int));
    if(temp == NULL){
        puts("메모리 할당 실패");
        return -1;
    }

    array2 = temp;

    if(array2==NULL) return -1;
    for(i=0; i<num; i++){
        array2[i] = array[i];        
    }

    free(array);

    for(i=0; i<num+num2; i++){
        printf("%3d",array2[i]);
    }
    
    free(array2);
    return 0;    
}