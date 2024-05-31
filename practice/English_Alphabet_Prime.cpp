// https://toj.tfcis.org/oj/chal/158394/
#include <bits/stdc++.h>
#define int long long //TLE or MLE remove
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int n;

signed main(void){
    fastio
    
    cin >> n;
    cout << char(n + 'A' - 1) << '\n';
            
    return 0;
}

// 可以使用 int() 得到一個字元的ASCII值
// cout << int('a') << '\n';
// output : 97

// 可以使用 char() 得到一個ASCII的值對應的字元
// cout << char(97) << '\n';
// output : a