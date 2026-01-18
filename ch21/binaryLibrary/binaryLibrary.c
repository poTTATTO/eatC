#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<errno.h>

#define MAX_OF_CONTENT 30

typedef struct Book{
    long number;
    char name[30];
    char author[30];
    char publisher[30];
    int borrowed;
}Book;

typedef struct{
    char signature[5];
    int version;
    long data_count;
    size_t record_size;
    char reserved[32];
}FileHeader;

bool check_info(Book* ptmp, FILE* fp, char* pinput, int size, int ch);
void safety_input(char* p);
int safety_input_num();
void return_book(Book* ptmp, FILE* fp, int* pcount);
void borrow_book(Book* ptmp, FILE* fp, int* pcount);
void view_books(Book* ptmp,FILE* fp, int* pcount);
void add_book(Book* ptmp, FileHeader* header, FILE* fp, int* pcount);
void find(Book* ptmp, FILE* fp, int* pcount);
int compare_str(char* str1, char* str2);
void copy_str(char* dst, char* src);
int check_file_length(FILE* fp);
void print_header(FILE* fp, FileHeader* header);
void init_header(FILE* fp,FileHeader* fileheader);
int main(){

    
    FileHeader fileheader={0};
    FileHeader* pheader = &fileheader;

    FILE* fp = fopen("list.bin", "rb+");
    if(fp==NULL){
        fp = fopen("list.bin","wb+");
    }
    Book tmp = {0};   
    Book* ptmp = &tmp;
    if(!fseek(fp, 0, SEEK_END) && ftell(fp) == 0){
        init_header(fp, pheader);
    }else{
        rewind(fp);
        fread(pheader, sizeof(FileHeader), 1, fp);
    }

    int current_count = check_file_length(fp); // 구체는 배열처럼 '\0'가 없어서 따로 변수를 둬야함
    int* pcount = &current_count;
    
    fseek(fp, 0, SEEK_SET);


    puts("======== 도서관에 오신 것을 환영합니다 ========");
    while(1){
        puts("[1] : 도서 검색\t[2] : 도서 추가\t[3] : 도서 대출\t[4] : 도서 반납\t[5] : 책 리스트\t[6] : 헤더\t[7] : 종료");
        printf("선택 : ");
        int input = safety_input_num();

        switch(input){
            case 1 : find(ptmp, fp, pcount); break;
            case 2 : add_book(ptmp, pheader, fp, pcount); break;
            case 3 : borrow_book(ptmp, fp, pcount); break;
            case 4 : return_book(ptmp, fp, pcount); break;
            case 5 : view_books(ptmp, fp, pcount); break;
            case 6 : print_header(fp, pheader); break;
            default : break;
        }
        if(input == 7)
            break;
    }
 

    
   
    return 0;
}
/*typedef struct{
    char signature[5];
    int version;
    long data_count;
    size_t record_size;
    char reserved[32];
}FileHeader;
*/
void print_header(FILE* fp, FileHeader* header){
    fseek(fp, 0, SEEK_SET);
    fread(header, sizeof(FileHeader), 1, fp);
    printf("signature : %s\n", header->signature);
    printf("version : %d\n", header->version);
    printf("data_count : %ld\n", header->data_count);
    printf("record_size : %zu\n",header->record_size);
    printf("reserved : %s\n", header->reserved);

    rewind(fp);
    return;
}

void init_header(FILE* fp, FileHeader* fileheader){
 
    memcpy(fileheader->signature, "MYDB", sizeof("MYDB"));
    fileheader->data_count = 0;
    fileheader->version = 1;
    fileheader->record_size = sizeof(Book);
    memcpy(fileheader->reserved, "none", sizeof("none"));
    
    rewind(fp);
    fwrite(fileheader, sizeof(FileHeader), 1, fp);
    rewind(fp);
}

int check_file_length(FILE* fp){
    fseek(fp, sizeof(FileHeader), SEEK_SET);
    long start = ftell(fp);
    
    fseek(fp, 0, SEEK_END);
    long end = ftell(fp);

    int count = (end - start)/sizeof(Book);

    return count;
}

