#include<bits/stdc++.h>
using namespace std;
string n;

int main(){
	cin >> n;
	string t = n;
	reverse(t.begin(), t.end());
	if(t == n){
		cout << "YES";
		return 0;
	}
	int ns = n.size();
	char pre;
	bool ok = 1;
	t = "";
	for(int i = 0; i < ns; ++i){
		if(n[i] != n[ns-1-i] && ok == 1){
			pre = n[i];
			ok = 0;
			continue;
		}
		t += n[i];
	}
	string r = t;
	reverse(r.begin(), r.end());
	if(r == t){
		cout << "YES";
		return 0;
	}
	r = "";
	int ts = t.size();
	ok = 1;
	int wow;
	for(int i = 0; i < ts; ++i){
		if(t[i] != t[ts-1-i] && ok == 1){
			r += pre;
			wow = ts-1-i;
			ok = 0;
		}
		if(!ok && i == wow){
			continue;
		}
		r += t[i];
	}
	string w = r;
	reverse(w.begin(), w.end());
	if(w == r){
		cout << "YES";
		return 0;
	}
	cout << "NO";
	return 0;
} 
