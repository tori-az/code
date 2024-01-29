// sample
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-all-loops")
#define tori_az ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long 
#define endl '\n'
const int MAX = 2e5+5;
const int INF = 9e18;
const int MOD = 1e9+7;
const double EPS = 1e-9;
using namespace std;
tuple<int, int, int, int> a(1, 2, 3, 4), b;

signed main(void){
    tori_az
    b = make_tuple(4, 3, 2, 1);
    a = {5, 6, 7, 8};
    get<0>(a) = 10;
    cout << "a0 = " << get<0>(a) << endl;
    int w, x, z;
    tie(w, x, ignore, z) = b; // 用 ignore 忽略不想拿的資料
    cout << w << ' ' << x << ' ' << z << endl;
    return 0;
}