#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b;
    cin >> n >> a >> b;
    int v[n+1];
    double ans[n+1];
    v[0] = 0;
    ans[0] = 0.0;
    for(int i = 1; i <= n; ++i){
        cin >> v[i];
        v[i] = v[i-1] + v[i];
        ans[i] = (v[i] / (2.0 * a + i * b)); 
    }

    int ind = 0;
    double max = -1.0;
    for(int i = 1; i <= n; ++i){
        if(ans[i] > max){
            max = ans[i];
            ind = i;
        }
    }
    cout << 1 << ' ' << ind;

    return 0;
}
