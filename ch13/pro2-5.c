#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<errno.h>

#define SIZE 100
#define MAX_OF_CONTENT 30

bool check_info(char** p, char* pinput, int size);
void safety_input(char* p);
int safety_input_num();
void return_book(char** ptitle, char** pauthor, char** ppublisher, int* pborrow_possible);
void borrow_book(char** ptitle, char** pauthor, char** ppublisher, int* pborrow_possible);
void view_books(char** ptitle, char** pauthor, char** ppublisher, int* pborrow_possible);
void add_book(char** ptitle, char** pauthor, char** ppublisher, int* plen_books, 
    char (*pttmp)[MAX_OF_CONTENT], char (*patmp)[MAX_OF_CONTENT], char (*pptmp)[MAX_OF_CONTENT], int* pborrow_possible);
void find(char** ptitle, char** pauthor, char** ppublisher, int* pborrow_possible);
int len_books(char** ptitle);
int compare_str(char* str1, char* str2);

int main(){
    
    char* title[SIZE] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
    char* author[SIZE] = {"jenny", "jenny", "peter", "peter", "kenny", "kenny", "ben", "ben", "john", "john"};
    char* publisher[SIZE] = {"A", "A", "B", "B", "C", "C", "D","D", "E", "E"}; 
    int borrow_possilble[SIZE] = {1,1,0,1,0,1,0,1,1,1};

    char ttmp[SIZE][MAX_OF_CONTENT];
    char atmp[SIZE][MAX_OF_CONTENT];
    char ptmp[SIZE][MAX_OF_CONTENT];

    char (*pttmp)[MAX_OF_CONTENT] = ttmp;
    char (*patmp)[MAX_OF_CONTENT] = atmp;
    char (*pptmp)[MAX_OF_CONTENT] = ptmp;

    int* pborrow_possilble = borrow_possilble;

    char** ptitle = title;
    char** pauthor = author;
    char** ppublisher = publisher;

    int len_book = len_books(ptitle);

    puts("======== 도서관에 오신 것을 환영합니다 ========");
    while(1){
        puts("[1] : 도서 검색\t[2] : 도서 추가\t[3] : 도서 대출\t[4] : 도서 반납\t[5] : 책 리스트\t[6] : 종료");
        printf("선택 : ");
        int input = safety_input_num();

        switch(input){
            case 1: find(ptitle, pauthor, ppublisher, pborrow_possilble); break;
            case 2 : add_book(ptitle, pauthor, ppublisher, &len_book, pttmp, patmp, pptmp, pborrow_possilble); break;
            case 3 : borrow_book(ptitle, pauthor, ppublisher, pborrow_possilble); break;
            case 4 : return_book(ptitle, pauthor, ppublisher, pborrow_possilble); break;
            case 5 : view_books(ptitle, pauthor, ppublisher, pborrow_possilble);
            default : break;
        }
        if(input == 6)
            break;
    }
 
    
   
    return 0;
}

void safety_input(char* p){
    if(fgets(p, sizeof(p), stdin) == NULL) return;
    
    if(strchr(p, '\n') == NULL && strlen(p) == sizeof(p) -1){
        int c;
        while((c = getchar()) != '\n' && c != EOF);
    }

    p[strcspn(p,"\n")] = '\0';

    return;
}

void add_book(char** ptitle, char** pauthor, char** ppublisher, int* plen_books, 
    char (*pttmp)[MAX_OF_CONTENT], char (*patmp)[MAX_OF_CONTENT], char (*pptmp)[MAX_OF_CONTENT], int* pborrow_possible){
    if(ptitle == NULL || pauthor == NULL || ppublisher == NULL || plen_books == NULL || pborrow_possible == NULL
        || pttmp == NULL || patmp == NULL || pptmp == NULL || pborrow_possible == NULL){
        return;
    }
    if(*plen_books>=SIZE){
        return;
    }
    char* pt = pttmp[*plen_books];
    char* pa = patmp[*plen_books];
    char* pp = pptmp[*plen_books];

    printf("책 제목을 입력하세요 : ");
    safety_input(pt);

    printf("저자 이름을 입력하세요 : ");
    safety_input(pa);

    printf("출판사 이름을 입력하세요 : ");
    safety_input(pp);
    
    
    int len = (*plen_books);
    // (*ptitle)[len]= pttmp[len];
    // (*pauthor)[len] = patmp[len];
    // (*ppublisher[len] = pptmp[len];

    ptitle[len] = pttmp[len];
    pauthor[len] = patmp[len];
    ppublisher[len] = pptmp[len];
    pborrow_possible[len] = 1;

    (*plen_books)++;



    // memcpy(*ptitle + *plen_books, tmp_title, sizeof(char) * (strlen(tmp_title)+1));
    // memcpy(*pauthor + *plen_books, tmp_author, sizeof(char) * (strlen(tmp_author)+1));
    // memcpy(*ppublisher + *plen_books, tmp_publisher, sizeof(char) * (strlen(tmp_publisher)+1));
    //ptr가 NULL이므로 절대 하면 안됨

    return;

    

}

