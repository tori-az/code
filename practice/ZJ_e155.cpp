// https://zerojudge.tw/ShowProblem?problemid=e155
// queue
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
queue<int> q;
vector<int> dis;

signed main(void){
    fastio
    while(cin >> n){
        if(n == 0)  break;
        dis.clear();
        while(!q.empty())   q.pop();
        for(int i = 1; i <= n; i++) q.push(i);
        while(q.size() > 1){
            dis.emplace_back(q.front());
            q.pop();
            q.push(q.front());
            q.pop();
        }
        cout << "Discarded cards: ";
        for(int i = 0; i < dis.size(); i++){
            cout << dis[i];
            if(i != dis.size()-1)   cout << ", ";
        }
        cout << endl << "Remaining card: " << q.front() << endl;
    }
    return 0;
}