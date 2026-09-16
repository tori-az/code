#include<stdio.h>
int grid[55][55]; // 全域變數預設 0
int temp[55][55]; // 不能直接改 grid 的值所以用另一個陣列

int neighbors(int x, int y){ // 算活鄰居數量，因為有補零不用考慮邊界
    int count = 0;
    for(int i = -1; i <= 1; ++i){
        for(int j = -1; j <= 1; ++j){
            if(i == 0 && j == 0)    continue; // 是自己跳過
            if(grid[x + i][y + j] == 1) ++count;
        }
    }
    return count;
}

int main(){
    int r, c, k;
    scanf("%d%d%d", &r, &c, &k);
    
    for(int i = 1; i <= r; ++i)
        for(int j = 1; j <= c; ++j)
            scanf("%d", &grid[i][j]);

    while(k--){
        for(int i = 1; i <= r; ++i){
            for(int j = 1; j <= c; ++j){
                int cnt = neighbors(i, j);

                if(grid[i][j] == 1){  // 活的
                    if(cnt == 2 || cnt == 3)    temp[i][j] = 1; // 繼續活
                    else    temp[i][j] = 0; // 死了
                }else{ // 死的
                    if(cnt == 3)    temp[i][j] = 1; // 復活
                    else    temp[i][j] = 0; // 繼續死
                }
            }
        }

        for(int i = 1; i <= r; ++i)
            for(int j = 1; j <= c; ++j)
                grid[i][j] = temp[i][j]; // 下一輪用新的

    }

    for(int i = 1; i <= r; ++i){
        for(int j = 1; j <= c; ++j){
            printf("%d%s", grid[i][j], (j < c) ? " " : "");
        }
        printf("\n");
    }
    return 0;
}

/*
死亡 (Die):

    如果鄰居活細胞 少於 2 個 (太孤單)。

    如果鄰居活細胞 多於 3 個 (太擁擠)。

    結果：該細胞下一回合變成「死」(0)。

生存 (Survive):

    如果該細胞原本是活的，且鄰居活細胞剛好是 2 個 或 3 個。

    結果：該細胞下一回合繼續保持「活」(1)。

繁殖 (Reproduce):

    如果該細胞原本是死的，但鄰居活細胞剛好是 3 個。

    結果：該細胞下一回合變成「活」(1)。
*/