#include<stdio.h>

int main(){
    int x = 1, y = 10, z = 100;

    if(x > 0 || y-- > 5){
        z = 101;
    }
    if(x < 0 || z++ > 100){
        y = 50;
    }
    printf("y = %d, z = %d", y, z);
    
    return 0;
}