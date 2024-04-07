#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct stack{
    char items[50];
    int top;
}Stack;

void push(Stack* sp, char c){
    if(sp->top == 49){
        printf("Stack Overflow!!\n");
        exit(1);
    }
    sp->items[++(sp->top)] = c;
}

char pop(Stack* sp){
    if(sp->top == -1){
        printf("Stack Underflow!!\n");
        exit(1);
    }
    return sp->items[(sp->top)--];
}

int isOperator(char c){
    return(c == '^' || c == '$' || c == '*' || c == '/' || c == '+' || c == '-');
}

int isalnum1(char ch){
    return (isalpha(ch) || isdigit(ch));
}

int precedence(char c){
    switch(c){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
        case '$':
            return 3;
        default:
            return 0;
    }
}

void infixToPostFix(char infix[], char postfix[]){
    Stack s;
    s.top = -1;
    int i,j = 0;

    for(i = 0; infix[i] != '\0'; i++){
        if(isalnum(infix[i])){
            postfix[j] = infix[i];
            j++;
        }else if(infix[i] == '('){
            push(&s, '(');
        }else if(infix[i] == ')'){
            while(s.top != -1 && s.items[s.top] != '('){
                postfix[j] = pop(&s);
                j++;
            }
            if(s.top == -1){
                printf("Invalid infix expression");
                exit(1);
            }
            pop(&s); // popping the '(' 
            }
            else if(isOperator(infix[i])){
                while(precedence(infix[i]) <= precedence(s.items[s.top]) && s.top != -1){
                    postfix[j] = pop(&s);
                    j++;
                }
                push(&s, infix[i]);
            }
    }

    while(s.top != -1){
        postfix[j] = pop(&s);
        j++;
    }
    postfix[j] = '\0';
}

int evaluatePostfix(char postfix[]){
    Stack s;
    s.top = -1;
    int i, op1, op2, result;
    for (i = 0; postfix[i] != '\0'; i++){
        if(isalnum1(postfix[i])){
            push(&s, postfix[i] - '0'); // convert character into integer and push
        }else{
            op2 = pop(&s);
            op1 = pop(&s);

            switch(postfix[i]){
                case '+':
                    result = op1 + op2;
                    break;
                case '-':
                    result = op1 - op2;
                    break;
                case '*':
                    result = op1 * op2;
                    break;
                case '/':
                    if(op2 == 0){
                        printf("Error: Division by zero.\n");
                        exit(1);
                    }
                    result = op1 / op2;
                    break;
                case '^':
                case '$':
                    result = op1 ^ op2;
                    break;

                default:
                    printf("Invalid postfix expression\n");
                    exit(1);
            }
            push(&s, result);
        }
    }
    return (pop(&s));
}

int main(){
    

    while(1){

    char infix[25];
    char postfix[25];
    printf("Enter a valid infix expression :");
    scanf("%s", infix);
    if(infix[0] == '0'){
        exit(0);
    }

    infixToPostFix(infix,postfix);

    printf("Postfix is: %s\n", postfix);

    int result = evaluatePostfix(postfix);

    printf("Result : %d\n", result);
    printf("Please enter 0 to exit.\n");
    }
    return 0;
}
