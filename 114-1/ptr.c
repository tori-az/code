#include<stdio.h>

int main(){
    int arr[5];
    int *ptr = arr;
    *ptr = 1;
    ptr = ptr + 1;
    *ptr = 2;
    *(ptr + 1) = 3;
    *(ptr + 3) = 4;
    arr[4] = 5;
    printf("%d %d %d %d %d", arr[0], arr[1], arr[2], arr[3], arr[4]);
    return 0;
}