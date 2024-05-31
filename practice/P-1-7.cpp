// P-1-7. 子集合乘積
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
int n, P = 10009, ans = 0;
int a[26];

void solve1(){
    cin >> n;
    vector<int> v(n);
    for(int& i : v)  cin >> i;
    for(int i = 0; i < (1 << n); ++i){
        int prod = 1;
        for(int j = 0; j < n; ++j){
            if((i >> j) & 1){
                prod = (prod*v[j])%P;
            }
        }
        if(prod == 1)   ++ans;
    }
    cout << ans;
}

void rec(int i, int prod){
    if(i >= n){
        if(prod == 1)   ++ans;
        return;
    }
    rec(i+1, (a[i]*prod)%P);
    rec(i+1, prod);
    return;
}

void solve2(){
    cin >> n;
    for(int i = 0; i < n; ++i)  cin >> a[i];
    rec(0, 1);
}

signed main(void){
    tori_az
    solve2();
    cout << ans-1;
    return 0;
}