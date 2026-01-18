#include<stdio.h>
void add(int* p);
int main(){
    // FILE* fp = fopen("file.txt", "r+");
    // char buf[100] = {"hello world\nhi world"};

    // fputs(buf, fp);

    FILE* fp = fopen("file.txt", "r");
    fseek(fp, 2, SEEK_SET);
    int start = ftell(fp);

    fseek(fp, 0, SEEK_END);
    int last = ftell(fp);

    printf("%d\n",start);
    printf("%d\n", last);
    return 0;
}

void add(int* p){
    ++(*p);
}