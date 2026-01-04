#include"input.h"
#include"book_function.h"
#include"str.h"



int main(){

    struct Book book_list[SIZE] = {0};
    
    
    char* title[SIZE] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
    char* author[SIZE] = {"jenny", "jenny", "peter", "peter", "kenny", "kenny", "ben", "ben", "john", "john"};
    char* publisher[SIZE] = {"A", "A", "B", "B", "C", "C", "D","D", "E", "E"}; 
    int borrow_possilble[SIZE] = {1,1,0,1,0,1,0,1,1,1};
    
    for(int i=0; i<10; i++){
        copy_str(book_list[i].name, title[i]);
        copy_str(book_list[i].author, author[i]);
        copy_str(book_list[i].publisher, publisher[i]);
        book_list[i].borrowed = borrow_possilble[i];
    }
    int current_count = 10; // 구체는 배열처럼 '\0'가 없어서 따로 변수를 둬야함
    int* pcount = &current_count;
    int sturct_size = sizeof(book_list[0]);
    struct Book* ptr = book_list;

   
    puts("======== 도서관에 오신 것을 환영합니다 ========");
    while(1){
        puts("[1] : 도서 검색\t[2] : 도서 추가\t[3] : 도서 대출\t[4] : 도서 반납\t[5] : 책 리스트\t[6] : 종료");
        printf("선택 : ");
        int input = safety_input_num();

        switch(input){
            case 1: find(ptr, current_count, sturct_size); break;
            case 2 : add_book(ptr, pcount); break;
            case 3 : borrow_book(ptr, pcount, sturct_size); break;
            case 4 : return_book(ptr, pcount, sturct_size); break;
            case 5 : view_books(ptr, current_count);
            default : break;
        }
        if(input == 6)
            break;
    }
 

    
   
    return 0;
}



