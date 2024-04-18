#include <stdio.h>
#include<stdlib.h>
struct node{
    int value;
    struct node* next;
};
typedef struct node NODE;
NODE* linkListInitialize(int initialvalue){
    NODE* head = (NODE*)malloc(sizeof(NODE));
    (*head).value = initialvalue;
    head-> next = NULL;
    
    
    return head;
    
}
int main (){
    NODE* head = linkListInitialize(55);
    
    
    printf("The value of initial node of link list: %d\n", head->value);
    printf("The next(pointer) of initial node is: %p\n", head->next);
    
    free(head);
    return 0;
    
}
