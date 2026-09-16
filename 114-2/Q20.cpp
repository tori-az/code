#include<iostream>

class Wakamoto{
protected:
    std::string name;
public:
    void input(){
        std::cin >> name;
    }
    void output(){
        std::cout << "Name: " << name << std::endl;
    }
};

class Arigato: public Wakamoto{
private:
    int w, h;
public:
    void inputA(){
        input();
        std::cin >> w >> h;
    }

    void outputA(){
        output();
        std::cout << "Area: " << w * h;
    }
};

int main(){
    Arigato a;
    a.inputA();
    a.outputA();

    return 0;
}