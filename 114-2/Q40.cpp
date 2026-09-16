#include<iostream>
#include<string>
#include<stdexcept>
using namespace std;

int main(){
    string s;
    cin >> s;
    try{
        int result;
        result = stoi(s);
        cout << result;
    }
    catch(const invalid_argument& e){
        cout << "invalid_argument";
    }
    catch(const out_of_range& e){
        cout << "out_of_range";
    }

    return 0;
}