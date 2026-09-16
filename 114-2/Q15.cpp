#include<iostream>

class Wallet{
private:
    int a, b;
public:
    void input(){
        std::cin >> a >> b;
    }

    void update(int &x, int &y){
        if(y > x)   x = y;
    }

    void output(){
        update(a, b);
        std::cout << a << std::endl;
    }
};

int main(){
    Wallet w;
    w.input();
    w.output();

    return 0;
}