//https://emanlaicepsa.github.io/2020/11/04/0-6/
#include <bits/stdc++.h>
#define int long long //TLE or MLE remove
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

string s;
int n;

signed main(void){
    fastio
    
    cin >> n;
    // 為了解決上述的問題，可以用 cin.ignore() 來表示我要忽略下一個字元
    cin.ignore();
    getline(cin, s);
    cout << n << '\n';
    cout << s << '\n';
    
    return 0;
}

/*
input :
3
dasd fasf gasf 
output :
3
dasd fasf gasf 
這樣一來，換行字元就成功被跳過了！*/