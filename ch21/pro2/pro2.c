#include<stdio.h>
#include<string.h>

int file_size(FILE* fp);
int find_string(const char* dst, const char* src);

int main(){
    FILE* fp = fopen("a.txt", "r");
    
    char buf[1000]={0};
    int cnt = file_size(fp);
    rewind(fp);
    if(cnt>=1000) cnt=999;

    fread(buf,1, cnt, fp);
    
    char* pos = strstr(buf, "babamba");
    
    printf("파일의 내용 : %s\n", buf);
    if(pos) printf("발견 위치 : %ld\n", pos-buf);
   

    fclose(fp);
}

int find_string(const char* dst, const char* src){
    
    for(int i=0; i+strlen(src)<strlen(dst); i++){
        if(memcmp(dst, src, strlen(src))){
            return i;
        }
    }
}

int file_size(FILE* fp){
    fseek(fp, 0, SEEK_END);
    int cnt = ftell(fp);
    return cnt;
}