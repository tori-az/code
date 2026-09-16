#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(){
    string name;
    string temp;
    int mid, fin, bonus;
    
    getline(cin, name, ',');
    
    getline(cin, temp, ',');
    mid = stoi(temp);
    
    getline(cin, temp, ',');
    fin = stoi(temp);
    
    getline(cin, temp); 
    bonus = stoi(temp);
    
    int total = mid + fin + bonus;
    double aver = total / 3.0; 
    
    cout << "Name: " << name << endl 
         << "Total: " << total << endl
         << "Average: " << fixed << setprecision(2) << aver;
         
    return 0;
}