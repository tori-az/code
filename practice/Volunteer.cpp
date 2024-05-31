// https://codeforces.com/group/S6XjkGb6qB/contest/422756/problem/C
#include<bits/stdc++.h>
using namespace std;

// declare
int n, m;
int x, y;

struct Book{
    string name;
    char category;
    int number;
};

signed main(void){
    // fast IO
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    // input
    cin >> n >> m;
    vector<Book> books(n);
    
    for(int i = 0; i < n; i++){
        cin >> books[i].name >> books[i].category >> books[i].number;
    }
    
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        swap(books[x-1], books[y-1]);
    }
    
    // output
    for(int i = 0; i < n; i++){
        cout << books[i].name << " " << books[i].category << " "  << books[i].number << '\n';
    }
    
    return 0;
}