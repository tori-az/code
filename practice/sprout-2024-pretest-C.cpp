#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#define tori_az ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long 
#define endl '\n'
const int MAX = 2e5+5;
const int INF = 9e18;
const int MOD = 1e9+7;
const double EPS = 1e-9;
using namespace std;

signed main(void){
    tori_az
    string s;
    cin >> s;
    map<int, string> ans;
    reverse(s.begin(), s.end());
    int j = 0, ss = s.size();
    for(int i = 0; i < ss;){
        if(s[i] == 'n'){
            ans[j] += 'n';
            if(s[i+1] == 'n'){
                ++j;
                ++i;
            }
            if(s[i+1] == 'a' || s[i+1] == 'e' || s[i+1] == 'i' || 
               s[i+1] == 'o' || s[i+1] == 'u'){
                ans[j] += s[i+1];
                if((s[i+2] == 'p' || s[i+2] == 't' || 
                    s[i+2] == 'k' || s[i+2] == 's' || 
                    s[i+2] == 'm' || s[i+2] == 'n' || 
                    s[i+2] == 'l' || s[i+2] == 'j' || s[i+2] == 'w') && 
                 !((s[i+2] == 't' || s[i+2] == 'j') && s[i+1] == 'i') && 
                 !(s[i+2] == 'w' && (s[i+1] == 'u' || s[i+1] == 'o'))){
                    ans[j] += s[i+2];
                    i += 3;
                }else{
                    ++j;
                    ++i;
                }
            }
            else{
                ++j;
                i += 2;
            }
        }
        else if(s[i] == 'a' || s[i] == 'e' || 
                s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
            ans[j] += s[i];
            if(s[i+1] == 'm' && s[i+2] == 'n'){
                ans[j] += s[i+1];
                ++j;
                ++i;
            }
            if((s[i+1] == 'p' || s[i+1] == 't' || 
                s[i+1] == 'k' || s[i+1] == 's' || 
                s[i+1] == 'm' || s[i+1] == 'n' || 
                s[i+1] == 'l' || s[i+1] == 'j' || s[i+1] == 'w') &&
             !((s[i+1] == 't' || s[i+1] == 'j') && s[i] == 'i') && 
             !(s[i+1] == 'w' && (s[i] == 'u' || s[i] == 'o'))){
                ans[j] += s[i+1];
                i += 2;
            }else{
                ++j;
                ++i;
            }
        }
        else{
            ++j;
            ++i;
        }
    }
    vector<string> tt;
    for(const auto& i : ans){
        string ts = i.second;
        reverse(ts.begin(), ts.end());
        tt.push_back(ts);
    }
    string ls = "";
    for(const auto& i : tt){
        if(i.size() > ls.size() || (i.size() == ls.size() && i < ls)){
            ls = i;
        }
    }
    if(ls.size() >= 2)  cout << ls;
    else    cout << "-1";
    return 0;
}