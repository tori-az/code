// https://domen111.github.io/UVa-Easy-Viewer/?10189
// 二維陣列
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-all-loops")
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long 
#define endl '\n'
const int MAX = 2e5+5;
const int INF = 9e18;
const int MOD = 1e9+7;
const double EPS = 1e-7;
using namespace std;
char arr[105][105];
int cnt[105][105];
int n, m, t;

signed main(void){
    fastio
    while(cin >> n >> m){
        if(n == 0 || m == 0)    continue;
        t++;
        for(int i = 0; i <= n+1; i++){
            for(int j = 0; j <= m+1; j++){
                if(i == 0 || i == n+1 || j == 0 || j == m+1)    cnt[i][j] = -1;
                else    cnt[i][j] = 0;
            }
        } // 避免溢位
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> arr[i][j];
            }
        }
        for(int i = 1; i <= n; i++){
           for(int j = 1; j <= m; j++){
                if(arr[i][j] == '*'){
                    cnt[i][j] = '*';
                    for(int k = i-1; k <= i+1; k++){
                       for(int l = j-1; l <= j+1; l++){
                            if(cnt[k][l] != '*')   cnt[k][l]++;
                        }
                    }
                }
            }
        }
        cout << "Field #" << t << ':' << endl;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(cnt[i][j] > 8)   cout << (char)cnt[i][j];
                else    cout << cnt[i][j];
            }
            cout << endl;
        }
        cout << endl;    
    }
    return 0;
}