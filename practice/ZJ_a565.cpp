// https://zerojudge.tw/ShowProblem?problemid=a565
// 聽說要用 stack :p
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

signed main(void){
    fastio
    cin >> n;
    while(n--){
        string s;
        int cnt = 0, ans = 0;
        cin >> s;
        int ss = s.size();
        for(int i = 0; i < ss; i++){
            if(s[i] == 'p') cnt++;
            else if(s[i] == 'q'){
                if(cnt > 0){
                    ans++;
                    cnt--;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}