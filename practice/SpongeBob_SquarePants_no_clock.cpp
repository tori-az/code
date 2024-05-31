// https://toj.tfcis.org/oj/pro/461/
#include <bits/stdc++.h>
#define int long long //TLE or MLE remove
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

double x;

signed main(void) {
    fastio
    
    cin >> x;
    if(x == 0 || x == 180)    cout << "2\n";
    else                      cout << "4\n";
    
    
    return 0;
}