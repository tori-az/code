#include<stdio.h>

int main(){
    int n, s, choice[200005] = {}; // 紀錄每個代碼出現幾次

    scanf("%d", &n);
    int arr[n];

    for(int i = 0; i < n; ++i){
        scanf("%d", &arr[i]);
        int j = arr[i];
        choice[j]++;
    }

    scanf("%d", &s);
    printf("Reversed List: ");
    for(int i = n-1; i >= 0; --i)   i == 0 ? printf("%d", arr[i]) : printf("%d ", arr[i]);
    printf("\nSearch Count: %d", choice[s]);
    return 0;
}