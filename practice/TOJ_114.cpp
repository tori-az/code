// https://toj.tfcis.org/oj/pro/114/
// 二維陣列
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-all-loops")
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long 
#define endl '\n'
const int MAX = 2e5+5;
const int INF = 9e18;
const int MOD = 1e9+7;
const double EPS = 1e-7;
using namespace std;
int arr[5][6]; // 橫排 5 排，一排 6 個
bool ok = 0;
signed main(void){
    fastio
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 6; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < 3; i++){  // 這樣 j+2 就不會超出陣列的範圍
        for(int j = 0; j < 4; j++){
            if(arr[i][j] == arr[i][j+1] && arr[i][j+1] == arr[i][j+2]){
                ok = 1;
            }
            if(arr[i][j] == arr[i+1][j] && arr[i+1][j] == arr[i+2][j]){
                ok = 1;
            }
        }
    }
    if(ok)  cout << "Yes";
    else    cout << "No";
    return 0;
}