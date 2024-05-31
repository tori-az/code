/*我們需要一個陣列 back 紀錄每個編號的志願者有沒有回來。
用0代表沒回來，1代表有回來。
例如:
back[5] == 1 代表5號志願者有回來
back[8] == 0 代表8號志願者沒回來*/
#include<iostream>
using namespace std;
int main()
{
    int n, R;
    int i;
    int num;
    int back[10001];
    while(cin >> n >> R)
    {
        for(i = 1; i <= n; i++)
        {
            back[i] = 0;
        }
        for(i = 1; i <= R; i++)
        {
            cin >> num;
            back[num] = 1;
        }
        if(n == R)
            cout << "*" << endl;
        else
        {
            for(i = 1; i <= n; i++)
            {
                if(back[i] == 0)
                    cout << i << " ";
            }
        }
        cout << endl;
    }
    return 0;
}