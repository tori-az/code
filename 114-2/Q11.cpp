#include<iostream>

class Pair{
private:
    int x, y;
public:
    void input(){
        std::cin >> x >> y;
    }

    void swap(int &a,int &b){
        int temp = a;
        a = b;
        b = temp;
    }

    void output(){
        swap(x, y);
        std::cout << x << ' ' << y;
    }
};

int main(){
    Pair owo;
    owo.input();
    owo.output();

    return 0;
}