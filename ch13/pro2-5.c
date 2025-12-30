#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define SIZE 100
#define MAX_OF_CONTENT 30


void return_book(char** ptitle, char** pauthor, char** ppublisher, int* pborrow_possible);
void borrow_book(char** ptitle, char** pauthor, char** ppublisher, int* pborrow_possible);
//void view_books(char** ptitle, char** pauthor, char** ppublisher, int* pborrow_possible);
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

    // view_books(ptitle, pauthor, ppublisher, pborrow_possilble);

 
    int len_book = len_books(ptitle);
    // add_book(ptitle, pauthor, ppublisher, &len_book, pttmp, patmp, pptmp, pborrow_possilble);

    // view_books(ptitle, pauthor, ppublisher, pborrow_possilble);
    // find_as_title(ptitle, pauthor, ppublisher, pborrow_possilble); 
 
    borrow_book(ptitle, pauthor, ppublisher, pborrow_possilble);
    view_books(ptitle, pauthor, ppublisher, pborrow_possilble);
   
    return 0;
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

    printf("책 제목을 입력하세요 : ");
    fscanf(stdin, "%29[^\n]s", pttmp[*plen_books]);
    getchar();
    
    printf("저자 이름을 입력하세요 : ");
    fscanf(stdin, "%29[^\n]s", patmp[*plen_books]);
    getchar();
    
    printf("출판사 이름을 입력하세요 : ");
    fscanf(stdin, "%29[^\n]s", pptmp[*plen_books]);
    getchar();


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

    char tmp[30];
    int ch;
    printf("[1] : 책으로 검색\n[2] : 저자로 검색\n[3] : 출판사로 검색\n입 력 : ");
    ch = fgetc(stdin);
    if('1' == (char)ch){
        pselect = ptitle;
        printf("책 제목을 입력하세요 : ");
    }else if('2' == (char)ch){
        pselect = pauthor;
        printf("저자 이름을 입력하세요 : ");
    }else if('3' == (char)ch){
        pselect = ppublisher;
        printf("출판사를 입력하세요 : ");
    }else{
        return;
    }
    getchar();
    
    fscanf(stdin, "%29[^\n]s", tmp);

    for(int i=0; i<length; i++){
        if(compare_str(tmp, pselect[i])){
            printf("[%d]\t", i+1);
            printf("제목 : %s\t", ptitle[i]);
            printf("저자 : %s\t", pauthor[i]);
            printf("출판사 : %s\t", ppublisher[i]);
            pborrow_possible[i] == 1 ? printf("대출 가능") : printf("대출 불가능");
            putchar('\n');        
        }
    };

    getchar();
    return;
    

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
        }
        return 1;
    }else{
        return 0;
    }

}

void borrow_book(char** ptitle, char** pauthor, char** ppublisher, int* pborrow_possible){
    if(ptitle == NULL || pauthor == NULL || ppublisher == NULL || pborrow_possible == NULL){
        return;
    }

    find(ptitle, pauthor, ppublisher, pborrow_possible);
    int idx;
    
    do{
        printf("대출할 책의 번호를 입력하세요 : ");
        idx = fgetc(stdin);
        idx = idx - '0' - 1;
        getchar();
        if(pborrow_possible[idx] == 0){
            puts("이 책을 대출 할 수 없습니다!");
        }
    }while((idx >= 0 && idx<= strlen(ptitle))&& pborrow_possible[idx] == 0);
    

    printf("===== 대출 할 책의 정보 =====\n");
    printf("제 목 : %s\n", ptitle[idx]);
    printf("저 자 : %s\n", pauthor[idx]);
    printf("출판사 : %s\n", ppublisher[idx]);
    printf("==========================\n");

    printf("대출 하시겠습니까?\n[1] : 예\n[2] : 아니요\n입 력 : ");
    int ch2;
    ch2 = fgetc(stdin);
    getchar();
    if('1'==ch2) pborrow_possible[idx] = 0;
    
    return; 

}


void return_book(char** ptitle, char** pauthor, char** ppublisher, int* pborrow_possible){
    if(ptitle == NULL || pauthor == NULL || ppublisher == NULL || pborrow_possible == NULL){
        return;
    }

    find(ptitle, pauthor, ppublisher, pborrow_possible);
    int idx;
; 
    do{
        printf("반납할 책의 번호를 입력하세요 : ");
        idx = fgetc(stdin);
        getchar();
        if(idx + 1 < 1 || idx + 1 > strlen(ptitle)){
            printf("%d번 책의 정보가 없습니다.\n", idx + 1);
        }
    }while(idx + 1 < 1 || idx + 1 > strlen(ptitle));
    

    printf("===== 반납 할 책의 정보 =====\n");
    printf("제 목 : %s\n", ptitle[idx]);
    printf("저 자 : %s\n", pauthor[idx]);
    printf("출판사 : %s\n", ppublisher[idx]);
    printf("==========================\n");

    printf("반납 하시겠습니까?\n[1] : 예\n[2] : 아니요\n입 력 : ");
    int ch2;
    ch2 = fgetc(stdin);
    getchar();
    if('1'==ch2) pborrow_possible[idx] = 1;
    
    return;
}