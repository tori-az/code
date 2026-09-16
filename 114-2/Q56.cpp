#include<iostream>
#include<sstream>
#include<string>
using namespace std;

int main(){
    string name;
    string course;
    int score;

    getline(cin, name);
    getline(cin, course);
    cin >> score;

    stringstream oss;
    oss << "[Report] " << name << " got " << score 
        << " points in " << course << ".";

    cout << oss.str();

    return 0;
}