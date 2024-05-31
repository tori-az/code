// https://www.csie.ntu.edu.tw/~b98902112/cpp_and_algo/cpp/practice_save_withdraw.html
#include<iostream>
using namespace std;
int main()
{
    int N; //N個顧客
    int T; //T筆交易
    int n, t, m; //表第n名顧客，存款或提款了m元。t=1代表存款；t=2代表提款
    int customer[105]; //假設顧客編號是0~N-1，每名顧客帳戶一開始存有0元
    int i;
    cin >> N >> T;
    for(i = 0; i < N; i++)
    {
        customer[i] = 0;
    }
    for(i = 0; i < T; i++)
    {
        cin >> n >> t >> m;
        if(t == 1)
            customer[n] += m;
        if(t == 2)
            customer[n] -= m;
    }
    for(i = 0; N > i; i++)
    {
        cout << i << " : " << customer[i] << endl;
    }
    return 0;
}