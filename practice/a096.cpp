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
char ch;
int h, m, s;

signed main(void){
    tori_az
    cin >> h >> ch >> m >> ch >> s;
    int t1 = h*3600 + m*60 + s;
    cin >> h >> ch >> m >> ch >> s;
    int t2 = h*3600 + m*60 + s;
    int diff = t2 - t1;
    if(diff < 0)    diff += 24 * 3600;
    int hh = (diff / 3600) % 24;
    int mm = (diff % 3600) / 60;
    int ss = diff % 60;
    cout << setw(2) << setfill('0') << hh << ":"
         << setw(2) << setfill('0') << mm << ":"
         << setw(2) << setfill('0') << ss;
    return 0;
}