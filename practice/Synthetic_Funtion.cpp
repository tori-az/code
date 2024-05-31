// https://judge.tcirc.tw/ShowProblem?problemid=d002
#include <bits/stdc++.h>
#define int long long //TLE or MLE remove
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
const double eps = 1e-9;
const double MAX = 1e5+5;

string s;

int solve(){
    cin >> s;
    if(s == "f"){
        int x = solve();
        return 2*x - 3;
    }
    else if(s == "g"){
        int x = solve();
        int y = solve();
        return 2*x + y - 7;
    }
    else if(s == "h"){
        int x = solve();
        int y = solve();
        int z = solve();
        return 3*x - 2*y + z;
    }
    else return stoi(s);
}

int stoi(string s){
    int ans = 0, st = 0;
    bool neg = 0;
    if(s[st] == '-')    neg = 1, st++;
    for(int i = st; i < s.size(); i++)    ans = 10 * ans + s[i] - '0';
    if(neg)    ans = -ans;
    return ans;
}

signed main(void){
    fastio
    
    cout << solve() << endl;

    return 0;
}