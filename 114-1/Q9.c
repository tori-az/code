#include<stdio.h>

int main(){
    int crop, age, organic;
    double area;
    double subsidy;
    scanf("%d %d %d %lf", &crop, &age, &organic, &area);
    if(crop == 1 && area <= 5)   subsidy = area * 10000;
    else if(crop == 1 && area > 5)  subsidy = 50000 + (area-5)*0.8*10000;
    else if(crop == 2)  subsidy =  area * 8000;
    else if(crop == 3)  subsidy = area * 6000;
    if(crop == 2 && organic == 1)    subsidy *= 1.8;
    else if(organic == 1)  subsidy *= 1.5;
    if(age <= 40 && !(crop == 3 && area < 0.5))  subsidy *= 1.2;
    if(subsidy > 200000)    subsidy = 200000;
    printf("Final Subsidy: %d", (int)subsidy);

    return 0;
}