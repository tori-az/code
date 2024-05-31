// https://codeforces.com/problemset/problem/1921/B
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
string s, f;

signed main(void){
    tori_az
    cin >> t;
    while(t--){
        int cnt1 = 0, cnt2 = 0, ans = 0;
        cin >> n >> s >> f;
        for(int i = 0; i < n; ++i){
            if(s[i] != f[i] && s[i] == '1') ++cnt1;
            if(s[i] != f[i] && s[i] == '0') ++cnt2;
        }
        //cout << cnt1 << ' ' << cnt2 << endl;
        if(cnt1 == cnt2)    ans = cnt1;
        else if(cnt1 > cnt2)    ans = cnt1;
        else if(cnt2 > cnt1)    ans = cnt2;
        cout << ans << endl;
    }
    return 0;
}