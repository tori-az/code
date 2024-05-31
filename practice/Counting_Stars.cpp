// 我的解
// https://toj.tfcis.org/oj/pro/120/
#include <bits/stdc++.h>
#define int long long //TLE or MLE remove
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
const double eps = 1e-9;

int n, q;
int a, b;
int tmp;
vector<int> v(1);
vector<int> pre(1);

signed main(void){
    fastio
    
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> tmp;
        v.push_back(tmp);
        pre.push_back(pre[i-1] + v[i]);
    }
    cin >> q;
    while(q--){
        cin >> a >> b;
        if(a > b)    swap(a, b);
        cout << pre[b] - pre[a-1] << endl;
    }
    
    return 0;
}

// 大佬解
// TOJ 120
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n, q, arr[200005], pre[200005]; //關鍵字：前綴和

int main(){
    ios::sync_with_stdio(0), cin.tie(0);// 看不懂的話，複習0-6進階輸入輸出
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i], pre[i] = pre[i-1] + arr[i];
    cin>>q;
    for(int i=1,l,r;i<=q;i++){
        cin>>l>>r;
        if(l>r) swap(l, r);
        cout<<pre[r] - pre[l-1]<<'\n';
    }
}