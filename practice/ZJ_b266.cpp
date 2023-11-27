// https://zerojudge.tw/ShowProblem?problemid=b266
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
int R, C, M, arr[15][15], action[15];

void mirror(){
    int tmp[15][15];
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            tmp[i][j] = arr[R-i-1][j];
        }
    }
    swap(tmp, arr);
}

void rotate(){
    swap(R, C);
    int tmp[15][15];
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            tmp[i][j] = arr[j][R-i-1];
        }
    }
    swap(tmp, arr);    
}

signed main(void){
    fastio
    while(cin >> R >> C >> M){
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                cin >> arr[i][j];
            }
        }
        for(int i = 0; i < M; i++){
            cin >> action[i];
        }
        for(int i = M-1; i >= 0 ; i--){
            if(action[i] == 0)  rotate();
            else    mirror();
        }
        cout << R << ' ' << C << endl;
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                cout << arr[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}