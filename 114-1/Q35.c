#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int id;
    struct node *next;
}Node;

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    Node *head = (Node*)malloc(sizeof(Node));
    head->id = 1;
    head->next = NULL;

    Node *current = head;
    for(int i = 2; i <= n; ++i){
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->id = i;
        newNode->next = NULL;
        current->next = newNode;
        current = newNode;
    }
    current->next = head;
    
    Node *prev = current;
    current = head;
    while(current->next != current){
        for(int i = 1; i < m; ++i){
            prev = current;
            current = current->next;
        }
        Node *temp = current;
        prev->next = current->next;
        current = current->next;
        free(temp);
    }

    printf("%d", current->id);
    free(current);
    return 0;
}

/*
// 逆推
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    
    int warrior = 0;

    for(int i = 2; i <= n; ++i){
        warrior = (warrior + m) % i;
    }

    printf("%d", warrior + 1);
    return 0;
}
*/