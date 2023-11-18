#include <stdio.h>
#include <stdlib.h>


struct Queue {
    int *array;
    int front, rear, maxSize;
};


void initializeQueue(struct Queue *queue, int maxSize) {
    queue->array = (int *)malloc(maxSize * sizeof(int));
    if (queue->array == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    queue->front = -1;
    queue->rear = -1;
    queue->maxSize = maxSize;
}


int isEmpty(struct Queue *queue) {
    return (queue->front == -1 && queue->rear == -1);
}


int isFull(struct Queue *queue) {
    return (queue->rear == queue->maxSize - 1);
}


void enqueue(struct Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (isEmpty(queue)) 
        queue->front = 0;
    

   
    queue->array[++queue->rear] = value;
    printf("Enqueued: %d\n", value);
}


void dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    printf("Dequeued: %d\n", queue->array[queue->front]);

    if (queue->front == queue->rear) {
      
        queue->front = -1;
        queue->rear = -1;
    } 
    else 
        queue->front++;
    
}


void peep(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot peep.\n");
        return;
    }

    printf("Peep: %d\n", queue->array[queue->front]);
}


void displayQueue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->array[i]);
    }

    printf("\n");
}

int main() {
    struct Queue queue;
    int maxSize, choice, value;

   
    printf("Enter the maximum size of the queue: ");
    scanf("%d", &maxSize);

    initializeQueue(&queue, maxSize);

    do {
    
        printf("\n---- Menu ----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peep\n");
        printf("4. Display Queue\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
               
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(&queue, value);
                break;

            case 2:
             
                dequeue(&queue);
                break;

            case 3:
              
                peep(&queue);
                break;

            case 4:
              
                displayQueue(&queue);
                break;

            case 0:
            
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    
    free(queue.array);

    return 0;
}
