#include<stdio.h>

int main(){
    int x1, y1, x2, y2, px, py;
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &px, &py);
    if((x1 < px && px < x2) && (y1 < py && py < y2))  printf("Inside");
    else if(((px == x1 || px == x2) && (y1 <= py && py <= y2)) || ((x1 <= px && px <= x2) && (py == y1 || py == y2)))   printf("On the border");
    else    printf("Outside");
    
    return 0;
}