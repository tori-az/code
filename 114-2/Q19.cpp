#include<iostream>

class Pet{
protected:
    std::string name;
public:
    void SayMyName(){
        std::cin >> name;
        std::cout << "Name: " << name << std::endl;
    }
};

class Dog: public Pet{
private:
    int woof;
public:
    void GoodBoy(){
        SayMyName();
        std::cin >> woof;
        for(int i = 0; i < woof; ++i){
            std::cout << "Woof";
            if(i != woof - 1)   std::cout << " ";
        }
    }
};

int main(){
    Dog d;
    d.GoodBoy();

    return 0;
}