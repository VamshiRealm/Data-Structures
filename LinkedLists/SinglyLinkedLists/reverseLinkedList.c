#include <stdio.h>
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

Node* insFront(Node** start, int newValue){
    Node* newNode = (Node*) malloc (sizeof(Node));
    if(newNode == NULL){
        printf("Meory allocation Failed!!");
        return *start;
    }
    newNode->data = newValue;
    newNode->next = *start;
    *start = newNode;
    return *start;
}



// Node* reverseRecurse(Node* start){
//     if(start == NULL || start->next == NULL){
//         return start;
//     }
//     Node* newStart = reverseRecurse(start->next);
    
//     // Node* startNext = start->next;
//     start->next->next = start;
//     start->next = NULL;
//     return newStart;
// }

Node* reverse(Node* start){
    Node* current = start;
    Node* prev = NULL;
    
    while(current != NULL){
        Node* temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    return prev;
}



void freeList(Node* start){
    Node* temp = start;
    while(start != NULL){
        start = start->next;
        free(temp);
        temp = start;
    }
}

int main(){
    Node* start = NULL;
    
    insFront(&start, 55);
    insFront(&start, 44);
    insFront(&start, 33);
    insFront(&start, 22);
    insFront(&start, 11);
    
    printf("The Original List: \n");
    printList(start);
    
    start = reverse(start);
    
    
    printf("\n\nThe reversed List: \n");
    printList(start);
    
    freeList(start);
    
    return 0;
}
