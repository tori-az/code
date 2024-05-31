// 大佬解
// TOJ 117
#include <iostream>
using namespace std;
int n, ans;

int main(){
    cin >> n;
    for (int i=0,tmp;i<n;i++){
        cin >> tmp;
        if(tmp > ans) ans = tmp;
    }
    cout << ans << '\n';
}

// 我的爛解
//https://toj.tfcis.org/oj/pro/117/
#include <bits/stdc++.h>
#define int long long //TLE or MLE remove
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
const double eps = 1e-9;

int a;
int ans;

signed main(void){
    fastio
    
    cin >> a;
    int arr[a];
    for(int i = 0; i < a; i++){
        cin >> arr[i];
        if(arr[i] > ans)    ans = arr[i];
    }
    cout << ans <<endl;
    
    return 0;
}