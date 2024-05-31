// P-1-3. 棍子中點切割
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
int n, l, p[50010];
/* 線性搜尋
int cut(int left, int right){
    if(right - left <= 1)   return 0; // 只剩一節
    int len = p[right] - p[left], k = (p[left] + p[right])/2, m = left;
    for(int i = (right - left)/2; i > 0; i >>= 1){
        while(m+i < right && p[m+i] < k)    m += i;
    }
    if(p[m] - p[left] < p[right] - p[m+1])  ++m; // p[m] 一定小於 k，所以要看 p[m+1] 是否離中點更近
    return len + cut(left, m) + cut(m, right);
}*/

/* 跳躍式二分搜
int cut(int left, int right){
    if(right - left <= 1)   return 0; // 只剩一節
    int len = p[right] - p[left], k = (p[left] + p[right])/2, m = left;
    while(p[m] < k) ++m;
    if(p[m-1] - p[left] >= p[right] - p[m]) --m; // p[m] 可能大於 k，看 p[m-1] 是否離中點更近，又因求座標較小的所以加上 =
    return len + cut(left, m) + cut(m, right);
}*/

// lower_bound(s, t, x) 求 s~t 中 >= x 的第一個位置
int cut(int left, int right){
    if(right - left <= 1)    return 0;
    int len = p[right] - p[left], k = (p[left] + p[right])/2, m = left;
    m = lower_bound(p+right, p+left, k) - p;
    if(p[m-1] - p[left] >= p[right] - p[m])  --m;
    return len + cut(left, m) + cut(m, right);
}

signed main(void){
    tori_az
    cin >> n >> l;
    p[0] = 0, p[n+1] = l;
    for(int i = 1; i <= n; ++i)  cin >> p[i];
    cout << cut(0, n+1);
    return 0;
}