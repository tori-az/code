#include<iostream>
#include<exception>
using namespace std;

class ClassroomFullException : public exception{
public:
    const char* what() const noexcept override{
        return "Classroom capacity exceeded";
    }
};

void Check(int capacity, int current, int entering){
    if(current + entering <= capacity)  cout << current + entering;
    else    throw ClassroomFullException();
}

int main(){
    int capacity, current, entering;
    cin >> capacity >> current >> entering;

    try{
        Check(capacity, current, entering);
    }
    catch(const exception& e){
        cout << e.what();
    }

    return 0;
}