#include<stdio.h>

int main(){
    char s[100000];
    int shift;

    scanf("%s %d", s, &shift);
    shift = shift % 26;

    for(int i = 0; s[i] != '\0'; ++i){
        char c = s[i];

        if(c >= 'a' && c < 'z'){
            c = c - shift;
            while(c < 'a')  c += 26;
            while(c > 'z')  c -= 26;
        }
        else if(c >= 'A' && c <'Z'){
            c = c - shift;
            while(c < 'A')  c += 26;
            while(c > 'Z')  c -= 26;
        }

        s[i] = c;
    }

    printf("%s", s);
    return 0;
}
