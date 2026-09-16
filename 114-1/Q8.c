#include<stdio.h>

int main(){
    int day, passenger, ticket;
    double fare = 150;
    scanf("%d %d %d", &day, &passenger, &ticket);
    if(ticket == 2) fare += 100;
    if(passenger == 2 || passenger == 3)    fare *= 0.5;
    if(day == 2)    fare *= 1.2;
    printf("Final Fare: %d", (int)fare);

    return 0;
}