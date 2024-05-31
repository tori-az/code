// Q-1-4. 支點切割 (APCS201802) 
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
int n, k, p[MAX];

int cut(int left, int right, int cnt){
    int size = right - left;
    if(size < 3 || cnt > k)    return 0;
    // 找到 m
    int m, sum[n];
    for(int i = 1; i < n-1; ++i){
        sum[i] = 0;
        for(int j = 0; j < n; ++j){
            sum[i] += p[j]*abs(i-j);
        }
        if(i != 1 && sum[i] < sum[i-1])   m = i;
        if(size == 4 && sum[i] > sum[i-1])  m = i-1;
        if(size == 3)  m = 1;
    }
    ++cnt;
    return p[m] + cut(left, m - 1, cnt) + cut(m + 1, right, cnt);
}

signed main(void){
    tori_az
    cin >> n >> k;
    for(int i = 0; i < n; ++i)  cin >> p[i];
    cout << cut(0, n-1, 1);
    return 0;
}