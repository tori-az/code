/*假設a <= b，只會有兩種情形：
按(△按鈕)轉過去：次數 = b-a
按(▽按鈕)轉過去：次數 = (a-0)+(100-b)
輸出次數較少的情形就可以了。
不過輸入進來的a, b不一定每次都是a <= b，這在數學計算上可能會有正負號的麻煩。
因此當發現a > b時，先幫a, b兩數交換就能解決這個困擾了＼(^ω^＼)*/
#include<iostream>
using namespace std;
int main()
{
    int a, b, w;
    int ans1, ans2;
    while(cin >> a >> b)
    {
        if(a == -1 and b == -1)
            break;
        if(a > b)
        {
            w = a;
            a = b;
            b = w;
        }
        ans1 = b-a;
        ans2 = (a-0)+(100-b);
        if(ans1 <= ans2)
        cout << ans1 << endl;
        else
        cout << ans2 << endl;
    }
    return 0;
}