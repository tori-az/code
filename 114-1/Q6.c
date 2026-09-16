#include<stdio.h>

int main(){
    int num;
    scanf("%d", &num);
    int hun = num/100, ten = num%100/10, one = num%10;
    // Narcissistic
    int Narcissistic = hun*hun*hun + ten*ten*ten + one*one*one;
    if(Narcissistic == num) printf("Narcissistic Number");
    // Palindrome
    else if(hun == one) printf("Palindrome");
    // Increasing
    else if(hun < ten && ten < one) printf("Increasing");
    // Ordinary
    else    printf("Ordinary");

    return 0;
}