// https://toj.tfcis.org/oj/pro/485/
#include <bits/stdc++.h>
#define int long long //TLE or MLE remove
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
const double eps = 1e-9;

int n;
string s;

signed main(void){
    fastio
    
    cin >> n >> s;
    int ans = n - 1; // 最多 n - 1
    for(int i = n - 1; i >= 0; i--){
        bool is_p = 1;
        for(int l = i, r = n - 1; l < r; l++, r--){
            if(s[l] != s[r]){
                is_p = 0;
                break; // 元素不同，改變左界
            }
        }
        if(is_p)    ans = i; // 如果元素皆相同，改變左界和右界直到左界和右界差 1 (相鄰)，此時的 i 即為 ans
    }
    cout << ans << endl;
    return 0;
}