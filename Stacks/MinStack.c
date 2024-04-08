#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int items[50];
    int top;
}Stack;



void push(Stack* sp, int value){
    if(sp->top == 49){
        printf("Stack Overfow\n");
        exit(1);
    }else{
        sp->items[++sp->top] = value;
    }
}

int pop(Stack* sp){
    if(sp->top == -1){
        printf("Stack Underflow\n");
        return -999;
    }else{
        int val = sp->items[sp->top--];
        return val;
    }
}



int main(){
    Stack *sp = (Stack*)malloc(sizeof(Stack));
    Stack *support_stack = (Stack*)malloc(sizeof(Stack));
    sp->top = -1;
    support_stack->top = -1;
    int choice,element;

    printf("Enter the operation: 1.Push 2.Pop 3.Minimum element 4.Exit 5.Stop Loop\n");
    scanf("%d", &choice);
    while(choice != 5){
        if(choice == 1){
            printf("Enter the number to be pushed: ");
            scanf("%d", &element);

            push(sp,element);
            if(support_stack->top >= 0 && element < support_stack->items[support_stack->top]){
                push(support_stack,element);
            }else if(support_stack->top == -1){
                push(support_stack,element);
            }
        }
        else if(choice == 2){
            if(sp->top == -1){
                printf("Stack Underflow\n");
                exit(1);
            }else{
                int popped = pop(sp);
                
                if(popped != -999){
                    printf("Element popped : %d\n", popped);

                    if(popped == support_stack->items[support_stack->top]){
                        int support_stack_element = pop(support_stack); // if popped element is the minimum element..
                    }
                }


            }
        }
        else if(choice == 3){
            if(support_stack->top <= -1){
                printf("Empty Stack!!\n");
            }else{
                printf("The minimun element in the stack is: %d\n\n", support_stack->items[support_stack->top]);
            }
        }
        else if(choice == 4){
            if (sp->top > -1) {
                printf("Main Stack:\n");
                    for (int i = sp->top; i >= 0; i--) {
                        printf("| %d |\n", sp->items[i]);
                        printf("------\n");
                    }
            } 


            if (support_stack->top > -1) {
                printf("Support Stack:\n");
                for (int i = support_stack->top; i >= 0; i--) {
                    printf("| %d |\n", support_stack->items[i]);
                    printf("------\n");
              }
            } else {
                printf("Empty Stacks!!\n");
            }


        }
        printf("Enter the operation: 1.Push 2.Pop 3.Minimum element 4.Exit 5.Stop Loop\n");
        scanf("%d", &choice);
    }

    return 0;
}
