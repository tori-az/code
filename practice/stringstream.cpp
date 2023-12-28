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
string s;
stringstream ss;

signed main(void){
    tori_az
    while(getline(cin, s)){
        ss.clear();
        ss.str(s);
        int add = 0, a;
        while(ss >> a)  add += a;
        cout << add << endl;
    }
    return 0;
}
/*
input:
123 456 789
1 2 3 4 5 6 7 8 9 10
11

output:
1368
55
11
*/