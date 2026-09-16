#include<iostream>
using namespace std;

class Component1D{
private:
    int value;
    
public:
    Component1D(int val){
        value = val;
    }

    int displacement(const Component1D& target){
        return target.value - value;
    }
};

int main(){
    int a, b;
    cin >> a >> b;
    Component1D A(a);
    Component1D B(b);

    cout << A.displacement(B) << endl << B.displacement(A);

    return 0;
}