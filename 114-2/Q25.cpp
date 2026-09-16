#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

class Point2D{
private:
    int x, y;

public:
    Point2D(int a, int b) : x(a), y(b) {}
    
    int X() const {return x;}
    int Y() const {return y;}
};

class Shape{
public:
    virtual double area() const = 0;
};

class Triangle : public Shape{
private:
    Point2D p1, p2, p3;
public:
    Triangle(const Point2D& a, const Point2D& b, const Point2D& c) : p1(a), p2(b), p3(c) {}

    double area() const override{
        // 三個點座標
        int x1 = p1.X(), y1 = p1.Y();
        int x2 = p2.X(), y2 = p2.Y();
        int x3 = p3.X(), y3 = p3.Y();

        // |x1(y2-y3)+x2(y3-y1)+x3(y1-y2)| / 2
        return abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2))/2.00;
    }
};

int main(){
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    Point2D p1(a, b);
    Point2D p2(c, d);
    Point2D p3(e, f);

    Triangle t(p1, p2, p3);

    cout << fixed << setprecision(2) << t.area();

    return 0;
}