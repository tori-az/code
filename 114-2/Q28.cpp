#include <iostream>
#include <string>
#include <map>
using namespace std;

class Person{
private:
    string name;
    int currentFloor;
    bool inside;

public:
    Person() : name(""), currentFloor(1), inside(false) {} // 給 map 用
    Person(string n, int f) : name(n), currentFloor(f), inside(false) {}

    bool isInside() const { return inside; }
    int getFloor() const { return currentFloor; }
    
    void updateFloor(int f) { currentFloor = f; }
    void enter() { inside = true; }
    void exit() { inside = false; }
};

class Elevator{
private:
    int currentFloor;
    int capacity;
    int passengers;

public:
    // 預設停在 1 樓，乘客數為 0
    Elevator(int c) : currentFloor(1), capacity(c), passengers(0) {}

    int getFloor() const { return currentFloor; }
    bool isFull() const { return passengers >= capacity; }
    int getPassengers() const { return passengers; }

    void move(int f) { currentFloor = f; }
    void addPassenger() { ++passengers; }
    void removePassenger() { --passengers; }
};

class Building {
private:
    Elevator elevator;
    map<string, Person> people; 

public:
    Building(int c) : elevator(c) {}

    void moveOp(int f){
        elevator.move(f);
        cout << "Elevator moved to " << f << "\n";
    }

    void enterOp(const string& name, int floor){
        // 第一次出現建立資料
        if(people.find(name) == people.end()){
            people[name] = Person(name, floor);
        }

        Person& p = people[name];

        // 電梯在該樓層 && 人在該樓層 && 人不在電梯內 && 電梯沒滿
        if(elevator.getFloor() == floor && p.getFloor() == floor && !p.isInside() && !elevator.isFull()){
            p.enter();
            elevator.addPassenger();
            cout << name << " entered\n";
        }else{
            cout << name << " cannot enter\n";
        }
    }

    void exitOp(const string& name, int floor){
        // 人不在無法離開
        if(people.find(name) == people.end()){
            cout << name << " cannot exit\n";
            return;
        }

        Person& p = people[name]; 

        // 人在電梯內 && 電梯在該樓層
        if(p.isInside() && elevator.getFloor() == floor){
            p.exit();
            p.updateFloor(floor); // 離開電梯後，把所在樓層更新為這層樓
            elevator.removePassenger();
            cout << name << " exited\n";
        }else{
            cout << name << " cannot exit\n";
        }
    }

    void statusOp() const {
        cout << "Floor: " << elevator.getFloor() 
             << ", Passengers: " << elevator.getPassengers() << "\n";
    }
};

int main(){
    int C, Q;
    cin >> C >> Q;
    Building building(C);

    while(Q--){
        string op;
        cin >> op;
        if(op == "MOVE"){
            int f;
            cin >> f;
            building.moveOp(f);
        } 
        else if(op == "ENTER"){
            string name;
            int floor;
            cin >> name >> floor;
            building.enterOp(name, floor);
        } 
        else if(op == "EXIT"){
            string name;
            int floor;
            cin >> name >> floor;
            building.exitOp(name, floor);
        } 
        else if(op == "STATUS"){
            building.statusOp();
        }
    }
    return 0;
}