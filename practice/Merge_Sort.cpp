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

void mergeSort(int *arr, int len){
    if(len <= 1)    return;
    // divide, conquer
    int leftLen = len/2, rightLen = len-leftLen;
    int *leftArr = arr, *rightArr = arr+leftLen;
    mergeSort(leftArr, leftLen);
    mergeSort(rightArr, rightLen); // 要將兩已排序好的陣列合併成一個陣列
    // combine
    static int tmp[MAX]; // static 會讓 tmp 的值留存到程式全部結束
    int tmpLen = 0, ll = 0, rr = 0; // 利用兩個指針從兩陣列的第一項開始相比較，比較後的元素放入陣列同時將指針向後移
    while(ll < leftLen && rr < rightLen){
        if(leftArr[ll] < rightArr[rr])    tmp[tmpLen++] = leftArr[ll++];
        else    tmp[tmpLen++] = rightArr[rr++];
    }
    while(ll < leftLen) tmp[tmpLen++] = leftArr[ll++];
    while(rr < rightLen)    tmp[tmpLen++] = rightArr[rr++];
    for(int i = 0; i < tmpLen; i++) arr[i] = tmp[i];
}

signed main(void){
    tori_az
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)  cin >> arr[i];
    mergeSort(arr, n);
    for(auto i : arr){
        cout << i << ' ';
    }
    return 0;
}

// merge sort 會排列出兩個遞增數列，可利用單調性算出有幾對逆序數對