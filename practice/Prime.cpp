// https://www.csie.ntu.edu.tw/~b98902112/cpp_and_algo/cpp/practice_isprime.html
#include<iostream>
using namespace std;
int main()
{
    int n, i, ans;
    while(cin >> n)
    {
        i = 2; //看n在2~(n-1)有沒有因數
        ans = 0;
        while(i < n)
        {
            if(n%i == 0)
            ans = 1;
            i++;
        }
        if(ans == 1 or n == 1 or n==0)
            cout << "No" << endl;
        else 
            cout << "Yes" << endl;
    }
return 0;
}