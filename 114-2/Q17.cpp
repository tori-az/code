#include<iostream>

class Person{
protected:
    std::string name;
public:
    void NicetomeetU(){
        std::cin >> name;
        std::cout << "Name: " << name << std::endl;
    }
};

class Poor: public Person{
private:
    int salary;
public:
    void GivemeMoney(){
        NicetomeetU();
        std::cin >> salary;
        std::cout << "Salary: " << salary;
    }
};

int main(){
    Poor me;
    me.GivemeMoney();

    return 0;
}