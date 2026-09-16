#include<iostream>

class Person{
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

class Student: public Person{
private:
    std::string id;
public:
    void inputS(){
        input();
        std::cin >> id;
    }
    void outputS(){
        output();
        std::cout << "ID: " << id;
    }
};

int main(){
    Student s;
    s.inputS();
    s.outputS();

    return 0;
}