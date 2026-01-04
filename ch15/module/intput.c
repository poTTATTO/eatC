#include"input.h"
#define MAX_OF_CONTENT 100
int safety_input_num(){
    int num;
    char* endPtr;
    char buf[5];

    if(fgets(buf, sizeof(buf), stdin) == NULL) return -1;
    num = strtol(buf, &endPtr, 10);

    if(strchr(buf, '\n') == NULL && strlen(buf) == sizeof(buf) -1){
        int c;
        while((c = getchar()) != '\n' && c != EOF);
    }

    return num;
}

void safety_input(char* p){
    if(fgets(p, MAX_OF_CONTENT, stdin) == NULL) return;
    
    if(strchr(p, '\n') == NULL && strlen(p) == MAX_OF_CONTENT -1){
        int c;
        while((c = getchar()) != '\n' && c != EOF);

    }
    p[strcspn(p,"\n")] = '\0';

    return;
}

