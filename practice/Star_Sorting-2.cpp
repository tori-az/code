// https://codeforces.com/group/S6XjkGb6qB/contest/403070/problem/E
#include <bits/stdc++.h>
using namespace std;

// declare
int n;

struct Star {
    int x, y;
};

bool cmp(Star &a, Star &b) {
    if (a.x != b.x) 
        return a.x < b.x;
    else 
        return a.y > b.y;
}

signed main(void) {
    // fast IO
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    // input
    cin >> n;
    vector<Star> stars(n);
    for (int i = 0; i < n; i++) {
        cin >> stars[i].x >> stars[i].y;
    }
    
    // output
    sort(stars.begin(), stars.end(), cmp);
    for (int i = 0; i < n; i++) {
        cout << stars[i].x << " " << stars[i].y << "\n";
    }
    
    return 0;
}