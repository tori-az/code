#include<iostream>

class BankAccount{
private:
    int balance, n;

public:
    void Input(){
        std::cin >> balance >> n;
    }

    void Method(){
        std::string s;
        int money;
        while(n--){
            std::cin >> s >> money;
            if(s == "deposit")  balance += money;
            else if(s == "withdraw")    balance -= money;
        }
    }

    void Output(){
        std::cout << "Balance: " << balance;
    }
};

int main(){
    BankAccount yoooooo;
    yoooooo.Input();
    yoooooo.Method();
    yoooooo.Output();
    
    return 0;
}