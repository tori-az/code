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
int a, b;

int power(int a, int b){
    int res = 1;
    while(b){
        if(b & 1)   res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
} // O(log b)

signed main(void){
    tori_az
    while(cin >> a >> b){
        cout << power(a, b) << ' ';
    }
    return 0;
}