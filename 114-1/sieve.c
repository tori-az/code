#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int isPrime[n];
    isPrime[0] = 0;
    isPrime[1] = 0;

    for(int i = 2; i <= n; ++i) isPrime[i] = 1;

    for(int p = 2; p * p <= n; ++p){    //任何 100 以內的合數 k，都『保證』至少有一個『小於或等於 10』的因數
        if(isPrime[p] == 1){
            for(int i = p * p; i <= n; i += p){
                isPrime[i] = 0;
            }
        }
    }

    for(int i = 2; i <= n; i++){
        if(isPrime[i] == 1) printf("%d ", i);
    }

    return 0;
}