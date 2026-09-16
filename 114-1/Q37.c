#include <stdio.h>
char arr[30][30]; 

int main(){
    int n, m;
    scanf("%d%d", &n, &m);

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            scanf(" %c", &arr[i][j]); // " %c" 忽略空白, \n, \t
        }
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            // 如果是落石直接印
            if(arr[i][j] == '*')   printf("*");
            else {
                // 計算周圍落石
                int cnt = 0;
                for(int di = -1; di <= 1; ++di){
                    for(int dj = -1; dj <= 1; ++dj){
                        if(arr[i + di][j + dj] == '*')    cnt++;
                    }
                }
                printf("%d", cnt);
            }

            if(j < m) printf(" ");
        }
        printf("\n");
    }

    return 0;
}