// 我的爛解
//https://toj.tfcis.org/oj/pro/107/
#include <bits/stdc++.h>
#define int long long //TLE or MLE remove
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
const double eps = 1e-9;

int s;
int d;
int g;

signed main(void){
    fastio
    for(int i = 1; i <= 30; i++){
        s++;
        d += i;
        g = d*i+g;
    }
    cout << s+d+g <<endl;
    
    return 0;
}

//TOJ 107 大佬解
#include<bits/stdc++.h>
using namespace std;

int n=30, ans;

int main(){
    for(int i=1;i<=n;i++){
        int son = 1;
        int dau = i;
        int son_son = i * (i * (i+1) / 2);
        ans += son + dau + son_son;
    }
    cout<<ans<<'\n';
}