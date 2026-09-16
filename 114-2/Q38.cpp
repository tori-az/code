#include<iostream>
using namespace std;

class Point2D{
private:
    int x, y;

public:
    Point2D(int a, int b) : x(a), y(b) {}

    Point2D operator+(const Point2D& other) const {
        cout << "[" << *this << " + " << other << "]" << " -> ";
        return Point2D(x + other.x, y + other.y);
    }

    friend ostream& operator<<(ostream& os, const Point2D& p){
        os << '(' << p.x << ", " << p.y << ')';
        return os;
    }
};

template <typename T>
T addValues(const T& a, const T& b, const T& c){
    return a+b+c;
}

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    Point2D p1(a, b);
    Point2D p2(c, d);
    Point2D p3(5, 6);
    cout << addValues(p1, p2, p3);
    return 0;
}