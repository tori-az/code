#include <stdio.h>

int main() {
    int N;
    // input
    scanf("%d", &N);

    // process
    for (int i = 0; i < N; ++i) {
        int a = abs(N/2 - i);     // abs() 絕對值
        int b = N - (2*a);
        printf("%*s", a, "");     // 右對齊、最小寬度為 a 的空字串，也就是印出 a 個空格
        for (int j = 0; j < b; ++j) printf("*");
        printf("\n");
    }

    return 0;
}

/*
#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);

    int a = N / 2; // 空格
    int b = 1;     // 星號

    for (int i = 0; i < N; ++i) {
        printf("%*s", a, "");
        for (int j = 0; j < b; ++j) printf("*");
        printf("\n");

        if (i < N / 2) {  // 上半(含中間)
            --a;
            b += 2;
        } else {          // 下半
            ++a;
            b -= 2;
        }
    }
}
*/