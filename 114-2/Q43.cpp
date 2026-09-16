#include<iostream>
#include<string>
using namespace std;

class StatusToken{
private:
    string msg;
public:
    StatusToken(string m) : msg(m) {}
    string ReturnMsg() const { return msg; }
};

void Check(int c){
    if(c == 0)  cout << "OK";
    else{
        string msg;
        switch(c){
            case 1: msg = "ABSENT"; break;
            case 2: msg = "LATE"; break;
            case 3: msg = "CHEATING"; break;
            default: msg = "UNKNOWN"; break;
        }
        throw StatusToken(msg);
    }
}

int main(){
    int c;
    cin >> c;
    try{
        Check(c);
    }
    catch(const StatusToken& s){
        cout << s.ReturnMsg();
    }

    return 0;
}