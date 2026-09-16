#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main(){
    string line;
    getline(cin, line);
    istringstream iss(line);

    int num;
    int count = 0;
    long long sum = 0;

    while(iss >> num){
        count++;
        sum += num;
    }

    cout << "Count: " << count << endl;
    cout << "Sum: " << sum << endl;

    return 0;
}