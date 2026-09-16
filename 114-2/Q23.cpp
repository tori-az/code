#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

class Point2D{
private:
    int x, y;

public:
    Point2D(int a, int b) : x(a), y(b) {}
    
    void Output(const Point2D& p2){
        cout << fixed << setprecision(2) << sqrt((x - p2.x)*(x - p2.x) + (y - p2.y)*(y - p2.y)) << endl;
    }
};

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    Point2D p1(a, b);
    Point2D p2(c, d);

    p1.Output(p2);

    return 0;
}