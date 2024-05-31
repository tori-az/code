// https://zerojudge.tw/ShowProblem?problemid=f312
#include<bits/stdc++.h>
using namespace std;

int a1,b1,c1,a2,b2,c2,n;

int main(){
    cin>>a1>>b1>>c1>>a2>>b2>>c2>>n;
    
    double x = 1.0 * (2 * a2 * n + b2 - b1) / (2 * (a1 + a2));
    // 找到二次函數極值發生的位置，與端點取max
    int ans = -100000000;

    int p = x, l = n-p;
    if(0 <= p && p <= n){
        int ans1 = a1 * p * p + b1 * p + c1 + a2 * l * l + b2 * l + c2;
        if(ans1 > ans) ans = ans1; // ans = max(ans, ans1)
    }

    // 微分後答案不一定是整數，因此要試兩個點
    p++, l--;
    if(0 <= p && p <= n){
        int ans1 = a1 * p * p + b1 * p + c1 + a2 * l * l + b2 * l + c2;
        if(ans1 > ans) ans = ans1;
    }
    
    int ans0 = a2 * n * n + b2 * n + c2 + c1; // 左端點
    int ansn = a1 * n * n + b1 * n + c1 + c2; // 右端點
    if(ans0 > ans) ans = ans0; // ans = max(ans, ans0)
    if(ansn > ans) ans = ansn; // ans = max(ans, ansn)
    cout<<ans<<'\n';
}