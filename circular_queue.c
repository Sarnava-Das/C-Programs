#include <stdio.h>
#include <stdlib.h>


struct CircularQueue {
    int *items;
    int front, rear, maxSize;
};



void initializeQueue(struct CircularQueue *q, int maxSize) {
    q->items = (int *)malloc(sizeof(int) * maxSize);
    q->front = -1;
    q->rear = -1;
    q->maxSize = maxSize;
}

int isFull(struct CircularQueue *q) {
    return (q->front == (q->rear + 1) % q->maxSize);
}

int isEmpty(struct CircularQueue *q) {
    return (q->front == -1 && q->rear == -1);
}

void enqueue(struct CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot insert element.\n");
        return;
    }

    if (isEmpty(q)) 
        q->front = q->rear = 0;
    else 
        q->rear = (q->rear + 1) % q->maxSize;
    

    q->items[q->rear] = value;
    printf("Element %d inserted successfully.\n", value);
}

int dequeue(struct CircularQueue *q) {
    int deletedValue;

    if (isEmpty(q)) {
        printf("Queue is empty. Cannot delete element.\n");
        return -1;
    }

    deletedValue = q->items[q->front];

    if (q->front == q->rear) 
        q->front = q->rear = -1;
    else 
        q->front = (q->front + 1) % q->maxSize;
    

    return deletedValue;
}

int frontValue(struct CircularQueue *q) {
    return q->items[q->front];
}

void display(struct CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Elements in the Circular Queue: ");
    int i = q->front;
    do {
        printf("%d ", q->items[i]);
        i = (i + 1) % q->maxSize;
    } while (i != (q->rear + 1) % q->maxSize);
    printf("\n");
}
int main() {
    struct CircularQueue queue;
    int maxSize, choice, value;

    printf("Enter the size of the Circular Queue: ");
    scanf("%d", &maxSize);

    initializeQueue(&queue, maxSize);

    do {
        printf("\nCircular Queue Operations:\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Front Element\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                enqueue(&queue, value);
                break;
            case 2:
                if (!isEmpty(&queue)) {
                    printf("Deleted Element: %d\n", dequeue(&queue));
                } else {
                    printf("Queue is empty\n");
                }
                break;
            case 3:
                if (!isEmpty(&queue)) {
                    printf("Front Element: %d\n", frontValue(&queue));
                } else {
                    printf("Queue is empty\n");
                }
                break;
            case 4:
                display(&queue);
                break;
            case 5:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    free(queue.items);

    return 0;
}
