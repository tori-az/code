#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
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

    return 0;
}
//氣泡排序的交換次數，等於這個陣列的「逆序對 (Inversion)」數量
//簡單來說，「逆序」是一個數字排在另一個比它小的數字前面