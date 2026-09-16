#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

template <typename T>
class Box{
private:
    T a, b;
public:
    Box(const T& v, const T& u) : a(v), b(u){}
    T Larger(const T& a, const T& b) {
        return (a > b ? a : b);
    }
};

int main() {
    char code;
    cin >> code;
    
    switch(code) {
        case 'I': { 
            int a, b;
            cin >> a >> b;
            Box<int> box(a, b);
            cout << box.Larger(a, b) << "\n";
            break;
        }

        case 'D': {
            double a, b;
            cin >> a >> b;
            Box<double> box(a, b);
            cout << fixed << setprecision(2) << box.Larger(a, b) << "\n";
            break;
        }

        case 'C': {
            char a, b;
            cin >> a >> b;
            Box<char> box(a, b);
            cout << box.Larger(a, b) << "\n";
            break;
        }
    }

    return 0;
}