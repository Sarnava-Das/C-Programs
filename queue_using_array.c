#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

int capacity; 
struct Queue {
    int front, rear, size;
    int* array;
};

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (!queue) {
        printf("Memory allocation error.\n");
        exit(1);
    }
    queue->front = queue->rear = -1;
    queue->size = 0;
    queue->array = (int*)malloc(capacity * sizeof(int));
    if (!queue->array) {
        printf("Memory allocation error.\n");
        exit(1);
    }
    return queue;
}

int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}


int isFull(struct Queue* queue) {
    return (queue->size == capacity);
}


void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % capacity;
    queue->array[queue->rear] = item;
    queue->size++;
    printf("%d has been enqueued into the queue.\n", item);
}


int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; 
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % capacity;
    queue->size--;
    return item;
}


int peep(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot peep.\n");
        return -1; 
    }
    return queue->array[queue->front];
}


void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int i = queue->front;
    for (int count = 0; count < queue->size; count++) {
        printf("%d ", queue->array[i]);
        i = (i + 1) % capacity;
    }
    printf("\n");
}

int main() {
    printf("Enter the size of the queue: ");
    scanf("%d", &capacity);

    if (capacity <= 0 || capacity > MAX_SIZE) {
        printf("Invalid capacity. Please enter a positive integer less than or equal to %d.\n", MAX_SIZE);
        return 1;
    }

    struct Queue* queue = createQueue();
    int choice, item;

    while (1) {
        printf("\nQueue Menu:\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Peep (Front element)\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &item);
                enqueue(queue, item);
                break;
            case 2:
                item = dequeue(queue);
                if (item != -1) {
                    printf("Dequeued element: %d\n", item);
                }
                break;
            case 3:
                item = peep(queue);
                if (item != -1) {
                    printf("Front element: %d\n", item);
                }
                break;
            case 4:
                display(queue);
                break;
            case 5:
                free(queue->array);
                free(queue);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
