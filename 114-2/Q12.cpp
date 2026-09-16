#include<iostream>

class Temperature{
private:
    int a, b;
public:
    void input(){
        std::cin >> a >> b;
    }
    void update(int &x, int &k){
        x += k;
    }
    void output(){
        update(a, b);
        std::cout << a;
    }
};

int main(){
    Temperature t;
    t.input();
    t.output();

    return 0;
}