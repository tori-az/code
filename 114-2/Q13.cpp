#include<iostream>

class Score{
private:
    int a, b;
public:
    void input(){
        std::cin >> a >> b;
    }

    void sort(int &score1, int &score2){
        if(score1 > score2){
            int temp = score1;
            score1 = score2;
            score2 = temp;
        } 
    }

    void output(){
        sort(a, b);
        std::cout << a << ' ' << b;
    }
};

int main(){
    Score s;
    s.input();
    s.output();

    return 0;
}