// https://cses.fi/problemset/task/1083
#include <bits/stdc++.h>
#define int long long //TLE or MLE remove
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;

int n, tot, sum, tmp;
int arr[200005];

signed main(void){
    fastio

    cin >> n;
    tot = ((n + 1)*n)/2;
    for(int i = 1; i <= n-1; i++){
        cin >> tmp;
        sum += tmp;
    }
    cout << tot-sum;
    
    return 0;
}