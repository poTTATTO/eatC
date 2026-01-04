#include<stdio.h>
#include"Book.h"
#include<stdbool.h>

#define SIZE 100
void return_book(struct Book* ptr, int* pcount, int struct_size);
void borrow_book(struct Book* ptr, int* pcount,int struct_size);
void view_books(struct Book* ptr, int count);
void add_book(struct Book* ptr, int* pcount);
void find(struct Book* ptr, int count, int struct_size);
bool check_info(struct Book* ptr, char* pinput, int size, int ch);
