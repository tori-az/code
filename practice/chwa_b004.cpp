// http://judge.chwa.com.tw/ShowProblem?problemid=b004
// 一維陣列
#include<bits/stdc++.h>
#define tori_az ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
/* cin/cout 較 scanf/printf 效率來得低，上面這行可以優化 cin/cout 的效率(原理可參照最後的網址) */
#define endl '\n' /* '\n' 比 endl 快(原理可參照最後的網址)，由於筆者習慣使用 endl，便將 endl 定義為 '\n' */
using namespace std;
int n, m, back[50];

int main(){
    tori_az
    cin >> n >> m;
    for(int i = 1, x; i <= m; i++){
        cin >> x;
        back[x]++; 
    }
    for(int i = 1; i <= n; i++){
        if(back[i] == 0){
            cout << i << ' ';
        }
    }
    return 0;
}

// https://cp.wiwiho.me/io-optimize/ I/O 優化