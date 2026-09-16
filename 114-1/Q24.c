#include<stdio.h>

int main(){
    char s[100];
    scanf("%s", s);
    int n = 0; // 重複次數

    for(int i = 0; s[i] != '\0'; ++i){
        if(s[i] >= '0' && s[i] <= '9'){
            n = n * 10 + (s[i] - '0');
        }else{
            int times = (n == 0) ? 1 : n;
            for(int j = 0; j < times; ++j){
                printf("%c", s[i]);
            }
            n = 0;
        }
    }
    
    return 0;
}