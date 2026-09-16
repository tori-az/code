#include<iostream>

class Student{
public:
    std::string name, id;
    int age;
};

int main(){
    Student s;
    std::cin >> s.name >> s.id >> s.age;
    std::cout << "Name: " << s.name << std::endl << "ID: " << s.id << std::endl << "Age: " << s.age;

    return 0;
}


/*
#include<iostream>
using namespace std;

int main(){
    string name, id;
    int age;
    cin >> name >> id >> age;
    cout << "Name: " << name << endl << "ID: " << id << endl << "Age: " << age;
    return 0;
}
*/