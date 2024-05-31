//https://toj.tfcis.org/oj/pro/114/
#include <bits/stdc++.h>
#define int long long //TLE or MLE remove
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
const double eps = 1e-9;

int n, ans;
int arr[5][6];

signed main(void){
    fastio
    
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 6; j++){
            cin >> arr[i][j];
        }
    }
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            if((arr[i][j+2] == arr[i][j+1] && arr[i][j+1] == arr[i][j]) || 
              (arr[i+2][j] == arr[i+1][j] && arr[i+1][j] == arr[i][j]))
                ans = 1;
        }
    }
    
    if(ans)    cout << "Yes" << endl;
    else    cout << "No" << endl;
    
    return 0;
}