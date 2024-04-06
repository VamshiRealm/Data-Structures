#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int capacity;
    int top;
    int *arr;
}Stack;

int isFull(Stack* s){
    if(s->top == s->capacity-1){
        return 1;
    }else{
        return 0;
    }
}

int isEmpty(Stack* s){
    if(s->top == -1){
        return 1;
    }else{
        return 0;
    }
}

int push(Stack* s, int value){
    if(isFull(s)){
        printf("Stack Overflow!!, Cannot push %d into the stack!!\n", value);
    }else{
        s->top++;
        s->arr[s->top] = value;
    }
}

int pop(Stack* s){
    if(isEmpty(s)){
        printf("Stack Underflow !!, No element available to pop. \n");
        return -1;
    }else{
        int val = s->arr[s->top];
        s->top--;
        return val;
    }
}

int peek(Stack* s){
    if(isEmpty(s)){
        printf("Stack is Empty.\n");
    }else{
        printf("Top element is: %d\n", s->arr[s->top]);
    }
}

void printStack(Stack* s){
    if(isEmpty(s)){
        printf("NULL(Stack is Empty)\n");
    }else{
        printf("Stack :\n");
        for(int i = s->top; i >= 0; i--){
            printf("| %d |\n", s->arr[i]);
            printf("------\n");
        }
        printf("Bottom\n");
    }
}

int main(){
    Stack* s = (Stack*)malloc(1*sizeof(Stack));
    s->capacity = 50;
    s->top = -1;
    s->arr = (int*)malloc((s->capacity)* sizeof(int));

     push(s, 10);
     push(s, 20);
     push(s, 30);

    printf("Stack Before: \n");
    printStack(s);


    int choice,value;
    do {
        printf(" 1. Push   2. Pop   3. Peek  4. Display Stack  5. Exit\n");
        scanf("%d", &choice);

    switch(choice){
        case 1:
            printf("Enter the Element value");
            scanf("%d", &value);
            push(s, value);
            break;
        case 2:
            printf("Element %d popped from stack.\n", pop(s));
            break;
        case 3:
            peek(s);
            break;
        case 4:
            printStack(s);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Wrong Choice\n");
    }
    } while(1);


    free(s->arr);
    free(s);
    
    return 0;
}
