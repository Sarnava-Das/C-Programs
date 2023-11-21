#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int MAX_SIZE;
    int* array;
    int top;
};

void push(struct Stack* stack, int value) {
    if (stack->top == stack->MAX_SIZE - 1)
        printf("Stack is full. Cannot push.\n");
    else {
        stack->array[++stack->top] = value;
        printf("%d pushed into the stack.\n", value);
    }
}

void pop(struct Stack* stack) {
    if (stack->top == -1)
        printf("Stack is empty. Cannot pop.\n");
    else
        printf("%d popped from the stack.\n", stack->array[stack->top--]);
}

int peek(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty.\n");
        return -1;
    } else
        return stack->array[stack->top];
}

void display(struct Stack* stack) {
    if (stack->top == -1)
        printf("Stack is empty.\n");
    else {
        printf("Stack elements: ");
        for (int i = 0; i <= stack->top; i++)
            printf("%d ", stack->array[i]);
        printf("\n");
    }
}

int main() {
    struct Stack stack;
    printf("Enter the maximum size of the stack: ");
    scanf("%d", &stack.MAX_SIZE);

    stack.array = (int*)malloc(stack.MAX_SIZE * sizeof(int));

    if (stack.array == NULL) {
        printf("Memory allocation failed. Exiting program.\n");
        return 1;
    }

    stack.top = -1;

    while (1) {
        printf("\nStack Menu:\n");
        printf("1. Push an element\n");
        printf("2. Pop an element\n");
        printf("3. Peek at the top element\n");
        printf("4. Display stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        int choice, value;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                value = peek(&stack);
                if (value != -1) {
                    printf("Top element: %d\n", value);
                }
                break;
            case 4:
                display(&stack);
                break;
            case 5:
                free(stack.array); // Free the dynamically allocated memory before exiting
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
