//https://openhome.cc/Gossip/CppGossip/OneDimArray.html
int number[10] = {0};      // 長度為 10 的整數陣列裡的元素初始值皆為 0
double score[10] = {0.0};  // 長度為 10 的浮點數陣列裡的元素初始值皆為 0.0
char ascii[10] = {'\0'};  // 長度為 10 的字元陣列裡的元素初始值空字元
bool flag[10] = {false};  // 長度為 10 的布林值陣列裡的元素初始值皆為 false

// 也可以在宣告陣列時初始所有的陣列值
int number[5] = {0, 1, 2, 3, 4};
double score[5] = {87.0, 78.0, 99.5, 69.5, 82.5};
char ascii[5] = {'A', 'B', 'C', 'D', 'E'};
bool flag[5] = {false, true, false, true, false};

// 可以不用指派每一個元素的值，只指派前幾個，不足者會自動補 0
int arr[4] = {1, 4};
cout<<arr[0]<<" "<<arr[3]<<'\n';
// output : 1 0

// 若在宣告陣列時指定各個索引處的的值，可以不用宣告陣列元素大小
int number[] = {1, 2, 3};                // 元素個數 3
double weight[] = {0.4, 3.2, 1.0, 4.2};  // 元素個數 4
char ch[] = {'A', 'B'};                  // 元素個數 2

// 但若全部未指定值，則陣列中每個元素的值可能是任何值！
// 陣列宣告過後，不可改變大小或重新宣告。

// 使用 LEN 紀錄陣列長度
#include <iostream> 
using namespace std; 

int main() { 
    constexpr int LEN = 10;
    int number[LEN] = {0}; 

    for(int i = 0; i < LEN; i++) {
        cout << number[i] << " "; 
    }
    cout << endl; 

    for(int i = 0; i < LEN; i++) {
        number[i] = i; 
    }

    for(int i = 0; i < LEN; i++) {
        cout << number[i] << " "; 
    }
    cout << endl; 

    return 0; 
}
/*
output :
0 0 0 0 0 0 0 0 0 0
0 1 2 3 4 5 6 7 8 9
*/

int length = sizeof(number) / sizeof(number[0]);
/* sizeof(number) 是計算 number 陣列佔用的總位元組數量，sizeof(number[0]) 是計算 number 陣列中每個元素佔用的位元組數量。
由於陣列在記憶體中是連續存放的，因此可以通過 sizeof(number) 除以 sizeof(number[0]) 來得到陣列中元素的個數，也就是陣列的長度。
在陣列元素數量改變時，不需要手動修改 length 變數的值，而是**根據陣列本身的大小自動計算**。

陣列名稱儲存了陣列記憶體的首個位置的位址，而索引值表示陣列元素是相對於陣列首個記憶體位址的位移量（offset），位移的量與資料型態長度有關，如果是 int 整數，每次位移時是一個 int 整數的長度，例如在上例中 number[0] 索引值為 0 時，表示位移量為 0，自然就是指第一個元素，而 number[9] 就是指相對於首個元素的位移量為 9。*/

int main() { 
    int number[5] = {0, 1, 2, 3, 4};

    for(auto offset = begin(number); offset != end(number); offset++) {
        auto n = *offset;
        cout << n << " "; 
    }
    cout << endl; 

    return 0; 
}
/* offset 是個指標（pointer），型態會是 int*，儲存的是位址，而 *offset 是取得儲存於該位址的值

auto offset = begin(number);：這行程式碼宣告一個名為 offset 的變數，並將其初始化為 number 陣列的起始位置，即 begin(number)。begin() 是標準程式庫中的一個函式，用於取得容器（如陣列、向量等）的起始位置。

offset != end(number);：這是一個條件判斷式，判斷 offset 是否還未達到 number 陣列的結束位置，即 end(number)。end() 是標準程式庫中的一個函式，用於取得容器的結束位置。

offset++：每次迭代後，將 offset 增加一個位置，即指向下一個元素。這是一個迴圈步進的動作。

auto n = *offset;：這行程式碼宣告一個名為 n 的變數，並將其初始化為 offset 指向的元素的值。*offset 表示取得 offset 指向的元素。

cout << n << " ";：將 n 的值輸出到標準輸出（通常是終端機或者控制台），並在後面加上一個空格。*/

// 上者與此功能相同
int main() { 
    int number[5] = {0, 1, 2, 3, 4};

    for(auto n : number) {
        cout << n << " "; 
    }
    cout << endl; 

    return 0; 
}

// 如果使用 const 或 constexpr 來修飾陣列，每個索引位置就成為唯讀
constexpr int number[] = {1, 2, 3}; // const int number[]
number[1] = 10; // error: assignment of read-only location 'number[1]'

/* 在競賽中，通常把陣列放在全域!
全域變數有兩大特點 :
1. 會自動初始化為每種型態的預設值，可避免很多不必要的錯誤
如果宣告在區域又未指定初始值，它的值是不一定的
2. 在硬體中的儲存位置，導致區域陣列通常只能開到數百萬的大小，但全域陣列可開到數千萬
區域陣列開太大超出限制的話，會在運行到那一行時產生RE。
全域陣列開太大超出限制的話，在編譯時，編譯器就會將其擋住，無法通過編譯。 */

// 多維陣列乘起來不可以超過大小限制 (約 1e8)，不然會 RE / CE