#include<iostream>
using namespace std;
int main()
{
    int hight[101];
    int n, sum, avg, ans, i;
    cin >> n;
    sum = 0;
    for(i = 0; i < n; i++)
    {
        cin >> hight[i];
        sum+=hight[i];
    }
    avg = sum/n;
    ans = 0;
    for(i = 0; i < n; i++)
    {
        if(hight[i] > avg)
            ans+=(hight[i]-avg);
    }
    cout << "The minimum number of moves is " << ans << "." << endl;
    return 0;
}