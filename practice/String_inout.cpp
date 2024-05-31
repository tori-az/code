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

cin 會一直讀入直到遇見不是整數的字元
getline 會一直讀入直到遇見換行符號
cin 遇到換行停在換行的位置，這時使用 getline，就會吃到那個換行結束
因此讀到的字串什麼都沒有*/