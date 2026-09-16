#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int q1, q2, q3;
    double lab;
    cin >> q1 >> q2 >> q3 >> lab;
    double sum, aver;
    sum = q1 + q2 + q3 + lab;
    aver = sum / 4.0;
    cout << "Total: " << fixed << setprecision(2) << sum << endl
        << "Average: " << fixed << setprecision(2) << aver;

    return 0;
}