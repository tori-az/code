#include<stdio.h> // v1

int main(){
    int n; // n 天
    int max = -1, min = 200005; // max 紀錄最多的人數，min 紀錄最少的人數
    int p = 0, t = 0, l = 0;    // p : peak day, t = trough day, l = 遞增最長連續天數;

    scanf("%d", &n);
    int arr[n], L[n];   // arr 記人數，L 記遞增連續天數

    for(int i = 0, j; i < n; ++i){
        scanf("%d", &arr[i]);

        if(arr[i] > max){   // Peak Day
            max = arr[i];
            p = i + 1;
        }
        if(arr[i] < min){   // Trough Day
            min = arr[i];
            t = i + 1;
        }

        if(i > 0 && arr[i] > arr[i-1])  L[i] = L[i-1] + 1;  // Longest Boom
        else  L[i] = 1; // 中斷或 i = 0
        
        if(L[i] > l)    l = L[i];   // 更新 l
    }

    printf("Peak: Day %d (%d visitors)\nTrough: Day %d (%d visitors)\nLongest Boom: %d days", p, max, t, min, l);

    return 0;
}



/*#include<stdio.h> // v2

int main(){
    int n; // n 天
    int max = -1, min = 200005; // max 紀錄最多的人數，min 紀錄最少的人數
    int p = 0, t = 0, l = 0;    // p : peak day, t = trough day, l = 遞增最長連續天數;
    int prev, curr;   // 記上一天跟今天的人數

    scanf("%d", &n);
    int L[n];   // L 記遞增連續天數

    for(int i = 0, j; i < n; ++i){
        scanf("%d", &curr);

        if(curr > max){   // Peak Day
            max = curr;
            p = i + 1;
        }
        if(curr < min){   // Trough Day
            min = curr;
            t = i + 1;
        }

        if(i > 0 && curr > prev)  L[i] = L[i-1] + 1;  // Longest Boom
        else  L[i] = 1; // 中斷或 i = 0
        
        if(L[i] > l)    l = L[i];   // 更新 l
        prev = curr;    // 下一輪的 prev 是這輪的 curr
    }

    printf("Peak: Day %d (%d visitors)\nTrough: Day %d (%d visitors)\nLongest Boom: %d days", p, max, t, min, l);

    return 0;
}*/