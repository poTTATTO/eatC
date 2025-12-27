#include<stdio.h>

int compare_strings(const char str1[], const char str2[]){
    int i=0;

    for(i=0; str1[i] != '\0' && str2[i] != '\0'; i++){
        if(str1[i] != str2[i])
            return 0;
    }

    if(str1[i] == '\0' && str2[i] == '\0')
        return 1;
    else
        return 0;
}
int main(){

    char str1[] = "aaabbb";
    char str2[] = "aaabbb";
    char str3[] = {"aaaccc"};

    printf("str1 : %s\n", str1);
    printf("str2 : %s\n", str2);
    printf("str3 : %s\n", str3);

    if(compare_strings(str1,str2))
        printf("%s\n","str1과 str2는 내용이 동일 합니다.");
    else
        printf("%s\n","str1과 str2는 내용이 동일 하지 않습니다.");
    if(compare_strings(str2, str3))
        printf("%s\n","str2과 str3는 내용이 동일 합니다.");
    else
        printf("%s\n","str2과 str3는 내용이 동일 하지 않습니다.");
        
    if(compare_strings(str1, str3))
        printf("%s\n","str1과 str3는 내용이 동일 합니다.");
    else
        printf("%s\n","str1과 str3는 내용이 동일 하지 않습니다.");
     

    return 0;
}