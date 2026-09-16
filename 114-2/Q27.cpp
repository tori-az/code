#include<iostream>
#include<string>
#include<map>
using namespace std;

class Book{
private:
    string title;
    bool valid;          // 1 可借，0 借出了
    string borrowerName; 

public:
    Book() : title(""), valid(1), borrowerName("") {}  // 給 map 用
    Book(const string& t) : title(t), valid(1), borrowerName("") {}
    
    bool status() const { return valid; }
    string who() const { return borrowerName; }
    
    void bo(const string& n) { borrowerName = n; valid = 0; }
    void re() { valid = 1; borrowerName = ""; }
};

class Student{
private:
    string name;
    int borrowCount;

public:
    Student() : name(""), borrowCount(0) {}
    Student(const string& n) : name(n), borrowCount(0) {}
    
    int getCnt() const { return borrowCount; }
    void bo() { ++borrowCount; }
    void re() { --borrowCount; }
};

class Library{
private:
    int available;
    int borrowed;
    map<string, Book> books;
    map<string, Student> students;

public:
    Library(int num) : available(num), borrowed(0) {}

    void addBook(const string& t){
        if(books.find(t) == books.end()){
            books[t] = Book(t);
        }
    }

    void bo(const string& name, const string& title){
        if(students.find(name) == students.end()){
            students[name] = Student(name);
        }

        if(books[title].status() == 0){
            cout << title << " unavailable\n"; 
        }
        else{
            if(students[name].getCnt() == 3){
                cout << name << " limit reached\n";
            }else{
                students[name].bo();
                books[title].bo(name); // 把學生的名字傳進去紀錄
                --available;
                ++borrowed;
                cout << name << " borrowed " << title << "\n";
            }
        }
    }

    void re(const string& name, const string& title){
        if(books[title].status() == 0 && books[title].who() == name){
            books[title].re();
            students[name].re();
            available++;
            borrowed--;
            cout << name << " returned " << title << "\n";
        }else{
            cout << name << " cannot return " << title << "\n";
        }
    }

    void status() const {
        cout << "Available: " << available << ", Borrowed: " << borrowed << "\n";
    }
};

int main(){
    int B, Q;
    cin >> B >> Q;
    Library library(B); 
    
    while(B--){
        string t;
        cin >> t;
        library.addBook(t);
    }
    
    while(Q--){
        string op;
        cin >> op;
        
        if(op == "BORROW"){
            string s, b;
            cin >> s >> b;
            library.bo(s, b);
        }
        else if(op == "RETURN"){
            string s, b;
            cin >> s >> b;
            library.re(s, b);
        }
        else if(op == "STATUS"){
            library.status();
        }
    }
    
    return 0;
}

// 不用 map 的話就用 Book Student 設陣列(題目有限制大小)，在類別裡加上return 書名跟名字的，再用迴圈跑一遍一個一個對
/*
#include<iostream>
#include<string>
using namespace std;

class Book{
private:
    string title;
    bool valid;          // 1 可借，0 借出了
    string borrowerName; 

public:
    Book() : title(""), valid(1), borrowerName("") {}
    Book(const string& t) : title(t), valid(1), borrowerName("") {}
    
    bool status() const {return valid;}
    string who() const {return borrowerName;}
    string getTitle() const {return title;} // 新增：讓圖書館可以看書名
    
    void bo(const string& n) { borrowerName = n; valid = 0; }
    void re() { valid = 1; borrowerName = ""; }
};

class Student{
private:
    string name;
    int borrowCount;

public:
    Student() : name(""), borrowCount(0) {}
    Student(const string& n) : name(n), borrowCount(0) {}
    
    int getCnt() const {return borrowCount;}
    string getName() const {return name;}   // 新增：讓圖書館可以看學生名字
    
    void bo() {++borrowCount;}
    void re() {--borrowCount;}
};

class Library{
private:
    int available;
    int borrowed;
    
    // 把 map 換成固定大小的陣列
    Book books[105];       // 最多 100 本書，開 105 比較保險
    int bookCount;         // 紀錄目前有幾本書
    
    Student students[205]; // 最多 200 個操作，極端情況下有 200 個不同學生
    int studentCount;      // 紀錄目前有幾個學生

    // --- 新增：陣列尋找引擎 ---
    
    // 找書本在陣列的第幾格
    int findBookIndex(const string& title) {
        for(int i = 0; i < bookCount; ++i){
            if(books[i].getTitle() == title) return i;
        }
        return -1; // 理論上不會發生，因為題目說書一定存在
    }

    // 找學生在陣列的第幾格，如果找不到，就當場「註冊」一個
    int getStudentIndex(const string& name) {
        for(int i = 0; i < studentCount; ++i){
            if(students[i].getName() == name) return i;
        }
        // 迴圈跑完都沒找到，代表是新學生
        students[studentCount] = Student(name);
        studentCount++; // 人數加一
        return studentCount - 1; // 回傳剛建好的那一格的索引值
    }

public:
    // 初始化時把計數器都歸零
    Library(int num) : available(num), borrowed(0), bookCount(0), studentCount(0) {}

    void addBook(const string& t){
        // 直接加到陣列尾端，並把計數器加一
        books[bookCount] = Book(t);
        bookCount++;
    }

    void bo(const string& name, const string& title){
        int sIdx = getStudentIndex(name);
        int bIdx = findBookIndex(title);

        if(books[bIdx].status() == 0){
            cout << title << " unavailable\n"; 
        }
        else{
            if(students[sIdx].getCnt() == 3){
                cout << name << " limit reached\n";
            }else{
                students[sIdx].bo();
                books[bIdx].bo(name); 
                available--;
                borrowed++;
                cout << name << " borrowed " << title << "\n";
            }
        }
    }

    void re(const string& name, const string& title){
        int sIdx = getStudentIndex(name);
        int bIdx = findBookIndex(title);

        if(books[bIdx].status() == 0 && books[bIdx].who() == name){
            books[bIdx].re();
            students[sIdx].re();
            available++;
            borrowed--;
            cout << name << " returned " << title << "\n";
        }else{
            cout << name << " cannot return " << title << "\n";
        }
    }

    void status() const {
        cout << "Available: " << available << ", Borrowed: " << borrowed << "\n";
    }
};

int main(){
    int B, Q;
    if(!(cin >> B >> Q)) return 0;
    Library library(B); 
    
    while(B--){
        string t;
        cin >> t;
        library.addBook(t);
    }
    
    while(Q--){
        string op;
        cin >> op;
        
        if(op == "BORROW"){
            string s, b;
            cin >> s >> b;
            library.bo(s, b);
        }
        else if(op == "RETURN"){
            string s, b;
            cin >> s >> b;
            library.re(s, b);
        }
        else if(op == "STATUS"){
            library.status();
        }
    }
    
    return 0;
}
*/