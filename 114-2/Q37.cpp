#include<iostream>
#include<cmath>
using namespace std;

int gcd(int a, int b){ // 最大公因數
    a = abs(a);
    b = abs(b);
    return b == 0 ? a : gcd(b, a%b);
}

class Fraction{ // 分數
private:
    int son;
    int mom;
    
public:
    Fraction(int s = 0, int m = 1) : son(s), mom(m) {
        if(mom < 0){ // 方便比大小
            mom = -mom;
            son = -son;
        }
        int g = gcd(mom, son); // 約分
        mom /= g;
        son /= g;
    }

    bool operator<(const Fraction& other) const {
        // a/b < c/d  =>  a*d < b*c
        long long left = (long long)son * other.mom;
        long long right = (long long)mom * other.son;
        return left < right;
    }

    friend ostream& operator<<(ostream& os, const Fraction& f){
        os << f.son << '/' << f.mom;
        return os;
    }

};

template <typename T>
T Larger(const T& a, const T& b){
    return (b < a) ? a : b;
}

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    Fraction f1(a, b);
    Fraction f2(c, d);

    cout << Larger(f1, f2);

    return 0;
}