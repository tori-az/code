//https://toj.tfcis.org/oj/pro/104/
#include <bits/stdc++.h>
#define int long long //TLE or MLE remove
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
const double eps = 1e-9;

int n;

signed main(void){
    fastio
    
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < n-i; j++)    cout << " ";
        for(int j = 0; j < 2*i-1; j++)    cout << '*';
        cout << endl;
    }
    
    return 0;
}