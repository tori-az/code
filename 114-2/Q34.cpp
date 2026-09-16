#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

template <typename T>
class Box{
private:
    T value;
public:
    Box(const T& v) : value(v) {}
    T Value() const{
        return value;
    }
};

int main(){
    char c;
    cin >> c;

    switch(c){
        case 'I':{
            int v;
            cin >> v;
            Box<int> b(v);
            cout << b.Value();
            break;
        } 

        case 'D':{
            double v;
            cin >> v;
            Box<double> b(v);
            cout << fixed << setprecision(2) << b.Value();
            break;
        }

        case 'C':{
            char v;
            cin >> v;
            Box<char> b(v);
            cout << b.Value();
            break;
        }
        
        case 'S':{
            string v;
            cin >> v;
            Box<string> b(v);
            cout << b.Value();
            break;
        }
    }
}