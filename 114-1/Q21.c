#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int M = 0, m = 0; // M 歷史最大連續總和，m 目前累計

    for(int i = 0, a; i < n; ++i){
        scanf("%d", &a); // a 每天舒適度
        m += a;
        if (m > M)  M = m;
        if (m < 0)  m = 0;
    }

    printf("%d\n", M);
    return 0;
}