// https://cses.fi/problemset/task/1069/
#include <bits/stdc++.h>
#define int long long //TLE or MLE remove
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;

string dna;
int now = 1;
int ans = 1;

signed main(void){
    fastio

    cin >> dna;
    for(int i = 0; i < dna.size(); i++){
        if(dna[i] == dna[i-1])    now++;
        else{
            ans = max(now, ans);
            now = 1;
        }
    }
    ans = max(now, ans);
    cout << ans;
    return 0;
}