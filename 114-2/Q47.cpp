#include<iostream>
#include<stdexcept>
using namespace std;

class BookLimitExceededException : public exception{
public:
    const char* what() const noexcept override{
        return "Book borrowing limit exceeded";
    }
};

void Check(int c, int l, int r){
    if(c + r <= l)  cout << c + r;
    else    throw BookLimitExceededException();
}

int main(){
    int c, l, r;
    cin >> c >> l >> r;
    try{
        Check(c, l, r);
    }
    catch(const exception& e){
        cout << e.what();
    }

    return 0;
}