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
int n;

void quickSort(int *arr, int len){
    if(len <= 1)    return;
    // divide
    int pivoIdx = rand()%len, pivot = arr[pivoIdx];
    swap(arr[len-1], arr[pivoIdx]); 
    int leftLen = 0;
    for(int i = 0; i < len; i++){
        if(arr[i] < pivot)  {
            swap(arr[i], arr[leftLen]); // 遍歷陣列，將小於基準元素的值移到左半部分
            leftLen++; // 這兩行可以直接寫成 swap(arr[i], arr[leftLen++]);
        }
    }
    swap(arr[leftLen], arr[len-1]); // 將基準元素移到正確的位置
    //for(int i = 0; i < len; i++)    cout << arr[i] << ' ';
    cout << endl;
    int rightLen = len-leftLen-1; // 計算右半部分的長度
    int *leftArr = arr, *rightArr = arr+leftLen+1;
    // conquer
    quickSort(leftArr, leftLen);
    quickSort(rightArr, rightLen);
}

signed main(void){
    tori_az
    cin >> n;
    int arr[n];
    for(int &i : arr)   cin >> i;
    quickSort(arr, n);
    for(int i : arr)    cout << i << ' ';
    return 0;
}