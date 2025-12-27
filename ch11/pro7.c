#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define SIZE 2048

char* Add(char* num1,int num1Length, char* num2, int num2Length, char* result);
char* Sub(char* num1,int num1Length, char* num2, int num2Length, char* result);

int main(){
    char num1[SIZE];
    char num2[SIZE];
    char result[SIZE];
    int num1Length=0;
    int num2Length=0;

    memset(num1, -1, sizeof(num1));
    memset(num2, -1, sizeof(num2));
    memset(result, 0, sizeof(result));
    result[SIZE-1]  = '\0';

    printf("%s","처음 숫자를 입력하세요 : ");
    fgets(num1, sizeof(num1), stdin);
    num1[strcspn(num1, "\n")] = '\0';

    printf("%s", "두 번째 숫자를 입력하세요 : ");
    fgets(num2, sizeof(num2), stdin);
    num2[strcspn(num2, "\n")] = '\0';

    for(int i=0; num1[i] != '\0'; i++){
        num1Length++;
    }
    for(int i=0; num2[i] != '\0'; i++){
        num2Length++;
    }

    int startIdx;
    int endIdx;
    for(int i=num1Length-1, endIdx = SIZE - 1 - 1; i>=0; i--, endIdx--){
        num1[endIdx] = num1[i];
        num1[i] = -1;
    }
    num1[num1Length] = -1;
    num1[num1Length+1] = -1;
    num1[SIZE-1] = '\0';

    for(int i=num2Length-1, endIdx = SIZE - 1 - 1; i>= 0; i--,endIdx--){
        num2[endIdx] = num2[i];
        num2[i] = -1;
    }
    num2[num2Length] = -1;
    num2[num2Length] = -1;

    num2[SIZE -1] = '\0';

    // for(startIdx = SIZE-num1Length; startIdx<SIZE; startIdx++){
    //     printf("%c",num1[startIdx]);
    // }
    // putchar('\n');

    // for(startIdx = SIZE-num2Length; startIdx<SIZE; startIdx++){
    //     printf("%c",num2[startIdx]);
    // }

    char* pResult;
    //pResult = Add(num1, num1Length, num2, num2Length, result);
    pResult = Sub(num1, num1Length, num2, num2Length, result);

    for(int i=0; pResult[i] != '\0'; i++){
        printf("%c",pResult[i]);
    }
    putchar('\n');
    
    return 0;

    
    
}

//think carry
char* Add(char* num1, int num1Length, char* num2, int num2Length, char* result){
    int carry = 0;
    int maxLen = num1Length > num2Length ? num1Length : num2Length;
    for(int i=SIZE-1 -1; i>SIZE -1 -1 - maxLen; i--){
        int v1 = num1[i] - '0' >= 0 && num1[i] - '0' <= 9 ? num1[i] - '0' : 0;
        int v2 = num2[i] - '0' >= 0 && num2[i] - '0' <= 9 ? num2[i] - '0' : 0;

        int sum = v1 + v2 + carry;
        result[i] = sum % 10 + '0';
        carry = sum / 10;
    }

    
    if(carry > 0 && SIZE - 1 - 1 - maxLen >=0){
        result[SIZE -1 -1 -maxLen] = carry+'0';
        return &result[SIZE -1 -1 - maxLen];
    }else{
        return &result[SIZE -1 - maxLen];
    }
}

char* Sub(char* num1, int num1Length, char* num2, int num2Length, char* result){
    bool minusFlag = 0;
    if((num1Length < num2Length) || ((num1Length == num2Length) && (num1[SIZE-num1Length-1] < num2[SIZE-num1Length-1]))){
        minusFlag = 1;
        char* temp = num1;
        num1= num2;
        num2 = temp;

    }
    int maxLen = num1Length >= num2Length ? num1Length :num2Length;
    int carry = 0;
    for(int i = SIZE -1 -1; i>SIZE -1 -1 -maxLen; i--){
        int v1 = num1[i] - '0' >= 0 && num1[i] - '0' <= 9 ? num1[i] - '0' : 0;
        int v2 = num2[i] - '0' >= 0 && num2[i] - '0' <= 9 ? num2[i] - '0' : 0;

        int sub = v1 - v2 + carry;
        carry=0;
        if(sub == 0){
            result[i] = 0 + '0';
        }else if(sub >0){
            result[i] = sub + '0';
        }else{                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
            result[i] = 10 + sub + '0';
            carry = -1;
        }
    }

    if(minusFlag && SIZE -1 -1 - maxLen >=0){
        result[SIZE -1 -1 -maxLen] = '-';
        return &result[SIZE -1 -1 -maxLen];
    }else{
        return &result[SIZE -1 - maxLen];
    }
}