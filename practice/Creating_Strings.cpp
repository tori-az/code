// https://cses.fi/problemset/task/1622
// 枚舉
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-all-loops")
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long 
#define endl '\n'
const int MAX = 2e5+5;
const int INF = 9e18;
const int MOD = 1e9+7;
const double EPS = 1e-9;
using namespace std;
string s;
vector<char> v;

signed main(void){
    fastio
    cin >> s;
    sort(s.begin(), s.end());
    do{
        for(const auto i : s){
            v.emplace_back(i);
        }
    }while(next_permutation(s.begin(), s.end()));
    int vs = v.size(), n = s.size();
    cout << vs/n << endl;
    for(int i = 0; i < vs; i++){
        cout << v[i];
        if((i+1)%n == 0){
            cout << endl;
        }
    }
    return 0;
}