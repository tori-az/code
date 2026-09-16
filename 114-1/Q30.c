#include <stdio.h>

int main(){
    char stack[105];
    int top = -1;
    char a;

    // 把右括弧排好，遇到左括弧把最外面的右括弧拿出來
    while(scanf("%c", &a) != EOF && a != '\n'){
        if(a == '(' || a == '[' || a == '{'){
            stack[++top] = a;
        }
        else if(a == ')' || a == ']' || a == '}'){
            if(top == -1){ // 第一個就左
                printf("Invalid");
                return 0;
            }
            
            char b = stack[top--];
            if((a == ')' && b != '(') || 
               (a == ']' && b != '[') || 
               (a == '}' && b != '{')){
                printf("Invalid");
                return 0;
            }
        }
    }

    printf("%s", (top != -1) ? "Invalid" : "Valid");
    
    return 0;
}