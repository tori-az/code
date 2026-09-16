#include<stdio.h>

int main(){
    char str[1024];
    scanf("%s", str);  // 放不放 & 都會過
    printf("%s", str);

    return 0;
}