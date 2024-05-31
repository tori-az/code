// https://zerojudge.tw/ShowProblem?problemid=f327
#include <iostream>
using namespace std;

int columnToNumber(string colName) {
    int result = 0;
    for (int i = 0; i < colName.size(); i++) {
        result = result * 26 + (colName[i] - 'A' + 1);
    }
    return result;
}

int main() {
    string startCol, endCol;
    cin >> startCol >> endCol;
    
    int startNum = columnToNumber(startCol);
    int endNum = columnToNumber(endCol);
    
    int numColsDeleted = endNum - startNum + 1;
    cout << numColsDeleted << endl;
    
    return 0;
}