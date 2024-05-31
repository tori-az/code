//https://toj.tfcis.org/oj/chal/158422/
#include <bits/stdc++.h>
#define int long long //TLE or MLE remove
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;

int n, k, x;

signed main(void){
    fastio
    
    cin >> n >> k;
    int max = 0, sec = 0;
    while(n--){
        cin >> x;
        if (x > max){
            sec = max;
            max = x;
        }else if (x > sec)
            sec = x;
    }
    cout << sec << endl;
    
    return 0;
}