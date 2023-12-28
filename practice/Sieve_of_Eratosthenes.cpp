// sample
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-all-loops")
#define tori_az ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long 
#define endl '\n'
const int MAX = 2e5+5;
const int INF = 9e18;
const int MOD = 1e9+7;
const double EPS = 1e-9;
using namespace std;
int m;

void PrimeFactors(int M){
    vector<bool> checked(M+1, false);
    vector<vector<int>> pFactors(M+1);
    for(int i = 2; i <= M; i++){
        if(checked[i] == false){
            for(int j = i; j <= M; j += i){
                if(j != i)  checked[j] = true; // 保存質數
                pFactors[j].push_back(i);
            }
        }
    }
    for(int i = 2; i < m+1; i++){
        if(checked[i] == true)  cout << i << " is even "; // 輸出範圍 2~M 內所有數是否為質數，及其質因數
        else    cout << i << " is odd  ";
        for(int j = 0; j < pFactors[i].size(); j++){
            cout << pFactors[i][j] << ' ';
        }
        cout << endl;
    }
    return;
}

signed main(void){
    tori_az
    cin >> m;
    PrimeFactors(m);
    return 0;
}