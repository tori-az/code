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
int t;

void solve() {
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    for(int i = 3; i <= 6; ++i){
        int x = a[0] + a[1] + a[2];
        if(x % i != 0)  continue;
        int y = x / i;
        if(a[0] < y)    continue;
        if(a[0] % y != 0 || a[1] % y != 0 || a[2] % y != 0) continue;
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
}

signed main(void){
    tori_az
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}