#include<iostream>

class Lamp{
private:
    bool state = 0;
    int n;
public:
    void Input(){
        std::cin >> n;
    }
    void Toggle(){
        std::string s;
        while(n--){
            std::cin >> s;
            if(s == "toggle")   state = !state;
        }
    }
    void Output(){
        if(state)   std::cout << "ON";
        else    std::cout << "OFF";
    }
};

int main(){
    Lamp owo;
    owo.Input();
    owo.Toggle();
    owo.Output();

    return 0;
}