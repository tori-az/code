// https://cses.fi/problemset/result/5855375/
#include <bits/stdc++.h>
#define int long long //TLE or MLE remove
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

char x;
int n, q;
int ax, ay, bx, by;

int v[1005][1005];
int pre[1005][1005];

signed main(void){
    fastio
    
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> x;
            if(x == '*'){
                v[i][j] = 1;
            }else{
                v[i][j] = 0;
            }
            pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + v[i][j];
        }
    }
    
    for(int i = 0; i < q; i ++){
        cin >> ay >> ax >> by >> bx;
        cout << pre[by][bx] - pre[by][ax-1] - pre[ay-1][bx] + pre[ay-1][ax-1] << '\n';
    }
    
    return 0;
}