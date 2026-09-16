#include<stdio.h>

int main(){
    char h[100000], n[100000];
    gets(h);
    gets(n);
    int ind = -1, j = 0;

    for(int i = 0; h[i] != '\0'; ){
        if(h[i] == n[j]){
            if(j == 0)  ind = i; // 在剛開始記起點
            ++i;
            ++j;
            if(n[j] == '\0'){ // j 到關鍵字結尾代表全對
                break;
            }
        }else{
            if(j > 0){  // 配到一半失敗
                i = i - j + 1; // 要回到剛剛嘗試的起點的下一個
                j = 0;
            }else{ // 第一個就錯直接往後
                ++i;
            }
            ind = -1;
        }
    }
    
    // 看是不是因為 h 結束才跑完的
    if(n[j] != '\0')    ind = -1;

    printf("%d", ind);
    return 0;
}