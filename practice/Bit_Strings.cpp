// https://cses.fi/problemset/task/1617
// 數學
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-all-loops")
#define tori_az ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long 
#define endl '\n'
const int MAX = 2e5+5;
const int INF = 9e18;
const int MOD = 1e9+7;
const double EPS = 1e-9;
using namespace std;
int n, ans = 1;

signed main(void){
    tori_az
    cin >> n;
    for(int i = 0; i < n; i++){
        ans *= 2;
        ans %= MOD; // 記得取餘數不然會 overflow
    }
    cout << ans;
    return 0;
}