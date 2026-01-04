#include"book_function.h"
#include"input.h"
#include"str.h"

void add_book(struct Book* ptr, int* pcount){
    if(ptr == NULL || *pcount>=SIZE){
        return;
    }
    

    char* pt = ptr[*pcount].name;
    char* pa = ptr[*pcount].author;
    char* pp = ptr[*pcount].publisher;

    printf("책 제목을 입력하세요 : ");
    safety_input(pt);

    printf("저자 이름을 입력하세요 : ");
    safety_input(pa);

    printf("출판사 이름을 입력하세요 : ");
    safety_input(pp);
    
    ptr[*pcount].borrowed = 1;

    (*pcount)++;

    // memcpy(*ptitle + *plen_books, tmp_title, sizeof(char) * (strlen(tmp_title)+1));
    // memcpy(*pauthor + *plen_books, tmp_author, sizeof(char) * (strlen(tmp_author)+1));
    // memcpy(*ppublisher + *plen_books, tmp_publisher, sizeof(char) * (strlen(tmp_publisher)+1));
    //ptr가 NULL이므로 절대 하면 안됨

    return;
}


void view_books(struct Book* ptr, int count){

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

void find(struct Book* ptr, int count, int struct_size){
    if(ptr == NULL){
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
        if(ch == 1) target = ptr[i].name;
        else if(ch == 2) target = ptr[i].author;
        else if(ch == 3) target = ptr[i].publisher;
        if(compare_str(tmp, target)){
            printf("[%d]\t", i+1);
            printf("제목 : %-10s\t", ptr[i].name);
            printf("저자 : %-10s\t", ptr[i].author);
            printf("출판사 : %-10s\t", ptr[i].publisher);
            ptr[i].borrowed == 1 ? printf("대출 가능\n") : printf("대출 불가능\n");
        }
    };

    puts("=============================================================================================================================");
    return;
    

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


bool check_info(struct Book* ptr, char* pinput, int size, int ch){
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

