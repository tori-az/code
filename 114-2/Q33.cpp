#include <iostream>
#include <iomanip>
using namespace std;

template <typename T>
T Larger(const T& a, const T& b) {
    return (a > b ? a : b);
}

int main() {
    char code;
    cin >> code;
    
    switch(code) {
        case 'I': { 
            int a, b;
            cin >> a >> b;
            cout << Larger(a, b) << "\n";
            break;
        }

        case 'D': {
            double a, b;
            cin >> a >> b;
            cout << fixed << setprecision(2) << Larger(a, b) << "\n";
            break;
        }

        case 'C': {
            char a, b;
            cin >> a >> b;
            cout << Larger(a, b) << "\n";
            break;
        }
    }

    return 0;
}