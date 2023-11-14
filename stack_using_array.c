#include <stdio.h>
#include <stdlib.h>

int MAX_SIZE; 
int* stack;
int top = -1;


void push(int value) {
    if (top == MAX_SIZE - 1) 
        printf("Stack is full. Cannot push.\n");
     else {
        stack[++top] = value;
        printf("%d pushed into the stack.\n", value);
    }
}


void pop() {
    if (top == -1) 
        printf("Stack is empty. Cannot pop.\n");
    else 
        printf("%d popped from the stack.\n", stack[top--]);
    
}


int peek() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return -1; 
    } else 
        return stack[top];
    
}


void display() {
    if (top == -1) 
        printf("Stack is empty.\n");
    else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) 
            printf("%d ", stack[i]);
        
        printf("\n");
    }
}

int main() {
    printf("Enter the maximum size of the stack: ");
    scanf("%d", &MAX_SIZE);

    stack = (int*)malloc(MAX_SIZE * sizeof(int)); 
   
    if (stack == NULL) {
        printf("Memory allocation failed. Exiting program.\n");
        return 1; 
    }

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
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                value = peek();
                if (value != -1) {
                    printf("Top element: %d\n", value);
                }
                break;
            case 4:
                display();
                break;
            case 5:
                free(stack); // Free the dynamically allocated memory before exiting
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
