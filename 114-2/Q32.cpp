#include <iostream>
#include <iomanip>
using namespace std;

template <typename T>
void mySwap(T& a, T& b) {
    T temp = a; 
    a = b;      
    b = temp;   
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char typeCode;
    
    if (cin >> typeCode) {
        if (typeCode == 'I') {
            int a, b;
            cin >> a >> b;
            mySwap(a, b); 
            cout << a << " " << b << "\n";
            
        } else if (typeCode == 'D') {
            double a, b;
            cin >> a >> b;
            mySwap(a, b); 
            cout << fixed << setprecision(2) << a << " " << b << "\n";
            
        } else if (typeCode == 'C') {
            char a, b;
            cin >> a >> b;
            mySwap(a, b);
            cout << a << " " << b << "\n";
        }
    }

    return 0;
}