int len_books(char** ptitle){
    if(ptitle == NULL)
        return -1;
    int count=0;

    while(*ptitle != NULL && count < SIZE){
        *ptitle++;
        count++;
    }
    return count;
}

void view_books(char** ptitle, char** pauthor, char** ppublisher, int* pborrow_possible){
    int length = len_books(ptitle);

    for(int i=0; i<length; i++){
        printf("[%d]\t", i+1);
        printf("제목 : %s\t", ptitle[i]);
        printf("저자 : %s\t", pauthor[i]);
        printf("출판사 : %s\t", ppublisher[i]);
        pborrow_possible[i] == 1 ? printf("대출 가능") : printf("대출 불가능");
        putchar('\n');
    }

    return;
}

void find(char** ptitle, char** pauthor, char** ppublisher,int* pborrow_possible ){
    if(ptitle == NULL || pauthor == NULL || ppublisher == NULL || pborrow_possible == NULL){
        return;
    }

    int length = len_books(ptitle);

    if(length <= 0){
        return;
    }
    char **pselect;

    
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
            pselect = ptitle;
            printf("책 제목을 입력하세요 : ");
        }else if(2 == ch){
            pselect = pauthor;
            printf("저자 이름을 입력하세요 : ");
        }else if(3 == ch){
            pselect = ppublisher;
            printf("출판사를 입력하세요 : ");
        }else{
            return;
        }
    
        safety_input(p);

        int length = len_books(ptitle);
        if(!check_info(pselect, p, length)){
            puts("검색 결과가 없습니다.");
        }
    }while(!check_info(pselect,p,length));

    puts("=============================================================================================================================");
    for(int i=0; i<length; i++){
        if(compare_str(tmp, pselect[i])){
            printf("[%d]\t", i+1);
            printf("제목 : %s\t", ptitle[i]);
            printf("저자 : %s\t", pauthor[i]);
            printf("출판사 : %s\t", ppublisher[i]);
            pborrow_possible[i] == 1 ? printf("대출 가능\n") : printf("대출 불가능\n");
        }
    };

    puts("=============================================================================================================================");
    return;
    

}
bool check_info(char** p, char* pinput, int size){
    int cnt = 0;

    for(int i=0; i<size; i++){
        if(compare_str(p[i], pinput)){
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

void borrow_book(char** ptitle, char** pauthor, char** ppublisher, int* pborrow_possible){
}


void return_book(char** ptitle, char** pauthor, char** ppublisher, int* pborrow_possible){
    if(ptitle == NULL || pauthor == NULL || ppublisher == NULL || pborrow_possible == NULL){
        return;
    }

    puts("===== 반납할 책 검색 =====");
    find(ptitle, pauthor, ppublisher, pborrow_possible);
    int idx;
    
    do{
        printf("반납할 책의 번호를 입력하세요 : ");
        idx = safety_input_num() - 1;

        if(idx < 0 || idx >= len_books(ptitle)){
            printf("%d번 책의 정보가 없습니다.\n", idx + 1);
        }
    }while(idx < 0 || idx >= len_books(ptitle));
    

    printf("===== 반납 할 책의 정보 =====\n");
    printf("제 목 : %s\n", ptitle[idx]);
    printf("저 자 : %s\n", pauthor[idx]);
    printf("출판사 : %s\n", ppublisher[idx]);
    printf("==========================\n");

    printf("반납 하시겠습니까?\n[1] : 예\n[2] : 아니요\n입 력 : ");
    int ch2;
    ch2 = fgetc(stdin);
    while(getchar() != '\n');
    if('1'==ch2) pborrow_possible[idx] = 1;
    
    return;
}