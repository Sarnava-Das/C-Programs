#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Queue {
    struct Node* front;
    struct Node* rear;
};


struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (!queue) {
        printf("Memory allocation error.\n");
        exit(1);
    }
    queue->front = queue->rear = NULL;
    return queue;
}


int isEmpty(struct Queue* queue) {
    return (queue->front == NULL && queue->rear==NULL);
}


void enqueue(struct Queue* queue, int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation error.\n");
        exit(1);
    }
    newNode->data = item;
    newNode->next = NULL;
    
    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("%d has been enqueued into the queue.\n", item);
}


int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
       exit(1);
    }
    int item = queue->front->data;
    struct Node* temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    return item;
}


int peep(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot peep.\n");
        return -1; 
    }
    return queue->front->data;
}


void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    struct Node* current = queue->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
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
               
                while (!isEmpty(queue)) {
                    dequeue(queue);
                }
                free(queue);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
