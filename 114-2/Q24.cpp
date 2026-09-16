#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

class Point2D{
private:
    int x, y;

public:
    Point2D(int a, int b) : x(a), y(b) {}
    
    double distance(const Point2D& p2) const{
        return sqrt((x - p2.x)*(x - p2.x) + (y - p2.y)*(y - p2.y));
    }

    int X() const {return x;}
    int Y() const {return y;}
};

class Shape{
public:
    virtual bool valid() const = 0;
    virtual void perimeter() const = 0;
};

class Triangle : public Shape{
private:
    Point2D p1, p2, p3;
public:
    Triangle(const Point2D& a, const Point2D& b, const Point2D& c) : p1(a), p2(b), p3(c) {}

    bool valid() const override{
        double s1 = p1.distance(p2);
        double s2 = p1.distance(p3);
        double s3 = p2.distance(p3);

        if(s1 + s2 > s2 && s2 + s3 > s1 && s1 + s3 > s2)    return 1;
        else    return 0;
    }

    void perimeter() const override{
        if(!valid()){
            cout << "NO\n0.00";
            return;
        }

        double s1 = p1.distance(p2);
        double s2 = p1.distance(p3);
        double s3 = p2.distance(p3);

        cout << "YES" << endl << fixed << setprecision(2) << s1 + s2 + s3;
        return;
    }
};

int main(){
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    Point2D p1(a, b);
    Point2D p2(c, d);
    Point2D p3(e, f);

    Triangle t(p1, p2, p3);

    t.perimeter();

    return 0;
}