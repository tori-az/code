#include<iostream>

class Clock{
private:
    int hour, minute;
public:
    Clock(int h, int m){
        hour = h;
        minute = m;
    }
    void display(){
        std::cout << "Hour: " << hour << std::endl << "Minute: " << minute;
    }

};

int main(){
    int h, m;
    std::cin >> h >> m;
    Clock cc(h, m);
    cc.display();

    return 0;
}