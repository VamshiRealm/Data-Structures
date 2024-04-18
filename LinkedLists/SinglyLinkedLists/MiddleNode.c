//Rabbit-tortoise method
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

void printList(Node* start){
    Node* ptr = start;
    // int count = 0;
    while(ptr!= NULL){
        printf(" %d -> ",ptr->data);
        ptr = ptr->next;
        // count++;
    }
    printf("NULL\n");
    // printf("the number of Nodes in LL are: %d\n", count);
}
 


Node* insAtPosn(Node* start, int newValue, int posn){
    Node* newNode = (Node*) malloc (sizeof(Node));
    newNode->data = newValue;
    if(newNode == NULL){
        printf("Memory allocation failed!!");
        return NULL;
    }
    if(start == NULL || posn == 1){
        newNode->next = start;
        start = newNode;
    }
    Node* ptr = start;
    for(int i = 1; i < posn-1; i++){
        ptr = ptr->next;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
    return start;
}

Node* middleEle(Node* start){
    Node* p = start;
    Node* q = start;
    while(q != NULL && q->next != NULL){
        p = p->next;
        q = q->next->next;
    }
    return p;
}

void freeList(Node* start){
    Node* temp = start;
    while(temp!= NULL){
        start = start->next;
        free(temp);
        temp = start;
    }
}

int main(){
    Node* start = (Node*)malloc(sizeof(Node));
    if(start == NULL){
        printf("Memory allocation Failed!!");
        return 1;
    }
    
    insAtPosn(start, 11, 1);
    insAtPosn(start, 22, 2);
    insAtPosn(start, 33, 3);
    insAtPosn(start, 44, 4);
    insAtPosn(start, 55, 5);
    
    printList(start);
    
    Node* middleNode = middleEle(start);
    printf("The middle node in the LL is: %d", middleNode->data);
    
    
    freeList(start);
    
    
    

   return 0; 
}
