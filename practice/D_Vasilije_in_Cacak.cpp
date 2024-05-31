#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#define tori_az ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long 
#define endl '\n'
const int MAX = 2e5+5;
const int INF = 9e18;
const int MOD = 1e9+7;
const double EPS = 1e-9;
using namespace std;

signed main(void) {
    tori_az
    int t; 
    cin >> t;
    while(t--){
        int n, k, x; 
        cin >> n >> k >> x;
        int mn = (k * (k + 1)) / 2, mx = (k * (2 * n + 1 - k)) / 2;
        if(mn <= x && x <= mx) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}