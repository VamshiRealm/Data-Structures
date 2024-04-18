#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

void insFront(Node** start, int newValue){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL){
        printf("Memory allocation Failed!!");
    }
    newNode -> data = newValue;
    newNode-> next = *start;
    *start = newNode;
}

void printList(Node* start){
    while(start != NULL){
        printf("%d -> ", start-> data);
        start = start->next;
    }
    printf("NULL\n");
}

void insEnd(Node** start, int newValue){
    Node* newNode = (Node*) malloc (sizeof(Node));
    if (newNode == NULL){
        printf("Memory allocation Failed!!");
        return;
    }
    newNode-> data = newValue;
    newNode-> next = NULL;
    
    Node* ptr = *start;
    if(ptr == NULL){
        *start = newNode;
    }
    while(ptr-> next != NULL){
        ptr = ptr-> next;
    }
    ptr-> next = newNode;
}

void freeList(Node* start){
    Node* temp;
    while(start != NULL){
        temp = start;
        start = start->next;
        free(temp);
    }
}

void insBetween(Node** start, int newValue, int index){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Memory allocation failed!");
        return;
    }
    
    Node* ptr = *start;
    int i = 1;
    
    while(index <= 0){
        printf("Invalid index!");
        free(newNode);
        return;
    }
    
    while(i < index -1){
        if(ptr == NULL){
            printf("Index out of Bound!");
            free(newNode);
            return;
        }
        ptr = ptr->next;
        i++;
    }
    newNode-> next = ptr->next;
    newNode->data = newValue;
    ptr->next = newNode;
}
int main(){
    Node* start = NULL;
    insFront(&start, 33);
    insEnd(&start, 44);
    insFront(&start, 22);
    insEnd(&start, 55);
    insFront(&start, 11);
    
    printList(start);
    int a,b;
    printf("Enter the Index no. you want to insert a node: ");
    scanf("%d", &b);
    printf("Enter the value that you want to store at that index: ");
    scanf("%d", &a);
    
    insBetween(&start,a,b);
    printf("After the index insertion:\n");
    printList(start);
    
    freeList(start);
    return 0;
}
