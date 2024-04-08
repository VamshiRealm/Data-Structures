#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct{
    char items[50];
    int top;
}Stack;

void push(Stack* sp, char ch){
    if(sp->top == 49){
        printf("Stack Overflow\n");
        // exit(EXIT_FAILURE);
    }else{
        sp->items[++(sp->top)] = ch;
    }
}

char pop(Stack* sp){
    if(sp->top == -1){
        printf("Stack Underflow\n");
        // exit(EXIT_FAILURE);
    }
    return sp->items[sp->top--];
}

void revString(char str[], char rev[]){
    Stack sp;
    sp.top = -1;

    for(int i = 0; str[i] != '\0'; i++){
        push(&sp,str[i]);
    }
     

    int j;
    for(j = 0; sp.top != -1; j++){
        rev[j] = pop(&sp);
    }
    rev[j] = '\0';
}

int main(){
while(1){
    char str[40];
    char res_str[40];

    printf("Enter a valid string: ");
    scanf("%s", str);
    // scanf("%39[^\n]", str);     IF THE STRING HAS A SPACE IN BETWEEN THEN USE THIS LINE
    if(str[0] == '0'){
        exit(0);
    }

    revString(str,res_str);
    printf("Reverse string is: %s\n", res_str);
    printf("Please Enter 0 to exit the loop.\n");
}

    return 0;
}