void copy_str(char* dst, char* src){
    while(*src){
        *dst = *src;
        src++;
        dst++;

    }
    *dst ='\0';
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

void add_book(Book* ptmp, FileHeader* pheader, FILE* fp, int* pcount){
    if(ptmp == NULL || fp == NULL){
        return;
    }
    

    char* pt = ptmp->name;
    char* pa = ptmp->author;
    char* pp = ptmp->publisher;

    printf("책 제목을 입력하세요 : ");
    safety_input(pt);

    printf("저자 이름을 입력하세요 : ");
    safety_input(pa);

    printf("출판사 이름을 입력하세요 : ");
    safety_input(pp);

    ptmp->borrowed = 1;

    ++(*pcount);
    ptmp->number = *pcount;

    pheader->data_count = *pcount;
    fseek(fp, 0, SEEK_SET);
    fwrite(pheader,sizeof(FileHeader), 1, fp);

    long offset = sizeof(FileHeader) + (sizeof(Book) * (*pcount -1));
    fseek(fp, offset, SEEK_SET);
    fwrite(ptmp, sizeof(Book), 1, fp);

   
    
    return;
}


void view_books(Book* ptmp, FILE* fp, int* pcount){

    fseek(fp, sizeof(FileHeader), SEEK_SET);

    for(int i=0; i<*pcount; i++){
        fread(ptmp, sizeof(Book), 1, fp);

        printf("[%ld]\t", ptmp->number);
        printf("제목 : %-10s\t", ptmp->name);
        printf("저자 : %-10s\t", ptmp->author);
        printf("출판사 : %-10s\t", ptmp->publisher);
        ptmp->borrowed == 1 ? printf("대출 가능") : printf("대출 불가능");
        putchar('\n');
    }

    return;
}

void find(Book* ptmp, FILE* fp, int* pcount){
    if(ptmp == NULL || fp == NULL){
        return;
    }

    if(*pcount <= 0){
        return;
    }

    
    int ch;
   
    char tmp[30];
    char* p = tmp;

    printf("[1] : 제목으로 검색\n[2] : 저자로 검색\n[3] : 출판사로 검색\n");
    do{
        printf("입력 : ");
        ch = safety_input_num();
        if(ch<1 || ch >3){
            puts("옵션을 잘 선택하세요");
        }
    }while(ch<1 || ch >3);
    

    if(ch == -1){
        return;
    }
    
    if(ch<=0 || ch>=4)
        return;

    
    if(1 == ch){
        printf("책 제목을 입력하세요 : "); 
    }else if(2 == ch){
        printf("저자 이름을 입력하세요 : ");
    }else if(3 == ch){
        printf("출판사를 입력하세요 : ");
    }else{
        return;
    }

    safety_input(p);

    if(!check_info(ptmp,fp, p, *pcount, ch)){
        puts("검색 결과가 없습니다.");
        return;
    }
    
    fseek(fp, sizeof(FileHeader), SEEK_SET);
    puts("=============================================================================================================================");
    for(int i=0; i<*pcount; i++){
        char* target = NULL;
        fread(ptmp, sizeof(Book), 1, fp);
        if(ch == 1) target = ptmp->name;
        else if(ch == 2) target = ptmp->author;
        else if(ch == 3) target = ptmp->publisher;
        if(compare_str(tmp, target)){
            printf("[%ld]\t", ptmp->number);
            printf("제목 : %-10s\t", ptmp->name);
            printf("저자 : %-10s\t", ptmp->author);
            printf("출판사 : %-10s\t", ptmp->publisher);
            ptmp->borrowed == 1 ? printf("대출 가능\n") : printf("대출 불가능\n");
        }
    };

    puts("=============================================================================================================================");
    return;
    

}

bool check_info(Book* ptmp, FILE* fp, char* pinput, int size, int ch){
    int cnt = 0;
    if (ptmp == NULL) return false;

    fseek(fp, sizeof(FileHeader), SEEK_SET);
    
    for(int i=0; i<size; i++){
        char* target;
        fread(ptmp, sizeof(Book), 1, fp);
        if(ch == 1) target = ptmp->name;
        else if(ch == 2) target = ptmp->author;
        else if(ch == 3) target = ptmp->publisher;
        if(compare_str(target, pinput)){
            cnt++;
        }
    }

    return cnt != 0 ? true : false;
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


void borrow_book(Book* ptmp, FILE* fp, int* pcount){
    if(ptmp == NULL || *pcount<0 || pcount == NULL ){
        return;
    }

    puts("===== 대출할 책 검색 =====");
    find(ptmp, fp, pcount);
    int idx;
    
    do{
        printf("대출할 책의 번호를 입력하세요 : ");
        idx = safety_input_num() - 1;

        if(idx < 0 || idx >= *pcount){
            printf("%d번 책의 정보가 없습니다.\n", idx + 1);
        }
    }while(idx < 0 || idx >= *pcount);
    
    long offset = sizeof(FileHeader) + sizeof(Book) * (idx);

    fseek(fp, offset, SEEK_SET);
    fread(ptmp, sizeof(Book), 1, fp);
    printf("===== 반납 할 책의 정보 =====\n");
    printf("제 목 : %-10s\n", ptmp->name);
    printf("저 자 : %-10s\n", ptmp->author);
    printf("출판사 : %-10s\n", ptmp->publisher);
    printf("==========================\n");

    printf("대출 하시겠습니까?\n[1] : 예\n[2] : 아니요\n입 력 : ");
    int ch2;
    ch2 = fgetc(stdin);
    while(getchar() != '\n');
    if('1'==ch2) ptmp->borrowed=0;
    fseek(fp, offset, SEEK_SET);
    fwrite(ptmp, sizeof(Book), 1, fp);

}

void return_book(Book* ptmp, FILE* fp, int* pcount){
    if(ptmp == NULL || *pcount<0 || pcount == NULL ){
        return;
    }

    puts("===== 반납할 책 검색 =====");
    find(ptmp, fp, pcount);
    int idx;
    
    do{
        printf("반납할 책의 번호를 입력하세요 : ");
        idx = safety_input_num() - 1;

        if(idx < 0 || idx >= *pcount){
            printf("%d번 책의 정보가 없습니다.\n", idx + 1);
        }
    }while(idx < 0 || idx >= *pcount);
    
    long offset = sizeof(FileHeader) + sizeof(Book) * (idx);

    fseek(fp, offset, SEEK_SET);
    fread(ptmp, sizeof(Book), 1, fp);
    printf("===== 반납 할 책의 정보 =====\n");
    printf("제 목 : %-10s\n", ptmp->name);
    printf("저 자 : %-10s\n", ptmp->author);
    printf("출판사 : %-10s\n", ptmp->publisher);
    printf("==========================\n");

    printf("반납 하시겠습니까?\n[1] : 예\n[2] : 아니요\n입 력 : ");
    int ch2;
    ch2 = fgetc(stdin);
    while(getchar() != '\n');
    if('1'==ch2) ptmp->borrowed=1;
    fseek(fp, offset, SEEK_SET);
    fwrite(ptmp, sizeof(Book), 1, fp);

}