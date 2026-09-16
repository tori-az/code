#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class Ticket{
private:
    string name;
    double price;
public:
    Ticket(string n, double p) : name(n), price(p) {}

    double Price() const { return price; }
};

class StudentTicket : public Ticket{
private:
    double discount;
public:
    StudentTicket(string n, double p, double d) : Ticket(n, p), discount(d) {}

    double Discount() const { return discount; }
};

int main(){
    string name;
    double ticket;
    double discount;

    cin >> name >> ticket >> discount;

    StudentTicket st(name, ticket, discount);
    Ticket* ptr = &st;
    StudentTicket* studentPtr = static_cast<StudentTicket*>(ptr);
    
    double finalPrice = (studentPtr->Price() * (100 - studentPtr->Discount()))/100;

    cout << "Name: " << name << endl 
        << "Original price: " << fixed << setprecision(2) << ticket << endl 
        << "Discounted price: " << fixed << setprecision(2) << finalPrice;

    return 0;
}

// static_cast 表示編譯期可檢查的明確轉型，常用於數值轉型或已知安全的類別階層轉型。