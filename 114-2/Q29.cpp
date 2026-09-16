#include<iostream>
#include<string>
#include<map>
using namespace std;

class Product{
private:
    string name;
    int price;
    int stock;

public:
    Product() : name(""), price(0), stock(0) {} 
    Product(const string& n, int p, int s) : name(n), price(p), stock(s) {}

    string Name() const { return name; }
    int Price() const { return price; }
    int Stock() const { return stock; }

    void Buy() { --stock; }
};

class Customer{
private:
    string customerName;
    int money;

public:
    Customer() : customerName(""), money(0) {}
    Customer(const string& n, int a) : customerName(n), money(a) {}

    string Name() const { return customerName; }
    int Money() const { return money; }

    void Buy(int p) { money -= p; }
    void Insert(int a) { money += a; }
    void Refund(){ money = 0; }
};

class Vending_Machine{
private:
    map<string, Product> products;
    map<string, Customer> customers;

public:
    Vending_Machine() {}

    void addItem(const string& n, int p, int s){
        // 怕有一樣的，直接更新或新增
        products[n] = Product(n, p, s);
    }

    void Insert(const string& n, int a){
        if(customers.find(n) == customers.end()){
            customers[n] = Customer(n, a);
        }else{
            customers[n].Insert(a);
        }
        cout << n << " balance " << customers[n].Money() << "\n";
    }

    void Buy(const string& c, const string& i){
        // 商品不存在或庫存為 0 
        if(products.find(i) == products.end() || products[i].Stock() == 0){
            cout << i << " unavailable\n";
            return;
        }
        // 餘額不足
        if(customers[c].Money() < products[i].Price()){
            cout << c << " insufficient funds\n";
            return;
        }
        
        // 成功購買
        customers[c].Buy(products[i].Price());
        products[i].Buy();
        cout << c << " bought " << i << "\n";
    }

    void Refund(const string& n){
        // 沒投幣印出 0 元
        cout << n << " refund " << customers[n].Money() << "\n";
        customers[n].Refund();
    }

    void Status(){
        int item = 0; 
        for(auto const& pair : products)  // map 是一堆 pair 組成的
            if(pair.second.Stock() > 0) ++item; // 有再記
        
        cout << "Items with stock: " << item << "\n";
    }
};

int main(){
    int P, Q;
    while(cin >> P >> Q) {
        Vending_Machine v;

        while(P--){
            string n;
            int p, s;
            cin >> n >> p >> s;
            v.addItem(n, p, s);
        }

        while(Q--){
            string s;
            cin >> s;
            if(s == "STATUS")   
                v.Status();
            else if(s == "INSERT"){ 
                string n;
                int a;
                cin >> n >> a;      
                v.Insert(n, a);
            }
            else if(s == "BUY"){    
                string n, p;
                cin >> n >> p;
                v.Buy(n, p);
            }
            else if(s == "REFUND"){
                string n;
                cin >> n;
                v.Refund(n);
            }
        }
    }

    return 0;
}