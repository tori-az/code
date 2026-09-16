#include <iostream>
#include <string>
#include <map>
#include <cmath>
using namespace std;

class Location {
private:
    int x, y;

public:
    Location() : x(0), y(0) {}
    Location(int x, int y) : x(x), y(y) {}

    int X() const { return x; }
    int Y() const { return y; }

    // operator+ 讓兩個座標可以直接相加
    Location operator+(const Location& other) const {
        return Location(x + other.x, y + other.y);
    }

    // operator== 讓兩個座標可以直接比較是否相同
    bool operator==(const Location& other) const {
        return x == other.x && y == other.y;
    }
};

class Package {
private:
    string id;
    int weight;
    Location dest;
    int status; // 0未分配, 1已分配, 2已送達

public:
    Package() : id(""), weight(0), status(0) {} // 給 map
    Package(string i, int w, int dx, int dy) : id(i), weight(w), dest(dx, dy), status(0) {}

    string Id() const { return id; }
    Location Dest() const { return dest; }
    int Status() const { return status; }

    void Assign() { status = 1; }
    void Deliver() { status = 2; }

    // operator< 讓包裹可以直接比重量
    bool operator<(const Package& other) const {
        return weight < other.weight;
    }
};

class Transport {
public:
    virtual ~Transport() {} // 虛擬解構子 解構的時候會先去找子類別的解構子
    
    virtual int Cost(int dx, int dy) const = 0; 
    virtual string GetType() const = 0;
    virtual Transport* Clone() const = 0; // 用父類別指標 Transport* 去裝子類別物件再加上 map 要複製，不處理的話會拿到一樣的指標但裝的不是一樣的東西
};

class BikeTransport : public Transport {
public:
    int Cost(int dx, int dy) const override {
        return abs(dx) + abs(dy);
    }
    string GetType() const override { return "BIKE"; }
    Transport* Clone() const override { return new BikeTransport(*this); }  // 弄出一個裝一樣東西的新的指標
};

class RobotTransport : public Transport {
public:
    int Cost(int dx, int dy) const override {
        return 2 * (abs(dx) + abs(dy));
    }
    string GetType() const override { return "ROBOT"; }
    Transport* Clone() const override { return new RobotTransport(*this); }
};

class Person {
protected: // 繼承的子類別能直接使用 name
    string name;
public:
    Person() : name("") {}
    Person(string n) : name(n) {}
    virtual ~Person() {} 

    string Name() const { return name; }
};

class Courier : public Person {
private:
    Location currentLoc;
    Transport* transport; // 用父類別指標操控不同的子類別物件(多型)
    string packageId;

public:
    Courier() : Person(), transport(nullptr), packageId("") {}
    
    Courier(string n, string type, int x, int y) : Person(n), currentLoc(x, y), packageId("") {
        // 據字串決定要生成腳踏車還是機器人
        if (type == "BIKE") transport = new BikeTransport();
        else transport = new RobotTransport();
    }

    // 不 delete 的話 heap 會炸
    ~Courier() { 
        delete transport; 
    }
    // Courier c2 = c1 拷貝建構子
    Courier(const Courier& other) : Person(other.name), currentLoc(other.currentLoc), packageId(other.packageId) {
        transport = other.transport ? other.transport->Clone() : nullptr;
    }
    // c1 = c2 賦值運算子
    Courier& operator=(const Courier& other) {
        if (this != &other) {
            name = other.name;
            currentLoc = other.currentLoc;
            packageId = other.packageId;
            delete transport; // 刪除舊運輸工具
            transport = other.transport ? other.transport->Clone() : nullptr; // 複製新運輸工具
        }
        return *this;
    }

    bool IsCarrying() const { return packageId != ""; }
    string PackageId() const { return packageId; }
    Location Loc() const { return currentLoc; }
    
    string TransportType() const { return transport ? transport->GetType() : ""; }
    
    int MoveCost(int dx, int dy) const { return transport ? transport->Cost(dx, dy) : 0; }

    void Assign(string pId) { packageId = pId; }
    void ClearPackage() { packageId = ""; }
    
