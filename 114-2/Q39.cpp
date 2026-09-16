#include<iostream>
#include<string>
using namespace std;

class StudentRecord{
private:
    string name;
    int score;
public:
    StudentRecord(string n, int s) : name(n), score(s) {}
    bool operator==(const StudentRecord& other) const {
        return name == other.name && score == other.score;
    }
};

template <typename T>
bool isSame(const T& a, const T& b){
    return a == b;
}

int main(){
    string s1, s2;
    int n1, n2;
    cin >> s1 >> n1 >> s2 >> n2;
    StudentRecord a(s1, n1);
    StudentRecord b(s2, n2);

    cout << (isSame(a, b) ? "Equal" : "Not Equal");
    return 0;
}