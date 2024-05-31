// Q-1-5. 二維黑白影像編碼 (APCS201810)
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
string s;
int n, i = 0;

int encode(int m){
    char c = s[i++]; // 等同 char c = s[i]; i++;
    if(c == '0') return 0;
    else if(c == '1') return m*m;
    else if(c == '2'){
        int lu = encode(m/2);
        int ru = encode(m/2);
        int ld = encode(m/2);
        int rd = encode(m/2);
        return lu + ru + ld + rd;
    }
}

signed main(void){
    tori_az
    cin >> s >> n;
    cout << encode(n);
    return 0;
}