#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


struct Stack {
    int top;
    unsigned capacity;
    int* array;
};


struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}


void push(struct Stack* stack, int value) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack is full. Cannot push.\n");
        return;
    }
    stack->array[++stack->top] = value;
}


int pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty. Cannot pop.\n");
       exit(1);
    }
    return stack->array[stack->top--];
}


int evaluatePostfix(char* postfix) {
    int length = strlen(postfix);
    struct Stack* stack = createStack(length);
    if (!stack)
    {   printf("Memory not allocated for stack\n");
        exit(1); 
    }

    for (int i = 0; i < length; i++) {
        char c = postfix[i];

        if (isdigit(c)) 
            push(stack, c - '0'); 
        else if (c == ' ' || c == '\t' || c =='\n') {
            // Ignore whitespace
        } else {
            int operand2 = pop(stack);
            int operand1 = pop(stack);
            int result;

            switch (c) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Division by zero is not allowed.\n");
                        exit(1);
                    }
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Invalid operator: %c\n", c);
                    exit(1);
            }

            push(stack, result);
        }
    }

    if (stack->top == 0) 
        return stack->array[0]; 
    else {
        printf("Invalid postfix expression.\n");
        exit(1);
    }
}

int main() {
    char postfix[100];
    printf("Enter a postfix expression: ");
    fgets(postfix, sizeof(postfix), stdin);

    // // Remove the newline character from the input
    // size_t len = strlen(postfix);
    // if (len > 0 && postfix[len - 1] == '\n') 
    //     postfix[len - 1] = '\0';
    
    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);
    

    return 0;
}
