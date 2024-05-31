// Q-1-2. 合成函數(2) (APCS201902)
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

int eval(){
    int x, y, z;
    char token[15];
    cin >> token;
    if(token[0] == 'h'){
        x = eval();
        y = eval();
        z = eval();
        return 3*x - 2*y + z;
    }
    else if(token[0] == 'f'){
        x = eval();
        return 2*x - 3;
    }
    else if(token[0] == 'g'){
        x = eval();
        y = eval();
        return 2*x + y - 7;
    }
    else{
        return atoi(token);
    }
}

signed main(void){
    tori_az
    cout << eval();
    return 0;
}