
// Implementation of queues using linked list...
#include<stdio.h>
#include<stdlib.h>

// Basic structure of a queue(Singly Linked List)
typedef struct node{
    int data;
    struct node* next;
}QueueNode;

// Enque function to enque an element from rear.
QueueNode* Enque(QueueNode* q, int val){
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));                     
    if(newNode == NULL){
        printf("Memory Allocation failed!!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = val;
    newNode->next = NULL;
    if(q == NULL){
        q = newNode;
    }else{
        QueueNode* temp = q;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return q;
}

// Function to dequeue the element from the front of the queue.
int Dequeue(QueueNode** q){
    if(*q == NULL){
        printf("Queue Underflow!!\n");
        exit(EXIT_FAILURE);
    }
    int value = (*q)->data;
    QueueNode* temp = *q;
    *q = (*q)->next;
    return value;
}

void displayQueue(QueueNode* q){
    if(q == NULL){
        printf("Empty Queue!!\n");
        return;
    }
    QueueNode* ptr = q;
    while(ptr != NULL){
        printf(" %d <- ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void destroyQueue(QueueNode* q){
    QueueNode* temp;
    while(q != NULL){
        temp = q;
        q = q->next;
        free(temp);
    }
}

int main(){
    QueueNode* q = NULL;
    int choice;

   
    do{
    printf("1.Enqueue 2.Dequeue 3.Display  4.Exit");
    scanf("%d", &choice);
        if(choice == 1){
            int element;
            printf("Enter the value that you want insert: ");
            scanf("%d", &element);
            q = Enque(q,element);
            printf("%d value Enqueued..\n");
        }
        if(choice == 2){
            int val = Dequeue(&q);
            printf("%d value Dequeued..\n",val);
        }
        if(choice == 3){
            displayQueue(q);
        }
    }while(choice != 4);
   
    destroyQueue(q);
    return 0;
}
