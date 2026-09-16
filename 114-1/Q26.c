#include <stdio.h>

int main(){
    int arr[15][15] = {0}; 
    int n, m;
    scanf("%d%d", &n, &m);
    int hotspot = 0;
    
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            scanf("%d", &arr[i][j]);
        }
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(arr[i][j] > arr[i-1][j] &&
                arr[i][j] > arr[i+1][j] &&
                arr[i][j] > arr[i][j-1] &&
                arr[i][j] > arr[i][j+1]){
                printf("Row %d Col %d: %d\n", i - 1, j - 1, arr[i][j]);
                hotspot = 1;
            }
        }
    }

    if(!hotspot)    printf("None\n");

    return 0;
}