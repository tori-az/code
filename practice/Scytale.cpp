//https://toj.tfcis.org/oj/pro/8/
#include <bits/stdc++.h>
#define int long long //TLE or MLE remove
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
const double eps = 1e-9;

int n;
string s;

signed main(void){
    fastio
    
    while(cin >> n){
        cin.ignore();
        getline(cin, s);
        int x = s.size()/n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < x; j++){
                cout << s[i+j*n];
                // 建議自己拿紙筆試試看
            }
        }
        cout << endl;
    }
    
    return 0;
}