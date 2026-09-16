#include<iostream>

class ScoreRecord{
private:
    int a, b, ave;
public:
    void Input(){
        std::cin >> a >> b;
    }
    void Average(){
        ave = (a + b)/2;
    }
    void Output(){
        std::cout << "Average: " << ave;
    }
};

int main(){
    ScoreRecord s;
    s.Input();
    s.Average();
    s.Output();

    return 0;
}