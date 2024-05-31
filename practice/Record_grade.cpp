#include<iostream>
using namespace std;
int main()
{
    int N;
    int i;
    int max;
    int min;
    int grade[100];
    cin >> N;
    for(i = 1; N >= i; i++)
    {
        cin >> grade[i];
    } 
    i = 1;
    min = 20000;
    max = 0;
    while(i <= N)
    {
        if(grade[i] > max)
        max = grade[i];
        if(grade[i] < min)
        min = grade[i];
        i++;
    }
    cout << max << " " << min;
    return 0;
}

//答案最大值變數為無限小，找到更大的就替換原來的值。
//答案最小值變數為無限大，找到更小的就替換原來的值。