#include<stdio.h>

int main(){
    int a, b, c, d;
    for(int i = 0; i < 5; a = (i = i + 1))  printf("%d", a);
    printf("\n");
    for(int i = 0; i < 5; b = (i += 1)) printf("%d", b);
    printf("\n");
    for(int i = 0; i < 5; c = i++)  printf("%d", c);
    printf("\n");
    for(int i =0 ; i < 5; d = ++i)  printf("%d", d);
    
    return 0;
}
/*
i = i + 1 就是加法 計算 i 原值 + 1 再存回 i
i += 1 把 1 變成左邊變數 i 的型別再相加再存回 i
i++ 先賦值後加 ex.i = 3; b = i++;
b 先變成 3 再讓 i 變成 4
++i 先加再賦值 ex.i = 3; b = ++i;
i 先變成 4 再讓 b 變成 4
*/