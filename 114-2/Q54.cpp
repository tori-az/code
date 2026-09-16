#include<iostream>
#include<string>
using namespace std;

int main(){
    int id;
    char* name;
    string department;

    if(cin >> id){
        cin.ignore();
        getline(cin, name);
        getline(cin, department);

        cout << "ID: " << id << "\n";
        cout << "Name: " << name << "\n";
        cout << "Department: " << department << "\n";
    }

    return 0;
}