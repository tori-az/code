#include<iostream>
#include<stdexcept>
using namespace std;

int main(){
    int t;
    cin >> t;
    try{
        if(t >= 0 && t <= 35)   cout << "normal";
        else    throw string("temperature alert");
    }
    catch(const string& s){
        cout << s;
    }

    return 0;
}