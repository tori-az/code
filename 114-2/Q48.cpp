#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int a;
    double b;
    char c;
    cin >> a >> b >> c;

    cout << "From double to int: " << static_cast<int>(b) << endl;
    cout << "From int to double: " << fixed << setprecision(2) << static_cast<double>(a) << endl;
    cout << "ASCII of char: " << static_cast<int>(c) << endl;

    return 0;
}
