#include<stdio.h>

int main(){
    int n, k;
    scanf("%d", &n);
    int arr[25][25] = {0};
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            scanf("%d", &arr[i][j]);
        }
    }

    scanf("%d", &k);
    int temp[25][25] = {0};
    while(k--){
        int type, move;
        scanf("%d%d", &type, &move);
        if(type == 1){
            int r = move;
            int last = arr[r][n-1];
            for(int i = n - 1; i >= 0; --i){
                if(i == 0)  arr[r][i] = last;
                else    arr[r][i] = arr[r][i-1]; 
            }
        }
        else if(type == 2){
            int c = move;
            int last = arr[n-1][c];
            for(int i = n - 1; i >= 0; --i){
                if(i == 0)  arr[i][c] = last;
                else    arr[i][c] = arr[i-1][c];
            }
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            printf("%d%s", arr[i][j], (j != n - 1) ? " " : "");
        }
        printf("\n");
    }

    return 0;
}