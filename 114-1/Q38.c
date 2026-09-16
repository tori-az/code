#include<stdio.h>

// Building > Floor > Room > Bed
// 定義床位結構，包含 30 天的狀態
typedef struct{
    int days[30];
}Bed;

// 定義房間結構，包含 4 張床
typedef struct{
    Bed beds[4];
}Room;

typedef struct{
    Room rooms[5];
}Floor;

typedef struct{
    Floor floors[5];
}Building;

int main(){
    Building dorm[3] = {0}; // 三棟樓
    int n;
    scanf("%d", &n);
    while(n--){
        int b, f, r, bed, Start, End;
        int succ = 1;
        scanf("%d%d%d%d%d%d", &b, &f, &r, &bed, &Start, &End);
        Bed *target_bed = &dorm[b].floors[f].rooms[r].beds[bed]; // 先把指定的床的位址記下來

        for(int i = Start; i < End; ++i){
            if(target_bed -> days[i] == 1){  // target_bed -> days[i] 等同 (*target_bed).days[i]
                succ = 0;
                printf("Conflict\n");
                break;
            }
        }
        if(succ){
            for(int i = Start; i < End; ++i){
                target_bed -> days[i] = 1;
            }
            printf("Success\n");
        }
    }

    return 0;
}

/*
int main(){
    // dorm[Building][Floor][Room][bed][Day]
    int dorm[4][6][6][5][31] = {0}; 
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        int B, F, R, Bed, Start, End;
        int succ = 1;

        scanf("%d%d%d%d%d%d", &B, &F, &R, &Bed, &Start, &End);
        for(int j = Start; j < End; ++j){
            if(dorm[B][F][R][Bed][j] == 1){
                succ = 0;
                printf("Conflict\n");
                break;
            }
        }

        if(succ){
            for(int j = Start; j < End; ++j)  dorm[B][F][R][Bed][j] = 1;
            printf("Success\n");
        }
    }

    return 0;
}
*/