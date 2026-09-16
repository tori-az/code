#include<stdio.h>

int main(){
    int start, end, sum = 0;

    // input
    scanf("%d %d", &start, &end);

    // process
    for(int i = start; i <= end; ++i){
        int a = i /10000;
        int b = i % 10000 / 1000;
        int c = i % 1000 / 100;
        int d = i % 100 / 10;
        int e = i % 10;

        // 如果不是 M 型數字或是有重複數字就跳掉
        if(a >= b || b <= c || c >= d || d <= e) continue; // continue 當作本次迴圈執行完畢，回到迴圈的條件式判斷
        if(a == b || a == c || a == d || a == e ||
           b == c || b == d || b == e ||
           c == d || c == e ||
           d == e) continue;

        // M 型數字不會被跳掉，在這裡加總
        sum += i;
        //printf("%d\n", i);
    }

    // output
    sum ? printf("%d", sum) : printf("0");

    return 0;
}







/* process(不用 continue)

for(int i = start, x; i <= end; ++i, x = 0){ // x 紀錄狀態
    int a = i /10000;
    int b = i % 10000 / 1000;
    int c = i % 1000 / 100;
    int d = i % 100 / 10;
    int e = i % 10;

    if(a < b && b > c && c < d && d > e)    ++x;
    // if a == b，x 不會加不會減，維持 0
    if(a == c || a == d || a == e || b == d || b == e || c == e) --x;
    
    // x == 1 是 M 型且沒重複數字的狀況，如果是的話就加上
    if(x == 1)   sum += i;
}
*/
