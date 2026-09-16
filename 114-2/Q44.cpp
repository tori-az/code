#include<iostream>
#include<stdexcept>
using namespace std;

void Check(int s){
    if(s >= 0 && s <= 100)  cout << "accepted";
    else    throw invalid_argument("invalid score");
}

int main(){
    int s;
    cin >> s;
    try{
        Check(s);
    }
    catch(const invalid_argument& e){
        cout << e.what();
    }

    return 0;
}