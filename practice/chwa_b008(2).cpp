// http://judge.chwa.com.tw/ShowProblem?problemid=b008
// 字串，但比 (1) 的作法簡潔多了
#include<bits/stdc++.h>
#define tori_az ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
string s, t;

int main(){
    tori_az
    cin >> s;
    t = s;
    reverse(t.begin(), t.end());
    if(s == t)  cout << "YES" << endl;
    else    cout << "NO" << endl;
    return 0;
}
// 更多酷酷的庫(?)：https://en.cppreference.com/w/