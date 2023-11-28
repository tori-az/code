// http://judge.chwa.com.tw/ShowProblem?problemid=b008
// 字串
#include<bits/stdc++.h>
#define tori_az ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
string s, tmp;
bool ok = 1;

int main(){
    tori_az
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        tmp[s.size()-1-i] = s[i];
    }
    for(int i = 0; i < s.size(); i++){
        if(s[i] != tmp[i]){
            ok = 0;
            break;
        }
    }
    if(ok)  cout << "YES" << endl;
    else    cout << "NO" << endl;
    return 0;
}