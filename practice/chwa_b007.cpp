// http://judge.chwa.com.tw/ShowProblem?problemid=b007
// 字串（有字元解法，但筆者習慣用字串）
#include<bits/stdc++.h>
#define tori_az ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
string s;

int main(){
    tori_az
    cin >> s;
    for(int i = s.size()-1; i >= 0; i--){
        cout << s[i];
    }
    return 0;
}