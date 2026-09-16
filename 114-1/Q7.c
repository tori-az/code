#include<stdio.h>

int main(){
    double a;
    scanf("%lf", &a);

    // 乘上 10^7，避免進位所以把最後一位 -5
    long long temp =(long long)(a * 1e7)-5;
    printf("%lld\n", temp);

    // 把最後一位清零 (去除第 7 位小數)
    temp = (temp / 10) * 10;
    printf("%lld\n", temp);

    // 除以 10^7 得到保留到小數第 6 位的數字
    a = (double)temp / 1e7;
    printf("%lf\n", a);
    
    if(a >= 28)   printf("It's hot! A great day for the beach at Qixingtan or river tracing at Mugumuyu!");
    else if(a >= 22)  printf("The weather is comfortable. Perfect for cycling at Liyu Lake or strolling through Taroko Gorge!");
    else if(a >= 18)  printf("It's a bit cool. A good time to visit the Ruisui or Antong hot springs.");
    else    printf("It's cold. We recommend indoor activities, like visiting the Pine Garden.");

    return 0;
}