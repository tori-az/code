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
    std::string a, b;
    std::cin >> a >> b;
    Obj* aa = new Obj(a);
    Obj* bb = new Obj(b);
    std::cout << "Working" << std::endl;
    delete bb;
    delete aa;

    return 0;
}