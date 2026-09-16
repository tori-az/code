#include<stdio.h>

int main(){
    int sum = 0, arr[7] = {};
    double ave;
    for(int i = 0; i < 7; ++i){
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    ave = sum / 7.0;
    
    printf("Total Visitors: %d\nAverage Visitors: %.1lf\n", sum, ave);
    printf("%lf", ave);
    return 0;
}