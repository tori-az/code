// https://codeforces.com/problemset/problem/1927/A
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
int t, n;
char s[15];

signed main(void){
    tori_az
    cin >> t;
    while(t--){
        int ans = 0;
        cin >> n >> s;
        for(int i = n-1; i >= 0; --i){
            if(s[i] == 'B'){
                ans = i;
                break;
            }
        }
        for(int i = 0; i < n; ++i){
            if(s[i] == 'B'){
                ans -= i;
                ++ans;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}