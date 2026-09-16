#include<stdio.h>
#include<string.h>

int main(){
    char str[15];
    gets(str);
    
    if(strlen(str) != 9 || 
       str[0] != 'D' || 
       !(str[1] >= '1' && str[1] <= '3') ||
       !((str[2] >= '0' && str[2] <= '9') && (str[3] >= '0' && str[3] <= '9')) ||
       !((str[4] >= 'A' && str[4] <= 'Z') && (str[5] >= 'A' && str[5] <= 'Z')) ||
       !((str[6] >= '0' && str[6] <= '9') && (str[7] >= '0' && str[7] <= '9') && (str[8] >= '0' && str[8] <= '9'))){
        printf("Invalid");
    }else{
        printf("Valid");
    }
    return 0;
}