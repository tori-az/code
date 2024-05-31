#include <bits/stdc++.h>
#define int long long //TLE or MLE remove
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;

int n, m;

struct Cat{
    int rk, age;
    string name;
    bool operator < (Cat b){
        if(rk != b.rk)    return rk < b.rk;
        else if(age != b.age){
            if(rk == 5)    return age < b.age;
            else    return age > b.age;
        }
        else    return name < b.name;
    }
}arr [10005];

string name, work;
int age;
string position = " enkwamdl";

signed main(void){
    fastio
    
    while(cin >> n >> m){
        for(int i = 0; i < n; i++){
            cin >> name >> work >> age;
            for(int j = 1; j <= 8; j++){
                if(work[0] == position[j]){
                    arr[i] = {j, age, name};
                }
            }
        }
        sort(arr, arr+n);
        if(n < m)    m = n;
        for(int i = 0; i < m; i++){
            cout << arr[i].name << endl;
        }
    }
    return 0;
}