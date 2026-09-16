#include<iostream>
#include<string>
#include<map>
using namespace std;

class Student{
private:
    string studentName;
    int machineId; // 0 代表目前沒有在使用機器

public:
    Student() : studentName(""), machineId(0) {}
    Student(const string& n) : studentName(n), machineId(0) {}

    string Name() const { return studentName; }
    bool IsUsing() const { return machineId != 0; }
    int MachineId() const { return machineId; }

    void Start(int id) { machineId = id; }
    void Finish() { machineId = 0; }
};

class Machine{
private:
    int id;
    bool occupied;
    string userName;

public:
    Machine() : id(0), occupied(0), userName("") {} // 給 map 用
    Machine(int i) : id(i), occupied(0), userName("") {}

    int Id() const { return id; }
    bool IsOccupied() const { return occupied; }
    string User() const { return userName; }

    void Start(const string& n) { 
        occupied = 1; 
        userName = n; 
    }
    void Finish() { 
        occupied = 0; 
        userName = ""; 
    }
};

class LaundryRoom{
private:
    int busy;
    int idle;
    map<int, Machine> machines;
    map<string, Student> students;

public:
    LaundryRoom(int M) : busy(0), idle(M) {
        for(int i = 1; i <= M; ++i) machines[i] = Machine(i);   
    }

    void Start(const string& name, int id){
        // 學生第一次出現
        if(students.find(name) == students.end()){
            students[name] = Student(name);
        }
        // 機器編號不存在
        if(machines.find(id) == machines.end()){
            cout << name << " cannot start\n";
            return;
        }
        // 目前空閒且 && 學生尚未使用其他機器
        if(!machines[id].IsOccupied() && !students[name].IsUsing()){
            machines[id].Start(name);
            students[name].Start(id);
            ++busy;
            --idle;
            cout << name << " started machine " << id << "\n";
        }else{
            cout << name << " cannot start\n";
        }
    }

    void Finish(const string& name, int id){
        // 路人跑來結束洗衣
        if(students.find(name) == students.end()){
            cout << name << " cannot finish\n";
            return;
        }
        // 機器編號不存在
        if(machines.find(id) == machines.end()){
            cout << name << " cannot finish\n";
            return;
        }
        // 機器被佔用 && 機器裡面是這個人的衣服 && 學生紀錄是這台
        if(machines[id].IsOccupied() && machines[id].User() == name && students[name].MachineId() == id){
            machines[id].Finish();
            students[name].Finish();
            --busy;
            ++idle;
            cout << name << " finished machine " << id << "\n";
        }else{
            cout << name << " cannot finish\n";
        }
    }

    void Status() const {
        cout << "Busy: " << busy << ", Idle: " << idle << "\n";
    }
};

int main(){
    int M, Q;
    while(cin >> M >> Q){
        LaundryRoom room(M);

        while(Q--){
            string op;
            cin >> op;
            if(op == "STATUS"){
                room.Status();
            }
            else if(op == "START"){
                string n;
                int id;
                cin >> n >> id;
                room.Start(n, id);
            }
            else if(op == "FINISH"){
                string n;
                int id;
                cin >> n >> id;
                room.Finish(n, id);
            }
        }
    }

    return 0;
}