#include<stdio.h>

int get_average(int r, int c, int N, int M, int grid[20][20]){
    int sum = 0, n = 0;
    for(int i = -1; i < 2; ++i){
        for(int j = -1; j < 2; ++j){
            if(r + i >= 0 && c + j >= 0 && r + i < N && c + j < M){
                sum += grid[r + i][c + j];
                ++n;
            }
        }
    }

    return (sum/n);
}

int main(){
    int arr[20][20] = {0};
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            scanf("%d", &arr[i][j]);
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            printf("%d%s", get_average(i, j, n, m, arr), (j != m - 1) ? " " : "");
        }
        printf("\n");
    }

    return 0;
}