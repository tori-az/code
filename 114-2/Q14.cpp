#include<iostream>

class Box{
private:
    int a, b, k;
public:
    void input(){
        std::cin >> a >> b >> k;
    }

    void normalize(int &x, int &y, int r){
        x += r;
        y -= r;
    }

    void output(){
        normalize(a, b, k);
        std::cout << a << ' ' << b;
    }
};

int main(){
    Box owo;
    owo.input();
    owo.output();

    return 0;
}