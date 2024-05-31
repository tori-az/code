// https://toj.tfcis.org/oj/pro/99/
#include <bits/stdc++.h>
#define int long long //TLE or MLE remove
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

double eps = 1e-7;
double a, b, c, d;

signed main(void){
    fastio
    
    cin >> a >> b >> c >> d;
    if(((a * d) - (b * c)) < eps && ((a * d) - (b * c)) > -eps)
        cout << 0 << '\n';
    else
        cout << 1 << '\n';
            
    return 0;
}

// 判斷兩個浮點數是否相等，需判斷他們之間的差的絕對值是否小於某個特定值，這個值我們稱作 epsilon，以 eps 在程式中出現，一般為 10 的 -9 次方，寫作 1e-9。