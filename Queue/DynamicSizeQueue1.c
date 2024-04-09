
// Implementation of queues using dynamic array

#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int* queue;
    int front, rear;
    int Capacity;
}Queue;

// Function to create queue
Queue* createQueue(int capacity){
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));;
    if(newQueue == NULL){
        printf("Memory allocation failed!!\n");
        exit(EXIT_FAILURE);
    }
    newQueue->queue = (int*)malloc(sizeof(int)* capacity);
    if(newQueue->queue == NULL){
        printf("Insufficient memory!1\n");
        exit(EXIT_FAILURE);
    }
    newQueue->Capacity = capacity;
    newQueue->front = 0;
    newQueue->rear = -1;

    return newQueue;
}

// Function to resize the queue unsing dynamic arrays
int reSizeQueue(Queue* q, int sizeChange){
    int newSize = q->Capacity + sizeChange;
    int* newArray = (int*)malloc(sizeof(int)* newSize);
    if(newArray == NULL){
        printf("Memory Insufficient\n");
        exit(EXIT_FAILURE);
    }
    q->Capacity = newSize;
    q->queue = newArray;
    return 1;
}

// Fuunction to add element into the queue
void Enqueue(Queue* q, int value){
    if(q->rear == q->Capacity -1){
        // Resize Queue
        if(!reSizeQueue(q,1)){
            printf("Queue is full!!\n");
            return;
        }
    }
    q->queue[++q->rear] = value;
    printf("Enqueued %d\n", value);
}

int Dequeue(Queue* q){
    if(q->front > q->rear){
        printf("Empty Queue!!\n");
        exit(EXIT_FAILURE);
    }
    int item = q->queue[q->front];
    if(q->front == q->rear){
        //Resize initiate front, rear pointers
        q->front = 0;
        q->rear = -1;
    }else{
        q->front++;
        // optional to decrease the size of the array 
        reSizeQueue(q, -1);
    }
    return item;
}
void DisplayQueue(Queue* q){
    if(q->front > q->rear){
        printf("Empty Queue!!\n");
        return;
    }else{
        for(int i = q->front; i <= q->rear; i++){
            printf(" %d <-",q->queue[i]);
        }
        printf("\n");
    }
}
void destroyQueue(Queue* q){
    free(q->queue);
    free(q);
}

int main(){
    Queue* q  = createQueue(10);

    int choice;
    while(choice != 5){
        printf("1.Enqueue 2.Dequeue 3.Display 5.Exit");
        scanf("%d", &choice);

        if(choice == 1){
            int value;
            printf("Enter the value:\n");
            scanf("%d", &value);
            Enqueue(q,value);
        }
        else if(choice == 2){
            int value = Dequeue(q);
            printf("Value %d dequeued from the queue\n", value);
        }
        else if(choice == 3){
           DisplayQueue(q);
        }
        else{
            printf("Wrong Choice\n");
        }
    }
    destroyQueue(q);
    printf("Queue is Destroyed!!\n");
   
    return 0;
}
