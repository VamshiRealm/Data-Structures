#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next; 
}Node;

void printList(Node* start){
    Node* ptr = start;
    while(ptr != NULL){
        printf(" %d -> ",ptr-> data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void freeList(Node* start){
    while(start != NULL){
        Node* temp = start;
        start = start ->next;
        free(temp);
    }
}

Node *insAtPosn(Node **start, int newValue, int posn){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Memory allocation Failed!!");
        return *start;
    }
    newNode->data = newValue;
    if(*start == NULL || posn == 1){
        newNode-> next = *start;
        *start = newNode;
        return newNode;
    }
    Node* ptr = *start;
    for(int i = 1; i < posn-1; i++){
        ptr = ptr->next;
    }
    if(ptr == NULL){
        printf("Position out of bound!!");
        return *start;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
    
}

// Node *mergeLists(Node* p, Node* q, Node* sorting){
//     Node* start = NULL;
    
//     if(p == NULL){
//         return q;
//     }
//     if(q == NULL){
//         return p;
//     }
    
//     if(p && q){
//         if(p->data <= q->data){
//             sorting = p;
//             p = sorting->next;
//         }
//         else{
//             sorting = q;
//             q = sorting->next;
//         }
//     }
    
//     start = sorting;
    
//     while(p && q){
//         if(p->data <= q->data){
//             sorting->next = p;
//             sorting = p;
//             p = sorting->next;
//         }
//         else{
//             sorting->next = q;
//             sorting = q;
//             q = sorting->next;
//         }
//     }
    
//     if(p == NULL){
//         sorting->next = q;
//     }
//     if(q == NULL){
//         sorting->next = p;
//     }
    
//     return start;
// }


Node* mergeLists(Node* start1, Node* start2, Node* result){
    Node* p = start1;
    Node* q = start2;
    Node* temp = result;
    if(p == NULL){
        return q;
    }
    if(q == NULL){
        return p;
    }
    
    if(p && q){
        if(p->data <= q->data){
            temp = p;
            p = temp ->next; 
        }else{
            temp = q;
            q = temp ->next;
        }
    }    
    result = temp;
    
    while( p && q ){
        if(p->data <= q->data){
            temp->next = p;
            temp = p;
            p = temp->next;
        }else{
            temp->next = q;
            temp = q;
            q = temp->next;
        }
    }
    
    if(p == NULL){
        temp->next = q;
    }
    if(q == NULL){
        temp->next = p;
    }
    return result;
}


int main(){
    Node *start1 = NULL, *start2 = NULL;
    Node* result = (Node*)malloc(sizeof(Node));
    // sorting->next = NULL;
    
    insAtPosn(&start1, 11, 1);
    insAtPosn(&start1, 22, 2);
    insAtPosn(&start1, 33, 3);
    insAtPosn(&start1, 44, 4);
    insAtPosn(&start1, 55, 5);
    
    printf("Linked list 1 before merging: \n");
    printList(start1);
    printf("\n\n");
    
    insAtPosn(&start2, 5, 1);
    insAtPosn(&start2, 10, 2);
    insAtPosn(&start2, 15, 3);
    insAtPosn(&start2, 20, 4);
    insAtPosn(&start2, 35, 5);
    insAtPosn(&start2, 60, 6);
    
    printf("Linked list 2 before merging: \n");
    printList(start2);
    printf("\n\n");
    
    
    
    
    printf("The Merged sorted list of both list is: \n");
    result = mergeLists(start1, start2, result);
    printList(result);
    
    
    
    
    
    return 0;
    
}



