#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

void appendNode(Node** head, int newValue){
    Node* newNode = (Node*) malloc (sizeof(Node));
    newNode-> data = newValue;
    newNode -> next = NULL;
    if(*head==NULL){
        *head = newNode;
        return ;
    }
    Node* current = *head;
    while(current-> next != NULL){
        current = current-> next;
    }
    current-> next = newNode;
}


void printList(Node* head){
    while(head != NULL){
        printf("%d -> ", head-> data);
        head = head-> next;
    }
    printf("NULL\n");
}

void freeList(Node* head){
    while(head != NULL){
    Node* temp = head;
    head = head -> next;
    free(temp);
    }
}

int main(){
    Node* head = NULL;
    
    appendNode(&head, 11);
    appendNode(&head, 22);
    appendNode(&head, 33);
    
    printList(head);
    

    
    freeList(head);
    
    return 0;
}
