// https://zerojudge.tw/ShowProblem?problemid=c123
// stack
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-all-loops")
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long 
#define endl '\n'
const int MAX = 2e5+5;
const int INF = 9e18;
const int MOD = 1e9+7;
const double EPS = 1e-9;
using namespace std;
int n;
stack<int> station;
queue<int> train;

signed main(void){
    fastio
    while(cin >> n){
        if(n == 0)  break;
        while(1){
            while(!station.empty())   station.pop();
            while(!train.empty())   train.pop();
            for(int i = 1; i <= n; i++) train.push(i); // 每筆測試都要重新測   
            bool ok = 1, out = 0;
            for(int i = 0, x; i < n; i++){
                cin >> x;
                if(x == 0){
                    out = 1;
                    break;
                }
                while(station.empty() || station.top() != x){
                    if(train.empty()){
                        ok = 0;
                        break;
                    }
                    else{
                        station.push(train.front());
                        train.pop();
                    }
                }
                if(ok)  station.pop(); // 出站
            }
            if(out){
                cout << endl;
                break;
            }
            if(ok)  cout << "Yes" << endl;
            else    cout << "No" << endl;
        }
    }
    return 0;
}