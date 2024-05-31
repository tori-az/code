// TOJ 47
#include<bits/stdc++.h>#include <bits/stdc++.h>
#define int long long //TLE or MLE remove
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;

int n, t, arr[1000005], k;

signed main(void){
    fastio
    cin >> n;
    for(int i = 1; i <= n; i++)    cin >> arr[i];
    sort(arr+1, arr+n+1);
    cin >> t;
    while(t--){
        cin >> k;
        int *big = lower_bound(arr+1, arr+n+1, k); // 宣告變數時在變數前加 * 表示此變數儲存地址(位址變數)
        int *small = big - 1;
        if(*big == k)    cout << k << endl; // 此處的 * 用於求值
        else{
            if(small == arr)    cout << "no "; // small 儲存的位址與 arr[0] 相同
            else    cout << *small << " ";
            if(big == arr+n+1)    cout << "no" << endl; // big 儲存的位址在 arr 最後一項的後一項(不存在)
            else    cout << *big << endl;
        }
    }
}