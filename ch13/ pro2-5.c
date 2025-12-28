#include<stdio.h>
#include<string.h>

#define SIZE 100
#define MAX_OF_CONTENT 30
void add_book();
void return_book();
void borrow_book();
void find_as_title();
void find_as_author();
void find_as_publisher();
int len_books(char** ptitle);
int main(){
    
    char* title[SIZE] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
    char* author[SIZE] = {"jenny", "jenny", "peter", "peter", "kenny", "kenny", "ben", "ben", "john", "john"};
    char* publisher[SIZE] = {"A", "A", "B", "B", "C", "C", "D","D", "E", "E", "F", "F"}; 
    char ttmp[SIZE][MAX_OF_CONTENT];
    char atmp[SIZE][MAX_OF_CONTENT];
    char ptemp[SIZE][MAX_OF_CONTENT];

    char (*pttmp)[MAX_OF_CONTENT] = ttmp;
    char (*patmp)
    char** ptitle = title;
    int len_books = len_books(ptitle);

    

    return 0;
}

void add_book(char** ptitle, char** pauthor, char** ppublisher, int* plen_books, char** pptmp){
    if(ptitle==NULL||pauthor==NULL||ppublisher==NULL||plen_books==NULL){
        return;
    }

    printf("책 제목을 입력하세요 : ");
    fscanf(stdin, %29[^\n]s, t);
    getchar();
    
    printf("저자 이름을 입력하세요 : ");
    fscanf(stdin, %29[^\n]s, tmp_author);
    getchar();
    
    printf("출판사 이름을 입력하세요 : ");
    fscanf(stdin, %29[^\n]s, tmp_publisher);
    getchar();

    // memcpy(*ptitle + *plen_books, tmp_title, sizeof(char) * (strlen(tmp_title)+1));
    // memcpy(*pauthor + *plen_books, tmp_author, sizeof(char) * (strlen(tmp_author)+1));
    // memcpy(*ppublisher + *plen_books, tmp_publisher, sizeof(char) * (strlen(tmp_publisher)+1));
    //ptr가 NULL이므로 절대 하면 안됨



    

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




char* array[100][200];