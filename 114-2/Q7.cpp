#include<iostream>

class Rectangle{
private:
    int height, width;
public:
    Rectangle(int h, int w){
        height = h;
        width = w;
    }
    void output(){
        std::cout << "Area: " << height * width;
    }

};

int main(){
    int h, w;
    std::cin >> h >> w;
    Rectangle rr(h, w);
    rr.output();

    return 0;
}