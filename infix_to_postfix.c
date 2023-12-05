#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 

struct Stack {
    int top;
    unsigned capacity;
    char* array;
};


struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}


int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '%');
}


int precedence(char ch) {
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/' || ch == '%')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return -1; 
}


void push(struct Stack* stack, char ch) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack is full. Cannot push.\n");
        return;
    }
    stack->array[++stack->top] = ch;
}


char pop(struct Stack* stack) {
    if (stack->top == -1)
        return '\0'; 
    return stack->array[stack->top--];
}


char peek(struct Stack* stack) {
    if (stack->top == -1)
        return '\0'; 
    return stack->array[stack->top];
}


void infixToPostfix(char* infix) {
    int length = strlen(infix);
    struct Stack* stack = createStack(length);
    if (!stack)
        return;

    int outputIndex = 0;
    char output[length];

    for (int i = 0; i < length; i++) {
        char c = infix[i];

        if (isalnum(c)) {
            output[outputIndex++] = c;
        } else if (c == '(') {
            push(stack, c);
        } else if (c == ')') {
            while (peek(stack) != '\0' && peek(stack) != '(') {
                output[outputIndex++] = pop(stack);
            }
            if (peek(stack) == '(')
                pop(stack);
        } else if (isOperator(c)) {
            while (peek(stack) != '\0' && precedence(c) <= precedence(peek(stack))) {
                output[outputIndex++] = pop(stack);
            }
            push(stack, c);
        }
    }

    while (peek(stack) != '\0') {
        output[outputIndex++] = pop(stack);
    }
    output[outputIndex] = '\0';

    printf("Postfix expression: %s\n", output);
}

int main() {
    char infix[100];

    printf("Enter an infix expression: ");
    fgets(infix, sizeof(infix), stdin);

    infixToPostfix(infix);

    return 0;
}
