#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100

typedef struct{
    int items[MAX_SIZE];
    int top1;
    int top2; 
}DoubleStack;

void initializeTops(DoubleStack* ds){
    ds->top1 = -1;
    ds->top2 = MAX_SIZE;
}

void push1(DoubleStack* ds, int val){
    if(ds->top1 < ds->top2-1){
        ds->items[++(ds->top1)] = val;
    }else{
        printf("STACK OVERFLOW FOR STACK 1\n");
    }
}

void push2(DoubleStack* ds, int val){
    if(ds->top1 < ds->top2-1){
        ds->items[--(ds->top2)] = val;
    }else{
        printf("STACK OVERFLOW FOR STACK 2\n"); 
    }
}

int pop1(DoubleStack* ds){
    if(ds->top1 > -1){
        return ds->items[(ds->top1)--];
    }else{
        printf("STACK UNDERFLOW FOR STACK 1\n");
        return -1;
    }
}

int pop2(DoubleStack* ds){
    if(ds->top2 < MAX_SIZE){
        return ds->items[(ds->top2)++];
    }else{
        printf("STACK UNDERFLOW FOR STACK 2\n");
        return -1;
    }
}

int peek1(DoubleStack* ds){
    if(ds->top1 > -1){
        return ds->items[ds->top1];
    }else{
        printf("Empty Stack 1 !!\n");
    }
}

int peek2(DoubleStack* ds){
    if(ds->top2 < MAX_SIZE){
        return ds->items[ds->top2];
    }else{
        printf("Empty Stack 2 !!\n");
    }
}


int main(){
    DoubleStack ds;
    initializeTops(&ds);

    push1(&ds,10);
    push1(&ds,20);

    push2(&ds,80);
    push2(&ds,70);

    printf("The top element of stack 1 is : %d\n", peek1(&ds));
    printf("The top element of stack 2 is : %d\n", peek2(&ds));

    printf("Element popped from Stack 1 : %d\n",pop1(&ds));
    printf("Element popped from Stack 2 : %d\n",pop2(&ds));

    
    printf("The NEW top element of stack 1 is : %d\n", peek1(&ds));
    printf("The NEW top element of stack 2 is : %d\n", peek2(&ds));

    return 0;
}
