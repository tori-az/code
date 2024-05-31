//https://toj.tfcis.org/oj/pro/106/
#include <bits/stdc++.h>
#define int long long //TLE or MLE remove
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
const double eps = 1e-9;

int n = 2;

signed main(void){
    fastio
    
    while(n % 71 != 0)    n = n*2 + 1;
    if(n % 3 == 0)        cout << "right" << endl;
    else                cout << "left" << endl;
    
    return 0;
}