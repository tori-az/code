// http://judge.chwa.com.tw/ShowProblem?problemid=b002
// 其實不用陣列
#include<bits/stdc++.h>
using namespace std;
int n, ans = -1;
int ind = -1; // 在全華上使用 index 作為變數名稱會 CE

int main(){
    cin >> n;
    for(int i = 1, x; i <= n; i++){
        cin >> x;
        if(x > ans){
            ans = x;
            ind = i;
        }
    }
    cout << ind << ' ' << ans;
    return 0;
}