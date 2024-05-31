// https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/A
#include <bits/stdc++.h>
#define int long long //TLE or MLE remove
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int n, k;
signed main(void){
    fastio
    
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    for(int i = 0; i < k; i++){
        int x;
        cin >> x;
        int l = 0, r = n - 1;
        bool ok = false;
        while(r >= l){
            int m = (r + l)/2;
            if(v[m] == x){
                ok = true;
                break;
            }else if(v[m] > x){
                r = m - 1;
            }else if(v[m] < x){
                l = m + 1;
            }
        }
        if(ok){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    
    return 0;
}