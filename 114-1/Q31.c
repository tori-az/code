#include <stdio.h>
#include <stdlib.h>

// counting sort range 不能太大 只能排正整數 只保留了數值，丟失跟原資料的關聯(只知道這個數有幾個)
// 致命的缺點！！！知道有多少數字但不知道數字是什麼 小數的稠密性
// bubble sort 太慢

int n;
void bubble();

int main(){
    scanf("%d", &n);
    bubble(); 
    /*int zero = 0, one = 0, two = 0; // O(N)

    for(int i = 0, a; i < n; ++i){
        scanf("%d", &a);
        if(a == 0)  ++zero;
        else if(a == 1) ++one;
        else if(a == 2) ++two;
    }
    for(int i = 0; i < zero; ++i)   printf("0 ");
    for(int i = 0; i < one; ++i)    printf("1 ");
    for(int i = 0; i < two; ++i)    printf("2 ");*/

    return 0;
}

void bubble(){ // O(N^2)
    int *arr = (int*)malloc(n * sizeof(int));
    
    for(int i = 0; i < n; ++i){
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < n; ++i){
        int swaped = 0;
        for(int j = 0; j < n - 1 - i; ++j){
            if(arr[j] > arr[j+1]){
                swaped = 1;
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        if(swaped == 0) break;
    }

    for(int i = 0; i < n; ++i){
        printf("%d ", arr[i]);
    }
    
    free(arr);
}