#include<stdio.h>

int main(){
    int N, tot = 0, a;
    scanf("%d", &N);
    for(int i = 0, w; i < N; ++i){
        scanf("%d", &w);
        if(w >= 250 && w <= 270)    ++tot;
    }
    printf("Total Qualified Boxes: %d", tot);
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