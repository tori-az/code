// http://judge.chwa.com.tw/ShowProblem?problemid=b010
// ASCII
#include<bits/stdc++.h>
#define tori_az ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
string s;

int main(){
    tori_az
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        cout << (char)((s[i] - 'A' + 24) % 26 + 'A');
    }
    return 0;
}