#include<stdio.h>
#define MAX(a, b) ((a > b) ? (a) : (b))
#define MIN(a, b) ((a < b) ? (a) : (b))

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int arr[n][m]; // 地形
    int water[n][m]; // 水位+地形

    for(int i = 0; i < n; ++i){
        for(int j = 0 ; j < m; ++j){
            scanf("%d", &arr[i][j]);
            
            if(i == 0 || i == n - 1 || j == 0 || j == m - 1)
                water[i][j] = arr[i][j]; // 邊界不蓄水流光光
            else
                water[i][j] = 100; // 先讓裡面的全部灌到 100 
        }
    }

    int changed = 1; // 檢查整張地圖跑完有沒有動過，沒有就是做完
    while(changed == 1){
        changed = 0; 
        // 檢查內部格子
        for(int i = 1; i < n - 1; ++i){
            for(int j = 1; j < m - 1; ++j){
                // 找出水位最低的鄰居
                int min = MIN(water[i+1][j], MIN(water[i-1][j], MIN(water[i][j+1], water[i][j-1])));
                // 最高不超過鄰居水位，超過就流到跟鄰居一樣高，但水位+地形最低跟原本地形一樣
                int target = MAX(arr[i][j], min);

                if(water[i][j] > target){
                    water[i][j] = target;
                    changed = 1; // 動了就設為 1 表示有動
                }
            }
        }
    }

    int sum = 0; 
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            // 水量 = 水位 - 地形
            sum += (water[i][j] - arr[i][j]);
        }
    }

    printf("%d", sum);
    return 0;
}