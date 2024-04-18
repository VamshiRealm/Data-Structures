#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

void printList(Node* start){
    Node* ptr = start;
    while(ptr != NULL){
        printf(" %d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
void freeList(Node* start){
    Node* temp = start;
    while(temp != NULL){
        start = start->next;
        free(temp);
    }
}
Node* addNode(Node** start, int newValue, int posn){
    if(start == NULL || posn <= 0){
        printf("Invalid position");
        return NULL;
    }
    Node* newNode = (Node*)malloc (sizeof(Node));
    if(newNode == NULL){
        printf("Memory allocation failed!!");
        return *start;
    }
    newNode-> data = newValue;
    newNode->next == NULL;
    
    if(posn == 1){
        newNode->next = *start;
        *start = newNode;
        return *start;
    }
    Node* ptr = *start;
    int count = 1;
    
    while(count < posn -1 && ptr != NULL){
        ptr = ptr->next;
        count++;
    }
    if(ptr == NULL){
        printf("Memory out of bound!!");
        free(newNode);
        return *start;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
}
int main(){
    Node* start = NULL;
     
    addNode(&start, 11, 1);
    addNode(&start, 22, 2);
    addNode(&start, 33, 3);
    addNode(&start, 44, 4);
    addNode(&start, 55, 5);
    
    printf("The list before adding the new Node: \n");
    printList(start);
    
    int a,b ;
    
    printf("Enter the position that you want to add a Node: ");
    scanf("%d", &b);
    printf("Enter the value of the new Node: ");
    scanf("%d", &a);
    
    addNode(&start, a, b);
    printf("The new List after adding node: \n");
    printList(start);
    
    return 0;
}
