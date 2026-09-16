#include<stdio.h>

int main(){
    // arr[i][num] = 1 代表列或行的 num 已經有了
    int rck[9][10] = {0};
    int cck[9][10] = {0};
    // sck[i][j][num] 
    int sck[3][3][10] = {0};
    int valid = 1;
    int broad[9][9];

    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j){
            scanf("%d", &broad[i][j]);
            int n = broad[i][j];
            if(n < 1 || n > 10) valid = 0;
            
            if(rck[i][n] == 1)  valid = 0;
            else    rck[i][n] = 1;

            if(cck[j][n] == 1)  valid = 0;
            else    cck[j][n] = 1;

            int r = i / 3, c = j / 3;
            if(sck[r][c][n] == 1)   valid = 0;
            else    sck[r][c][n] = 1;
        }
    }

    printf("%s", valid ? "Valid" : "Invalid");
    return 0;
}