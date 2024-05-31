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

int nq(int n){
    int p[n], total = 0;
    for(int i = 0; i < n; ++i)  p[i] = i;
    do{
        bool valid = true;
        for(int i = 0; i < n; ++i)  
            for(int j = i+1; j < n; ++j)
                if(abs(p[i] - p[j]) == j - i){
                    valid = false;
                    break;
                }
        if(valid)   ++total;
    }while(next_permutation(p, p+n));
    return total;
}

signed main(void){
    tori_az
    for(int i = 1; i < 12; ++i) cout << nq(i) << endl;
    return 0;
}
