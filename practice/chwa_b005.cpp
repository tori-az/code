// http://judge.chwa.com.tw/ShowProblem?problemid=b005
// 雖然是陣列題，但我用一維陣列跟 vector 都會 RE，所以改用 map
#include<bits/stdc++.h>
#define tori_az ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
using namespace std;
int n, tmp = -1, ind = -1;
unordered_map<int ,int> cnt;

signed main(void){
    tori_az
    cin >> n;
    for(int i = 1, x; i <= n; i++){
        cin >> x;
        cnt[x]++;
    }
    for(auto it = cnt.begin(); it != cnt.end(); it++){
        if(it -> second > tmp){  // = if((*it).second > tmp)
            tmp = it -> second;
            ind = it -> first;
        }
    }
    cout << ind << ' ' << tmp;
    return 0;
}
// 如果你不知道 map 是什麼，可以參考 https://emanlaicepsa.github.io/2020/12/09/0-21/
// 如果你沒有指標的概念，可以參考 https://www.itread01.com/study/cpp-pointers.html