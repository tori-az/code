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
int n;

void LinearSieve(int M){
    vector<int> primes;
    vector<bool> notPrime(M+1);
    notPrime[0] = notPrime[1] = true;
    for(int i = 2; i <= M; i++){
        if(notPrime[i] == false)    primes.emplace_back(i);
        for(auto p : primes){
            if(i*p > M) break;
            notPrime[i*p] = true;
            if(i%p == 0)    break; // 所有合數只會被最小的質因數篩到一次
        }
    }
    int s = primes.size();
    for(int i = 0; i < s; i++){
        cout << primes[i] << ' '; // 輸出範圍 2~M 的質數
    }
    return;
}

signed main(void){
    tori_az
    cin >> n;
    LinearSieve(n);

    return 0;
}