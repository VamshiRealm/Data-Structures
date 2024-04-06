
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
typedef struct node Node;

int Push(Node* top, int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Memory allocation Failed!!");
        return 0;
    }
    newNode->data = value;
    if(top == NULL){
        newNode->next = NULL;
        top = newNode;
    }else{
        newNode->next = top;
        top = newNode;
    }

}

int Pop(Node* top){
    if(top == NULL){
        printf("Empty Stack(Stack Underflow)!!");
        return 1;
    }
    Node* temp = top;
    printf("Node: %d  Popped.", top->data);
    top = top->next;
    free(temp);
}

int Peek(Node* top){
    if(top == NULL){
        printf("EMPTY STACK!!");
        return -1;
    }
    printf("The value of top Node is: %d ", top->data);
    return 1;
}

void printStack(Node* top){
    Node* ptr = top;
    printf("Top --> ");
    while(ptr != NULL){
        printf(" %d ", ptr->data);
        ptr = ptr->next;
    }
    printf("-->NULL\n");
}

void freeStack(Node* top){
    Node* temp = NULL;
    while(top != NULL){
        temp = top;
        top = top->next;
        free(temp);
    }
}

int main(){
    int top = NULL;

    top = Push(top,30);
    top = Push(top,20);
    top = Push(top,10);

    printf("Defaulted Stack: \n");
    printStack(top);

    int input = NULL;
    printf(" 1. Push \n 2. Pop \n 3. Peek \n 4. Stop \n");
    printf("Please enter your choice: ");
    scanf("%d", &input);

    switch (input){
        case 1:
            int value;
            printf("Enter the value to push: ");
            scanf("%d", &value);

            Push(top, value);
            break;

        case 2:
            printf("The popped value is: %d\n", top->data);
            Pop(top);
            break;
        
        case 3:
            Peek(top);
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("<<Invalid Choice>>\n");
    }