    // operator+
    void Move(int dx, int dy) { 
        currentLoc = currentLoc + Location(dx, dy); 
    }
};

class System {
private:
    map<string, Courier> couriers;
    map<string, Package> packages;

public:
    void AddCourier(const string& n, const string& t, int x, int y) {
        couriers[n] = Courier(n, t, x, y);
    }
    void AddPackage(const string& id, int w, int dx, int dy) {
        packages[id] = Package(id, w, dx, dy);
    }

    void AssignOp(const string& cName, const string& pId) {
        Courier& c = couriers[cName];
        Package& p = packages[pId];

        if (c.IsCarrying()) {
            cout << cName << " is already carrying a package\n";
            return;
        }
        if (p.Status() == 1) {
            cout << "Package " << pId << " is already assigned\n";
            return;
        }
        if (p.Status() == 2) {
            cout << "Package " << pId << " has already been delivered\n";
            return;
        }

        c.Assign(pId);
        p.Assign();
        cout << "Assigned package " << pId << " to " << cName << "\n";
    }

    void MoveOp(const string& cName, int dx, int dy) {
        Courier& c = couriers[cName];
        c.Move(dx, dy);
        cout << cName << " moved to (" << c.Loc().X() << ", " << c.Loc().Y() << ")\n";
    }

    void CostOp(const string& cName, int dx, int dy) {
        Courier& c = couriers[cName];
        cout << "Cost for " << cName << ": " << c.MoveCost(dx, dy) << "\n";
    }

    void DeliverOp(const string& cName) {
        Courier& c = couriers[cName];
        if (!c.IsCarrying()) {
            cout << cName << " has no package\n";
            return;
        }
        
        string pId = c.PackageId();
        Package& p = packages[pId];

        // operator==
        if (c.Loc() == p.Dest()) {
            p.Deliver();
            c.ClearPackage();
            cout << cName << " delivered package " << pId << "\n";
        } else {
            cout << cName << " failed to deliver package " << pId << "\n";
        }
    }

    void StatusOp(const string& cName) {
        Courier& c = couriers[cName];
        cout << cName << " at (" << c.Loc().X() << ", " << c.Loc().Y() 
             << "), transport: " << c.TransportType() << ", carrying: " 
             << (c.IsCarrying() ? c.PackageId() : "none") << "\n";
    }

    void LighterOp(const string& p1, const string& p2) {
        Package& pkg1 = packages[p1];
        Package& pkg2 = packages[p2];

        // operator<
        if (pkg1 < pkg2) {
            cout << "Lighter package: " << p1 << "\n";
        } else if (pkg2 < pkg1) {
            cout << "Lighter package: " << p2 << "\n";
        } else {
            cout << "Equal weight\n";
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int C, P;
    while (cin >> C >> P) {
        System center;

        while (C--) {
            string n, t;
            int x, y;
            cin >> n >> t >> x >> y;
            center.AddCourier(n, t, x, y);
        }

        while (P--) {
            string id;
            int w, dx, dy;
            cin >> id >> w >> dx >> dy;
            center.AddPackage(id, w, dx, dy);
        }

        int Q;
        cin >> Q;
        while (Q--) {
            string op;
            cin >> op;
            if (op == "ASSIGN") {
                string c, p;
                cin >> c >> p;
                center.AssignOp(c, p);
            } 
            else if (op == "MOVE") {
                string c;
                int dx, dy;
                cin >> c >> dx >> dy;
                center.MoveOp(c, dx, dy);
            } 
            else if (op == "COST") {
                string c;
                int dx, dy;
                cin >> c >> dx >> dy;
                center.CostOp(c, dx, dy);
            } 
            else if (op == "DELIVER") {
                string c;
                cin >> c;
                center.DeliverOp(c);
            } 
            else if (op == "STATUS") {
                string c;
                cin >> c;
                center.StatusOp(c);
            } 
            else if (op == "LIGHTER") {
                string p1, p2;
                cin >> p1 >> p2;
                center.LighterOp(p1, p2);
            }
        }
    }
    return 0;
}