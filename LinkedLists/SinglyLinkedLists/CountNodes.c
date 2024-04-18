#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node;


Node* insFront(Node** start, int newvalue){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Memory allocation Failed!!");
        return NULL;
    }
    newNode-> data = newvalue;
    newNode-> next = *start;
    *start = newNode;
    return newNode;
}

Node* insEnd(Node** start, int newValue){
    Node* newNode = (Node*) malloc (sizeof(Node));
    if(newNode == NULL){
        printf("Memory allocation Failed!!");
        return NULL;
    }
    Node* ptr = *start;
    while(ptr->next != NULL){
        ptr = ptr-> next;
    }
    newNode->data = newValue;
    newNode->next = NULL;
    ptr->next = newNode;
    return *start;
}


Node* traverseList(Node* start){
    Node* ptr = start;
    int count = 0;
    while(ptr != NULL){
        printf(" %d -> ", ptr ->data);
        ptr = ptr->next;
        count++;
    }
    printf("NULL\n");
    printf("The number of node in this list are: %d\n", count);
    return start;
}


void freeList(Node* start){
    Node* temp = start;
    while(temp != NULL){
        start = start->next;
        free(temp);
        temp = start;
    }
}

int main(){
    Node* start = NULL;
    
    insFront(&start, 11);
    insFront(&start, 22);
    insEnd(&start, 33);
    insFront(&start, 44);
    insEnd(&start, 55);
    insFront(&start, 66);
    
    // displayList(start);
    traverseList(start);
    
    
    freeList(start);
    
    return 0;
}
