#include<stdio.h>

int main(){
    char s[501];
    gets(s);

    int l = 0, L = 0; // l 目前單字長，L 最長單字長

    for(int i = 0; s[i] != '\0'; ++i){
        char c = s[i];
        if((c >= 'a' && c <= 'z')||(c >= 'A' && c <= 'Z')){
            ++l;
        }else{
            if(l > L)   L = l;
            l = 0;
        }
    }
    if(l > L)   L = l; // 如果以字母結尾，上面迴圈不會進到 else

    printf("Longest Word Length: %d", L);
    return 0;
}