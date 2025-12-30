#include<stdio.h>
#include<string.h>

struct Books{
    char name[30];
    char auth[30];
    char publ[30];
    int borrowed;
};

int main(){
    struct Books book_list[3] = {0};
    
    int i;

    for(i=0; i<3; i++){
        printf("책 %d 정보 입력 : ", i);
        fgets(book_list[i].name, sizeof(book_list[i].name), stdin);
        book_list[i].name[strcspn(book_list[i].name, "\n")] = '\0';

        fgets(book_list[i].auth, sizeof(book_list[i].auth), stdin);
        book_list[i].auth[strcspn(book_list[i].auth, "\n")] = '\0';
        
        fgets(book_list[i].publ, sizeof(book_list[i].name), stdin);
        book_list[i].name[strcspn(book_list[i].name, "\n")] = '\0';
        putchar('\n');
    }

    for(i=0; i<3; i++){
        puts("==========================================");
        printf("책 %d 정보\n",i);
        printf("이름 : %s\n", book_list[i].name);
        printf("저자 이름 : %s\n", book_list[i].auth);
        printf("출판사 이름 :%s\n", book_list[i].publ);
        if(book_list[i].borrowed == 0){
            puts("대출 불가");
        }else{
            puts("대출 가능");
        }
    }

    return 0;
}