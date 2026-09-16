#include<iostream>
#include<string>

class Obj{
private:
    std::string name;
public:
    Obj(std::string n){
        name = n;
        std::cout << "Construct " << name << std::endl;
    }
    ~Obj(){
        std::cout << "Destruct " << name << std::endl;
    }
};

int main(){
    std::string outer, inner;
    std::cin >> outer >> inner;
    Obj Out(outer);
    {
        Obj In(inner);
        std::cout << "Inside" << std::endl;    
    }
    std::cout << "Outside" << std::endl;

    return 0;
}