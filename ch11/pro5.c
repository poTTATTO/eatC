#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int checkRange(int base, const char* array);

char* DectoM(int,int);
int alphabetToDec(char);
int NtoDec(int, const char* array);

int main(){

    int fromBase;
    int toBase;

    // char* array = DectoM(35,8);

    // for(int i=0; array[i]!='\0'; i++){
    //     printf("%c", array[i]);
    // }

     char array[1024];
    printf("from진법 입력 : ");
    scanf("%d",&fromBase);
     
    while(getchar() != '\n');
   printf("to진법 입력 : ");
   scanf("%d", &toBase);
    while(getchar() != '\n');

    if(fgets(array, sizeof(array), stdin) != NULL){
        array[strcspn(array, "\n")] = '\0';
    }


    if(checkRange(fromBase,array) == 1){
        printf("%d진법에 맞는 숫자 입력하세요\n",fromBase);
        return 1;
    }
    char* array2 = DectoM(NtoDec(fromBase, array), toBase);

    for(int i=0; array2[i] != '\0'; i++){
        printf("%c",array2[i]);
    }
    putchar('\n');
    return 0;
}

int NtoDec(int base, const char* array){

    int length=0;

    for(int i=0; array[i]!='\0'; i++) length++;

    int weight =1;
    int sum=0;

    for(int i = length-1; i>=0; i--){
        if(array[i]>=65 && array[i]<=90){
            sum+= (int)(alphabetToDec(array[i])) * weight;
            weight*=base;
        }else{       
        sum+= (int)(array[i]-48) * weight;
        weight*=base;
        }
    }

    return sum;
}

char* DectoM(int num, int base){
    int quotient;
    int reminder;
    int digits = (int)floor(log(num)/log(base))+1;
    char* array = (char*)malloc(sizeof(char) * (digits + 1));
    array[digits] = '\0';

    int i = digits-1;
    while(i>=0){
        reminder = num % base;
        if(reminder < 10){
            array[i] = (char)(reminder + '0');
        }else{
            array[i] = (char)(reminder + 55);
        }
        i--;
        num/=base;
    }

    return array;
}

int alphabetToDec(char alpa){
    
    return (int)(alpa - 55);

}

int checkRange(int base, const char* array){
    int length=0;
    for(int i=0; array[i] != '\0'; i++){
        length++;
    }

    for(int i=0; i<length; i++){
        if(base <10 && base >= 0){
            if(array[i]-'0' < base &&  array[i]-'0' >=0){
                return 0;
            }else 
                return 1;
        }else if(base<=36 && base >=0){
            if((array[i]-'0' < base && array[i] -'0' >= 0) || array[i] - 55 < base && array[i] >=0){
                return 0;
            }else
                return 1;
        }
        
    }

    return 1;
}