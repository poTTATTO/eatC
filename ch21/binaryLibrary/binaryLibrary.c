#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<errno.h>

#define SIZE 100
#define MAX_OF_CONTENT 30

typedef struct Book{
    long number;
    char name[30];
    char author[30];
    char publisher[30];
    int borrowed;
}Book;

typedef struct{
    char signature[4];
    int version;
    long data_count;
    size_t record_size;
    char reserved[32];
}FileHeader;

bool check_info(struct Book* ptmp, char* pinput, int size, int ch);
void safety_input(char* p);
int safety_input_num();
void return_book(struct Book* ptmp, int* pcount, int struct_size);
void borrow_book(struct Book* ptmp, int* pcount,int struct_size);
void view_books(struct Book* ptmp, int count);
void add_book(struct Book* ptmp, FILE* fp, int* pcount, int* p_struct_size);
void find(struct Book* ptmp, FILE* fp, int count, int struct_size);
// int len_books(struct Book* ptr);
int compare_str(char* str1, char* str2);
void copy_str(char* dst, char* src);

int main(){

    Book tmp;   
    Book* ptmp = &tmp;
    int current_count = 0; // 구체는 배열처럼 '\0'가 없어서 따로 변수를 둬야함
    int* pcount = &current_count;
    int struct_size = sizeof(tmp);
    int* p_struct_size = &struct_size;

    FILE* fp = fopen("list.bin", "r+");
    FileHeader fileheader;
    memcpy(fileheader.signature, "MYDB", sizeof("MYDB")-1);
    fileheader.data_count = 0;
    fileheader.version = 1;
    fileheader.record_size= struct_size; 
    memcpy(fileheader.reserved, "none", sizeof("none")-1);

    fwrite(&fileheader, sizeof(fileheader), 1, fp);
    add_book(ptmp, fp, pcount, p_struct_size);


    
    FileHeader tmp2;

    fseek(fp, 0, SEEK_SET);
    fread(&tmp2, sizeof(tmp2), 1, fp);
    printf("signature : %s\n",tmp2.signature);
    printf("data_count : %ld\n", tmp2.data_count);
    printf("version : %d\n", tmp2.version);
    printf("record_size : %zu\n", tmp2.record_size);
    printf("reserved : %s\n", tmp2.reserved);

    fread(ptmp, sizeof(tmp), 1, fp);

// typedef struct Book{
//     long number;
//     char name[30];
//     char author[30];
//     char publisher[30];
//     int borrowed;
// }Book;

    printf("number : %ld\n", ptmp->number);
    printf("name : %s\n", ptmp->name);
    printf("author : %s\n", ptmp->author);
    printf("publisher : %s\n", ptmp->publisher);
    ptmp->borrowed == 0 ? puts("대출 불가능") : puts("대출 가능");


    // puts("======== 도서관에 오신 것을 환영합니다 ========");
    // while(1){
    //     puts("[1] : 도서 검색\t[2] : 도서 추가\t[3] : 도서 대출\t[4] : 도서 반납\t[5] : 책 리스트\t[6] : 종료");
    //     printf("선택 : ");
    //     int input = safety_input_num();

    //     switch(input){
    //         case 1: find(ptr, current_count, sturct_size); break;
    //         case 2 : add_book(ptr, pcount); break;
    //         case 3 : borrow_book(ptr, pcount, sturct_size); break;
    //         case 4 : return_book(ptr, pcount, sturct_size); break;
    //         case 5 : view_books(ptr, current_count);
    //         default : break;
    //     }
    //     if(input == 6)
    //         break;
    // }
 

    
   
    return 0;
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

void add_book(struct Book* ptmp, FILE* fp, int* pcount,int* p_struct_size ){
    if(ptmp == NULL || fp == NULL|| *pcount>=SIZE){
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

    (*pcount)++;

    fwrite(ptmp, *p_struct_size, 1, fp);

    // memcpy(*ptitle + *plen_books, tmp_title, sizeof(char) * (strlen(tmp_title)+1));
    // memcpy(*pauthor + *plen_books, tmp_author, sizeof(char) * (strlen(tmp_author)+1));
    // memcpy(*ppublisher + *plen_books, tmp_publisher, sizeof(char) * (strlen(tmp_publisher)+1));
    //ptr가 NULL이므로 절대 하면 안됨
    
    return;
}


void view_books(struct Book* ptmp, int count){

    for(int i=0; i<count; i++){
        printf("[%d]\t", i+1);
        printf("제목 : %-10s\t", ptr[i].name);
        printf("저자 : %-10s\t", ptr[i].author);
        printf("출판사 : %-10s\t", ptr[i].publisher);
        ptr[i].borrowed == 1 ? printf("대출 가능") : printf("대출 불가능");
        putchar('\n');
    }

    return;
}

void find(struct Book* ptmp, FILE* fp, int count, int struct_size){
    if(ptr == NULL || fp == NULL){
        return;
    }

    if(count <= 0){
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
        
    do{
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

        if(!check_info(ptr, p, count, ch)){
            puts("검색 결과가 없습니다.");
        }
    }while(!check_info(ptr, p,count, ch));

    puts("=============================================================================================================================");
    for(int i=0; i<count; i++){
        char* target = NULL;
        if(ch == 1) target = ptmp->name;
        else if(ch == 2) target = ptmp->author;
        else if(ch == 3) target = ptmp->publisher;
        if(compare_str(tmp, target)){
            printf("[%d]\t", i+1);
            printf("제목 : %-10s\t", ptmp->name);
            printf("저자 : %-10s\t", ptmp->author);
            printf("출판사 : %-10s\t", ptmp->publisher);
            ptmp->borrowed == 1 ? printf("대출 가능\n") : printf("대출 불가능\n");
        }
    };

    puts("=============================================================================================================================");
    return;
    

}

bool check_info(struct Book* ptmp, char* pinput, int size, int ch){
    int cnt = 0;
    if (ptr == NULL) return false;

    for(int i=0; i<size; i++){
        char* target;
        if(ch == 1) target = ptr[i].name;
        else if(ch == 2) target = ptr[i].author;
        else if(ch == 3) target = ptr[i].publisher;
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

void borrow_book(struct Book* ptr, int* pcount, int struct_size){
    if(ptr == NULL || *pcount<0 || pcount == NULL ){
        return;
    }

    puts("===== 대출할 책 검색 =====");
    find(ptr, *pcount, struct_size);
    int idx;
    
    do{
        printf("대출할 책의 번호를 입력하세요 : ");
        idx = safety_input_num() - 1;

        if(idx < 0 || idx >= *pcount){
            printf("%d번 책의 정보가 없습니다.\n", idx + 1);
        }
    }while(idx < 0 || idx >= *pcount);
    

    printf("===== 대출 할 책의 정보 =====\n");
    printf("제 목 : %-10s\n", ptr[idx].name);
    printf("저 자 : %-10s\n", ptr[idx].author);
    printf("출판사 : %-10s\n", ptr[idx].publisher);
    printf("==========================\n");

    printf("대출 하시겠습니까?\n[1] : 예\n[2] : 아니요\n입 력 : ");
    int ch2;
    ch2 = fgetc(stdin);
    while(getchar() != '\n');
    if('1'==ch2) ptr[idx].borrowed=0;

}

void return_book(struct Book* ptr, int* pcount, int struct_size){
    if(ptr == NULL){
        return;
    }

    puts("===== 반납할 책 검색 =====");
    find(ptr, *pcount, struct_size);
    int idx;
    
    do{
        printf("반납할 책의 번호를 입력하세요 : ");
        idx = safety_input_num() - 1;

        if(idx < 0 || idx >= *pcount){
            printf("%d번 책의 정보가 없습니다.\n", idx + 1);
        }
    }while(idx < 0 || idx >= *pcount);
    

    printf("===== 반납 할 책의 정보 =====\n");
    printf("제 목 : %-10s\n", ptr[idx].name);
    printf("저 자 : %-10s\n", ptr[idx].author);
    printf("출판사 : %-10s\n", ptr[idx].publisher);
    printf("==========================\n");

    printf("반납 하시겠습니까?\n[1] : 예\n[2] : 아니요\n입 력 : ");
    int ch2;
    ch2 = fgetc(stdin);
    while(getchar() != '\n');
    if('1'==ch2) ptr[idx].borrowed = 1;    
    return;
}