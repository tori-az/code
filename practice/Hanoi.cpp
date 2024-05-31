// https://zerojudge.tw/ShowProblem?problemid=a227
#include <bits/stdc++.h>
#define int long long //TLE or MLE remove
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
const double eps = 1e-9;
const double MAX = 1e5+5;

void hanoi(int n, char from, char mid, char to){
    if(n == 1){
        cout << "Move ring " << n << " from " << from << " to " << to << endl;
        return;
    }
    hanoi(n-1, from, to, mid);
    cout << "Move ring " << n << " from " << from << " to " << to << endl;
    hanoi(n-1, mid, from, to);
}

int n;

signed main(void){
    fastio
    
    while(cin >> n){
        hanoi(n,'A', 'B', 'C');
        cout << endl;
    }

    return 0;
}