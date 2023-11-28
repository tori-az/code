// http://judge.chwa.com.tw/ShowProblem?problemid=b001
// 一維陣列
#include<bits/stdc++.h>
using namespace std;
int arr[15], n;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = n-1; i >= 0; i--){
        cout << arr[i] << ' ';
    }
    return 0;
}