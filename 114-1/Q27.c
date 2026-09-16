#include <stdio.h>
#include <string.h>

int main(){
    char A[105], B[105];
    int multi[250] = {0}; 
    scanf("%s %s", A, B);

    int lenA = strlen(A);
    int lenB = strlen(B);
    for(int i = lenA - 1; i >= 0; --i){
        int a = A[i] - '0';
        for(int j = lenB - 1; j >= 0; --j){
            int b = B[j] - '0';

            // 從後面塞(lenA+lenB 往前)
            int p1 = i + j; // 要接收進位的前一個位置
            int p2 = i + j + 1; // 當前要填入個位數的位置

            int temp = a * b + multi[p2]; // multi[p2] 之前算過且落在這個位置的總和
            multi[p2] = temp % 10; // = (a*b + multi[p2]) % 10 這次計算的個位
            multi[p1] += temp / 10; // 進位
            // 下一次的 p2 就是這一次的 p1
        }
    }

    // 找出起點，因為從後面開始放
    int start = 0;
    while(start < lenA + lenB && multi[start] == 0) ++start;

    if(start == lenA + lenB)    printf("0"); // 都是 0 就輸出一個 0 
    else{
        for(int i = start; i < lenA + lenB; ++i){
            printf("%d", multi[i]);
        }
    }
    
    return 0;
}