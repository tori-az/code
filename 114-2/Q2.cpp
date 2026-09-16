#include<iostream>

class Rectangle{
private:
    int w, h, area;
public:
    void Input(){
        std::cin >> w >> h;
    }
    void Area(){
        area = w * h;
    }
    void Output(){
        std::cout << "Area: " << area;
    }
};

int main(){
    Rectangle r;
    r.Input();
    r.Area();
    r.Output();

    return 0;
}

/*
#include<iostream>
using namespace std;

int main(){
    int w, h;
    cin >> w >> h;
    cout << "Area: " << w * h;
}
*/