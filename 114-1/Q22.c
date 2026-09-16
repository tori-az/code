#include <stdio.h>
#include <string.h>

int main(){
    char str1[105], str2[105];
    int sum[105]; 

    scanf("%s%s", str1, str2);

    int len1 = strlen(str1), len2 = strlen(str2);
    int i = len1 - 1, j = len2 - 1; // 指向兩個字串的最後一位
    
    int nxt = 0; // 進位變數
    int k = 0;     // 結果陣列的 index

    // 還有位數或者還有進位繼續迴圈
    while(i >= 0 || j >= 0 || nxt > 0){
        int d1 = 0, d2 = 0; // 當前位數值

        if(i >= 0){
            d1 = str1[i] - '0';
            --i;
        }
        if(j >= 0){
            d2 = str2[j] - '0';
            --j;
        }

        int tempSum = d1 + d2 + nxt;
        sum[k] = tempSum % 10;
        nxt = tempSum / 10;
        ++k;
    }

    // 反向列印
    for(int x = k - 1; x >= 0; --x){
        printf("%d", sum[x]);
    }

    return 0;
}