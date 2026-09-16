#include<iostream>
#include<stdexcept>
using namespace std;

void Check(int b, int a){
    if(a < 0)   throw invalid_argument("invalid amount");
    if(a > b)   throw runtime_error("insufficient funds");
    cout << b - a;
}

int main(){
    int b, a;
    cin >> b >> a;
    try{
        Check(b, a);
    }
    catch(const exception& e){
        cout << e.what();
    }

    return 0;
}