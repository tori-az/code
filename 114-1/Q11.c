#include<stdio.h>

int main(){
    int code, w, animal = 0, weight = 0, point = 0;
    int a = 0;
    while(1){
        scanf("%d %d", &code, &w);
        if(code == 0)   break;
        ++animal;
        weight += w;
        if(code == 1 && w > 100)   point += w+50;
        else if(code == 1)  point += w;
        else if(code == 2){
            ++a;
            if(a <= 5)  point += w*2;
        }
        else if(code == 3)  point += w*3;
    }
    printf("Total Animals Reported: %d\nTotal Weight Reported: %d kg\nTotal Conservation Points: %d", animal, weight, point);
    return 0;
}

/*for(scanf("%d %d", &code, &w); code != 0; scanf("%d %d", &code, &w))

scanf("%d %d", &code, &w);
while(code != 0){
    ++animal;
    weight += w;
    if(code == 1 && w > 100)   point += w+50;
    else if(code == 1)  point += w;
    else if(code == 2){
        ++a;
        if(a <= 5)  point += w*2;
    }
    else if(code == 3)  point += w*3;
    scanf("%d %d", &code, &w);
}*/