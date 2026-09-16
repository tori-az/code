#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Person{
private:
    string name;
public:
    Person(string n) : name(n) {}

    string Name() const { return name; }

    virtual ~Person() = default; 
};

class Student : public Person{
private:
    int score;
public:
    Student(string n, int s) : Person(n), score(s) {}

    int Score() const { return score; }
};

class Teacher : public Person{
private:
    int year;
public:
    Teacher(string n, int y) : Person(n), year(y) {}

    int Year() const { return year; }
};

int main(){
    int n;
    cin >> n;
    
    vector<Person*> v;
    while(n--){
        char type;
        string name;
        int num;

        cin >> type >> name >> num;
        switch(type){
            case 'S':
                v.push_back(new Student(name, num));
                break;
            case 'T':
                v.push_back(new Teacher(name, num));
                break;
        }
    }

    int s = 0, t = 0;
    for(Person* p : v){
        if(Student* student = dynamic_cast<Student*>(p)){
            s++;
            cout << "Student " << student->Name() << " " << student->Score() << "\n";
            continue;
        }
        if(Teacher* teacher = dynamic_cast<Teacher*>(p)){
            t++;
            cout << "Teacher " << teacher->Name() << " " << teacher->Year() << "\n";
        }
    }
    
    cout << "Students: " << s << "\n" << "Teachers: " << t << "\n";

    for(auto p : v)   delete p;

    return 0;
}

//dynamic_cast 在多型階層中做執行期型別檢查，常用於需要確認物件真實子型別的安全 downcast。