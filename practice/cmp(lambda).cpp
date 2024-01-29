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

struct Pt { int x; int y; };
int n;

signed main(void) {
    tori_az
    cin >> n;
    vector<Pt> Points(n);
    for (int i = 0; i < n; i++) {
        cin >> Points[i].x >> Points[i].y;
    }
    sort(Points.begin(), Points.end(), [](Pt a, Pt b){
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    });
    for (auto i : Points) {
        cout << i.x << ',' << i.y << ' ';
    }

    return 0;
}
