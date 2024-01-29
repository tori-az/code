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

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a%b);
} // O(log a)

signed main(void){
    tori_az
    while(cin >> a >> b){
        cout << gcd(a, b) << ' ';
    }
    return 0;
}