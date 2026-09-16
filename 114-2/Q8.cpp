#include<iostream>
#include<string>

class Greeter{
private:
    std::string name;
public:
    Greeter(std::string n){
        name = n;
        std::cout << "Construct " << name << std::endl;
    }
    void hello(){
        std::cout << "Hello, " << name << std::endl;
    }
    ~Greeter(){
        std::cout << "Destruct " << name;
    }
};

int main(){
    std::string n;
    std::cin >> n;
    Greeter gg(n);
    gg.hello();

    return 0;
}

/*
#include<iostream>

class Greeter{
private:
    std::string name;
public:
    Greeter(std::string n){
        name = n;
        std::cout << "Construct " << name << std::endl;
    }
    void hello(){
        std::cout << "Hello, " << name << std::endl;
    }
    ~Greeter(){
        std::cout << "Destruct " << name;
    }
};

int main(){
    std::string n;
    std::cin >> n;
    Greeter* ptr = new Greeter(n);
    ptr -> hello();
    delete ptr;
    ptr = nullptr;
    
    return 0;
}
*/