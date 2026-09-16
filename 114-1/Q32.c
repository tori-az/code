#include<stdio.h>

int main(){
    char ISBN[25];
    fgets(ISBN, 25, stdin);
    
    int sum = 0;
    int n = 0; // 數字(0-9, X)計數器

    for(int i = 0; ISBN[i] != '\0'; ++i){
        if(n < 9 && ISBN[i] >= '0' && ISBN[i] <= '9'){
            int d = ISBN[i] - '0';
            sum += (10 - n) * d;
            ++n;
        }
        else if(n == 9){
            if(ISBN[i] == 'X'){
                sum += 10;
                ++n;
            }
            else if(ISBN[i] >= '0' && ISBN[i] <= '9'){
                sum += (ISBN[i] - '0');
                ++n;
            }
        }
    }

    if (n == 10 && sum % 11 == 0)   printf("Valid");
    else    printf("Invalid");

    return 0;
}