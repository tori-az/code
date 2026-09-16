#include<stdio.h>
#include<string.h>

int main() {
    char s[501];
    gets(s);

    int len = strlen(s);
    int L = 0;
    int ind = 0; // 記回文起點

    for(int i = 0; i < len; ++i) {
        if(s[i] == ' ') continue; // 開頭不能空白
        if(len - i <= L) break; // 如果剩下的長度 (l - i) 比目前找到的 L 還短，後面不會有更長的迴文

        for(int j = len - 1; j >= i; --j) { // 從最後面開始往前找 (找子字串的結尾)
            if(j - i + 1 <= L) break; // 如果當前檢查的長度比 L 小，就跳下個 i
            if(s[j] == ' ') continue; // 結尾不能是空白

            if(s[i] == s[j]) {
                int left = i;
                int right = j;
                int a = 1; // a 看是不是回文

                while(left < right) {
                    if(s[left] != s[right]) {
                        a = 0;
                        break;
                    }
                    left++;
                    right--;
                }

                if(a) {
                    int l = j - i + 1; // 目前回文長
                    if(l > L) {
                        L = l;
                        ind = i;
                    }
                    break; 
                }
            }
        }
    }

    // 輸出結果
    for(int k = 0; k < L; ++k) {
        printf("%c", s[ind + k]);
    }
    printf("\n");

    return 0;
}
