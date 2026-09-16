#include<iostream>
#include<iomanip>
using namespace std;

template <typename T>
T Sum(const T arr[], int n){
    T sum = T();
    for(int i = 0; i < n; ++i){
        sum += arr[i];
    }
    return sum;
}

int main(){
    char c;
    int n;
    cin >> c >> n;
    if(c == 'I'){
        int arr[n];
        for(int i = 0; i < n; ++i)  cin >> arr[i];
        cout << Sum(arr, n);
    }
    if(c == 'D'){
        double arr[n];
        for(int i = 0; i < n; ++i)  cin >> arr[i];
        cout << fixed << setprecision(2) << Sum(arr, n);
    }

    return 0;
}