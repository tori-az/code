//https://toj.tfcis.org/oj/pro/119/
#include <bits/stdc++.h>
#define int long long //TLE or MLE remove
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
const double eps = 1e-9;

int n, t, a, b;
int arr[200005];
bool ok = 1;

signed main(void){
    fastio
    
    cin >> n;
    for(int i = 1; i <= n; i++)    cin >> arr[i];
    
    cin >> t;
    while(t--){
        cin >> a >> b;
        if(abs(a-b) > 8){  // abs : 絕對值函數
            ok = 0;
            break;
        }
        swap(arr[a], arr[b]);
    }
    
    if(ok)    cout << "SORTED!" << endl;
    else    cout << "I QUIT!" << endl;
    
    for(int i = 1; i <= n; i++){
        cout << arr[i];
        if(i < n)cout << " ";
        else    cout << endl;
    }
    
    return 0;
}