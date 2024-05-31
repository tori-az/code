// https://cses.fi/problemset/task/1646
#include <bits/stdc++.h>
#define int long long //TLE or MLE remove
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int n, k, a, b;

signed main(void){
    fastio
    
    // input
    cin >> n >> k;
    vector<int> v(n+1);
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    
    // 前綴和
    vector<int> pre(n+1);
    for(int i = 1; i <= n; i++){
        pre[i] = pre[i-1] + v[i];
    }
    
    // output
    for(int i = 0; i < k; i++){
        cin >> a >> b;
        cout << pre[b] - pre[a-1] << '\n';
    }
    
    return 0;
}