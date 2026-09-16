#include<iostream>
using namespace std;

class Point2D{
private:
    int x, y;
public:
    Point2D(int a, int b) : x(a), y(b) {}

    void Output(){
        cout << "(" << x << ", " << y << ")" << endl;
        cout << (x*x + y*y);
    }
};

int main(){
    int a, b;
    cin >> a >> b;
    Point2D p(a, b);

    p.Output();

    return 0;
}