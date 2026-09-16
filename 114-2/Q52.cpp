#include<iostream>
#include<string>
using namespace std;

int main(){
    string name;
    int age;
    string major;

    cin >> name >> age >> major;
    cout << "Student " << name << " is " << age << " years old and majors in " << major << '.';
    return 0;
}