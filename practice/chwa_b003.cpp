// http://judge.chwa.com.tw/ShowProblem?problemid=b003
// 一維陣列
#include<bits/stdc++.h>
using namespace std;
int n, arr[15], m;
int a, b;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >> m;
    for(int i = 0; i < n; i++){
        if(arr[i] > m)  a++;
        if(arr[i] < m)  b++;
    }
    cout << a << ' ' << b;
    return 0;
}