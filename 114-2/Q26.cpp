#include<iostream>
#include<string>
#include<map>
using namespace std;

class Light{
private:
    bool ON;

public:
    Light() : ON(0) {}

    void turnOn() {ON = 1;}
    void turnOff() {ON = 0;}
    bool on() const {return ON;}
};

class Student{
private:
    string Name;
    bool Inside;

public:
    Student() : Name(""), Inside(0) {} // 給 map 用的
    Student(string n) : Name(n), Inside(0) {}

    void enter() {Inside = 1;}
    void leave() {Inside = 0;}
    bool inside() const {return Inside;}
    string name() const {return Name;}
};

class Classroom{
private:
    int cnt;
    map<string, Student> students;
    Light light;
    
public:
    Classroom() : cnt(0) {}

    void enter(const string& name){
        if(students.find(name) == students.end()){ // 要分開因為可能會重複進入
            students[name] = Student(name); // students[name]會生一個空的 Student 物件出來
        }

        if(!students[name].inside()){
            cnt++;
            students[name].enter();
            if(cnt == 1)    light.turnOn();
            cout << name << " entered" << endl;

        }else{
            cout << name << " already inside" << endl;
        }

        return;
    }

    void leave(const string& name){
        if(students.find(name) == students.end() || !students[name].inside()){
            cout << name << " not inside" << endl;
        }else{
            cnt--;
            if(cnt == 0)    light.turnOff();
            students[name].leave();
            cout << name << " left" << endl;
        }

        return;
    }

    void status(){
        cout << "Students: " << cnt << ", Light: " << (light.on() ? "ON" : "OFF") << endl;

        return;
    }
};

int main(){
    Classroom room;

    int q;
    cin >> q;
    while(q--){
        string op;
        cin >> op;
        if(op == "ENTER"){
            string name;
            cin >> name;
            room.enter(name);
        }
        else if(op == "LEAVE"){
            string name;
            cin >> name;
            room.leave(name);
        }
        else if(op == "STATUS"){
            room.status();
        }
    }

    return 0;
}