#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int arr[15][15] = {0};
    int r = 0, c = 0; // (r, c)
    // dr 控制列，dc 控制行
    int dr = 0, dc = 1;  // 一開始向右，列不變行+1

    for(int i = 1; i <= n*n; ++i){
        arr[r][c] = i;
        // 下一步的位置
        int nr = r + dr;
        int nc = c + dc;
        if(nr >= n || nr < 0 || nc >= n || nc < 0 || arr[nr][nc] != 0){
            // (0, 1) -> (1, 0) -> (0, -1) -> (-1, 0) -> (0, 1)
            // dr = 舊 dc，dc = 舊 dr * -1
            int temp = dr;
            dr = dc;
            dc = -temp;
        }
        r += dr;
        c += dc;
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            printf("%3d", arr[i][j]);
            if(j < n-1) printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}