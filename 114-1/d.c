#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int a = m, b = n * m; 

    for (int i = 0; i < 2 * n + 1; ++i) {
        if (i < n) {
            printf("%*s", b, "");
            printf("/");
            for (int j = 0; j < a; ++j) {
                printf("*");
            }
            printf("\\"); 
            a += 2 * m;
            b -= m;
        } 
        else if (i == n) {
            printf("|");
            for (int j = 0; j < a; ++j) {
                printf("*");
            }
            printf("|");
            a -= 2 * m;
            b += m;
        } 
        else {
            printf("%*s", b, "");
            printf("\\"); 
            for (int j = 0; j < a; ++j) {
                printf("*");
            }
            printf("/");
            a -= 2 * m;
            b += m;
        }
        printf("\n");
    }
    return 0;
}