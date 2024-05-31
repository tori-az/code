// https://toj.tfcis.org/oj/pro/575/
#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, k;
int a, b;
vector<int> v[1000001];

signed main(void){
    // fast IO
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // input
    cin >> n >> k;
    for(int i = 0; i < k; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    // output
    for(int i = 1; i <= n; i++){
        sort(v[i].begin(), v[i].end());
        
        for(int j = 0; j < v[i].size(); j++){
            cout << v[i][j];
            
            if(j != v[i].size()-1)
            cout << " ";
        }
        
        cout << '\n';
    }
    
    return 0;
}