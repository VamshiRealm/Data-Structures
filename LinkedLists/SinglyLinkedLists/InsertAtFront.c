#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}NODE;

void insertFront(NODE** head, int newData){
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    if(newNode == NULL){
        fprintf(stderr,"Memory allocation failed!!\n");
        exit(EXIT_FAILURE);
    }
    newNode-> data = newData;
    newNode-> next = *head;
    *head = newNode;
}
 void printList(NODE* head){
     while(head != NULL){
         printf("%d -> ", head->data);
         head = head-> next;
     }
     printf("NULL\n");
 }
 void freeList(NODE* head){
     while(head != NULL){
         NODE* temp = head;
         head = head-> next;
         free(temp);
     }
 }
 
 int main(){
     
    NODE* head = NULL;
     
    insertFront(&head, 11);
    insertFront(&head, 22);
    insertFront(&head, 33);
     
    printList(head);
     
    freeList(head);
     
    return 0;
 }

