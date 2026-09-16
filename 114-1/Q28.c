#include<stdio.h>

int main(){
    int n, m, p;
    scanf("%d%d%d", &n, &m, &p);

    int A[n][m], B[m][p], C[n][p];

    for(int i = 0; i < n; ++i) // 存 A
        for(int j = 0; j < m; ++j)
            scanf("%d", &A[i][j]);

    for(int i = 0; i < m; ++i) // 存 B
        for(int j = 0; j < p; ++j)
            scanf("%d", &B[i][j]);
        
    for(int i = 0; i < n; ++i) // 初始化 C
        for(int j = 0; j < p; ++j)
            C[i][j] = 0;

    for(int i = 0; i < n; ++i){ 
        for(int k = 0; k < m; ++k){
            int r = A[i][k];
            if(r == 0)  continue;
            for(int j = 0; j < p; ++j){
                C[i][j] += r * B[k][j]; // Cij=∑(Aik×Bkj)
            }
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < p; ++j){
            printf("%d%s", C[i][j], (j == p - 1) ? "" : " ");
        }
        printf("\n");
    }
    
    return 0;
}