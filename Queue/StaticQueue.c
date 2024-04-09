// Static Queue (using Static array) 
#include<stdio.h>
#define MAX 5
typedef struct{
    int items[MAX];
    int front, rear;
}Queue;

void insert(Queue* q, int val){
    if(q->rear < MAX -1){
        q->items[++(q->rear)] = val;
    }else{
        printf("Static array is full\n");
    }
}

int isEmpty(Queue* q){
    return q->rear < q->front;
}

// int remove1(Queue* q){
//     if(!isEmpty(q)){
//         int val = q->items[(q->front)++];
//         return val;
//     }
//     else{
//         printf("Queue is empty!!\n");
//     }
// }

int remove1(Queue* q){
    if(q->front > q->rear){
        printf("Empty Queue!!");
        return 0;
    }else{
        int item = q->items[q->front];
        if(q->front == q->rear){
            q->front = 0;
            q->rear = -1;
        }else{
            q->front++;
        }
        return item;
    }
}

void display(Queue* q){
    if(isEmpty(q)){
        printf("Empty Queue!!");
    }else{
        for(int i = q->front; i <= q->rear; i++ ){
            printf(" %d <- ",q->items[i]);
        }
    }
    printf("\n");
}

int main(){
    Queue q;
    q.front = 0;
    q.rear = -1;


    int choice = 0;
   
        while(choice != 5){
             printf("1.insert 2.Remove 3.Check Empty 4.Display 5.Exit :");
             scanf("%d", &choice);
            if(choice == 1){
                int value;
                printf("Enter the value : ");
                scanf("%d", &value);

                insert(&q,value);
                printf("Value %d inserted into queue successfully.\n", value);
            }
            else if(choice == 2){
                int val = remove1(&q);
                printf("Value %d removed from the queue.\n", val);
            }
            else if(choice == 3){
                if(isEmpty(&q)){
                    printf("The queue is empty!!\n");
                }else{
                    printf("The Queue is not Empty!!\n");
                }
            }
            else if(choice == 4){
                printf("The queue is: \n");
                display(&q);
            }
            else{
                printf("Wrong choice!!\n");
            }
        }
    
}
