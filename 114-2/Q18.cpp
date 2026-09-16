#include<iostream>

class Car{
protected:
    std::string brand;
public:
    void input(){
        std::cin >> brand;
    }
    void output(){
        std::cout << "Brand: " << brand << std::endl;
    }
};

class Seats: public Car{
private:
    int seat;
public:
    void inputS(){
        input();
        std::cin >> seat;
    }

    void outputS(){
        output();
        std::cout << "Seats: " << seat;
    }
};

int main(){
    Seats s;
    s.inputS();
    s.outputS();

    return 0;
}