#include<iostream>
#include<string>
#include<vector>
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
    double score;
public:
    Student(string n, double s) : Person(n), score(s) {}
    
    double Score() const { return score; }
};

class Teacher : public Person{
private:
    double year;
public:
    Teacher(string n, double y) : Person(n), year(y) {}

    double Year() const { return year; }
};

int main(){
    int n;
    cin >> n;
    
    vector<Person*> v;
    while(n--){
        char type;
        string name;
        double num;
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

    int ss = 0, tt = 0;
    for(Person* p : v){
        if(Student* s = dynamic_cast<Student*>(p)){
            ss++;
            int score = static_cast<int>(s->Score());
            cout << "Student " << s->Name() << " score " << score << endl;
            continue;
        }
        if(Teacher* t = dynamic_cast<Teacher*>(p)){
            tt++;
            int salary = static_cast<int>(t->Year());
            cout << "Teacher " << t->Name() << " salary " << salary << endl;
        }
    }
    cout << "Students: " << ss << endl << "Teachers: " << tt << endl;

    for(auto i : v) delete i;

    return 0;

}