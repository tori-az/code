#include<stdio.h>

int main(){
    int r, c;
    scanf("%d%d", &r, &c);

    int grid[r][c];
    int k = 0; // 沒有被刪掉的要放的位子兼計數器

    for(int i = 0; i < r; ++i){
        int full = 1; // 預設滿列(要刪)
        for(int j = 0; j < c; ++j){
            scanf("%d", &grid[k][j]);
            if(grid[k][j] == 0){ // 讀到一個零代表不是滿列
                full = 0; 
            }
        }
        if(!full)   ++k; // 如果不是滿的(不用刪)就換下一列，是滿的話 k 不動，後面不是滿的會蓋掉它，最後一次會多 + 1
    }

    int empty = r - k;
    for(int i = 0; i < empty; ++i){
        for(int j = 0; j < c; ++j){
            printf("0%s", (j == c - 1) ? "" : " ");
        }
        printf("\n");
    }

    for(int i = 0; i < k; ++i){
        for(int j = 0; j < c; ++j){
            printf("%d%s", grid[i][j], (j == c - 1) ? "" : " ");
        }
        printf("\n");
    }

    return 0;
}


/*
#include<stdio.h>

int main(){
    int r, c;
    int grid[25][25] = {0}, result[25][25] = {0};
    scanf("%d%d", &r, &c);

    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            scanf("%d", &grid[i][j]);
        }
    }

    int k = r - 1; // 倒著掃回去
    for(int i = r - 1; i >= 0; --i){
        int full = 1;
        for(int j = 0; j < c; ++j){
            if(grid[i][j] == 0) {
                full = 0;
                break;
            }
        }

        if(!full){
            for(int j = 0; j < c; ++j){
                result[k][j] = grid[i][j];
            }
            --k;
        }
    }

    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            printf("%d%s", result[i][j], (j == c - 1) ? "" : " ");
        }
        printf("\n");
    }

    return 0;
}
*/