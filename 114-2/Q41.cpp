#include<iostream>
#include<vector>
#include<stdexcept>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i)  cin >> v[i];
    int k;
    cin >> k;
    try{
        cout << v.at(k);
    }
    catch(out_of_range){
        cout << "out_of_range";
    }

    return 0;
}
