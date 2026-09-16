#include <iostream>
#include <string>
#include <map>
using namespace std;

class Obj{
private:
    int id;
    Obj* nxt;
public:
    Obj(int i) : id{i}, nxt{nullptr} {} // 建立變數/物件並賦予初始值用{}可以檢查報錯，例如放錯或呼叫「無參數的預設建構子」
    // 「宣告/生出」一個東西並給它資料 {}
    int Id() const { return id; }
    Obj* Nxt() const { return nxt; }
    
    void SetNxt(Obj* const target){ nxt = target; }
};

class ObjManager {
private:
    map<int, Obj*> objMap; 

public:
    void New(int id){
        if(objMap.find(id) == objMap.end()){
            objMap[id] = new Obj{id};
            cout << "Created object " << id << '\n';
        }else{
            cout << "Object " << id << " already exists\n"; // 已經存在
        }
    }

    void Setnext(int a, int b){
        if(objMap.find(a) != objMap.end() && objMap.find(b) != objMap.end()){
            objMap[a]->SetNxt(objMap[b]); 
            cout << "Object " << a << " now points to " << b << '\n';
        }else{
            cout << "Invalid operation\n"; // 目標物件不存在
        }
    }

    void Clearnext(int a){
        if(objMap.find(a) != objMap.end()){
            objMap[a]->SetNxt(nullptr);
            cout << "Object " << a << " now points to none\n";
        }else{
            cout << "Invalid operation\n"; // 目標物件不存在
        }
    }

    void Show(int id){
        if(objMap.find(id) != objMap.end()){
            Obj* target = objMap[id];
            
            if(target->Nxt() != nullptr){
                cout << "Object " << id << ": next = " << target->Nxt()->Id() << '\n';
            }else {
                cout << "Object " << id << ": next = none\n";
            }
        }else{
            cout << "Object " << id << " not found\n"; // 不存在的物件
        }
    }

    void Count(){
        cout << "Object count: " << objMap.size() << '\n';
    }

    ~ObjManager(){
        for(auto& [id, ptr] : objMap)   delete ptr;
        objMap.clear();
    }
};

int main(){
    int n;
    cin >> n;
    ObjManager OM;

    while(n--){
        string cmd;
        cin >> cmd;
        
        if(cmd == "NEW"){
            int a;
            cin >> a;
            OM.New(a);
        }
        else if(cmd == "SETNEXT"){
            int a, b;
            cin >> a >> b;
            OM.Setnext(a, b);
        }
        else if(cmd == "CLEARNEXT"){
            int a;
            cin >> a;
            OM.Clearnext(a);
        }
        else if(cmd == "SHOW"){
            int a;
            cin >> a;
            OM.Show(a);
        }
        else if(cmd == "COUNT"){
            OM.Count();
        }
    }
    return 0;
}

// 寫 new 和 delete 實在太容易出錯（忘記寫、提早 return 導致沒執行到），C++11 引入了智慧指標，完美體現了 RAII（資源獲取即初始化） 的精神：把資源包在物件裡，利用物件死亡必呼叫解構子的特性來自動 delete