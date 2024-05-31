//https://toj.tfcis.org/oj/pro/170/
#include <bits/stdc++.h>
#define int long long //TLE or MLE remove
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
const double eps = 1e-9;
const double MAX = 1e5+5;

int t, n;
char c;

void A(int n){
    for(int j = 1; j <= n; j++){
        for(int i = 1; i <= n - j; i++)    cout << " ";
        for(int i = 1; i <= 2 * j - 1; i++)    cout << '*';
        cout << endl;
    }
}

void B(int n){
    int w = 2;
    while(w--){
        for(int j = 1; j <= n; j++){
            for(int i = 1; i <= n - j; i++)    cout << " ";
            for(int i = 1; i <= 2 * j - 1; i++)    cout << '*';
            cout << endl;
        }
    }
}

void C(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            for(int k = 1; k <= n - j; k++)    cout << " ";
            for(int k = 1; k <= 2 * j - 1; k++)    cout << "*";
            cout << endl;
        }
    }
}

void E(int n){
    for(int j = 1; j <= n; j++){
        for(int i = 1; i <= n - j + 2; i++)    cout << " ";
        for(int i = 1; i <= 2 * j - 1; i++)    cout << '*';
        cout << endl;
    }
    for(int j = 1; j <= (n+1)*2 + 1; j++)    cout << "#";
    cout << endl;
}

signed main(void){
    fastio
    
    cin >> t;
    while(t--){
        cin >> c >> n;
        if(c == 'A')    A(n);
        else if(c == 'B')    B(n) ;
        else if(c == 'C')    C(n);
        else if(c == 'D')    A(10 * n);
        else if(c == 'E')    E(n);
        else if(c == 'F')    A(2 * n);
        else if(c == 'G')    A(3 * n);
        else if(c == 'H')    A(7 * n);
        else    A(4 * n - 1);
        cout << endl;
    }

    return 0;
// 我覺得我這次寫得特別好
}