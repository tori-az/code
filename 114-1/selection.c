#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; ++i){
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < n - 1; ++i){ //跑到倒數第二個位置，最後一個就定位了
        int min_index = i;
        for(int j = i + 1; j < n; ++j){   
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        if(min_index != i){
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }

    for(int i = 0; i < n; ++i){
        printf("%d ", arr[i]);
    }

    return 0;
}