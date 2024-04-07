 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 #define MAX_SIZE 100

 typedef struct stack{
    int capacity;
    int top;
    char *arr; // It is an character array = expression
 }Stack;

 int isEmpty(Stack* ptr){
    if(ptr->top == -1){
        return 1;
    }else{
        return 0;
    }
 }

 int isFull(Stack* ptr){
    if(ptr->top == ptr->capacity-1){
        return 1;
    }else{
        return 0;
    }
 }

 void push(Stack* ptr, char val){
    if(isFull(ptr)){
        printf("Stack Overflow!! Cannot push %d into the stack.", val);
    }else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
 }

 char pop(Stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow !!(Empty Stack)");
    }else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
 }

 int parenthesisMatch(char* exp){
    // Create and initialize stack
    Stack* sp = (Stack*)malloc(sizeof(Stack));
    sp->capacity = 100;
    sp->top = -1;
    sp->arr = (char*)malloc(sp->capacity* sizeof(char));

    for(int i = 0; exp[i]!= '\0'; i++){
        if(exp[i] == '('){
            push(sp,'(');
        }
        else if(exp[i] == ')'){
            if(isEmpty(sp)){
                return 0;
            }
            pop(sp);
        }
    }
    if(isEmpty(sp)){
        return 1;
    }else{
        return 0;
    }
 }

 int stackTop(Stack* sp){
    return sp->arr[sp->top];
 }

int Precedence(char ch){
    if(ch == '^' || ch == '$'){
        return 4;
    }
    else if(ch == '*' || ch == '/'){
        return 3;
    }
    else if(ch == '+' || ch == '-'){
        return 2;
    }else{
        return 0; 
    }
}

int isOperator(char ch){
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '$' ){
        return 1;
    }else{
        return 0;
    }
}


 char* InfixToPostfix(char* infix){
    Stack* sp = (Stack*)malloc(sizeof(Stack));
    sp->capacity = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->capacity * sizeof(char));

    char* postfix = (char*)malloc((strlen(infix)+1)* sizeof(char));
    int i = 0; // Infix scanner
    int j = 0; // Postfix filler

    while(infix[i] != '\0'){
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            i++;
            j++;
        }else{
            if(Precedence(infix[i]) > Precedence(stackTop(sp))){
                push(sp,infix[i]);
                i++;
            }else{
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while(!isEmpty(sp)){
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
    free(sp->arr);
    free(sp);
 }


int main(){

    while(1){
        char infix[MAX_SIZE];
        printf("Enter any arithmetic operation: ");
        scanf("%s", &infix);
        if(infix[0] == '0'){
            exit(0);
        }
        printf("Infix Expression: %s\n",infix);
        printf("Postfix Expression is: %s\n",InfixToPostfix(infix));
        printf("Please enter 0 to exit the loop\n");
    }
    return 0;
}
