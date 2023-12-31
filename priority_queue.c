#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the priority queue
typedef struct {
    int data;
    int priority;
} Node;

// Structure to represent the priority queue
typedef struct {
    Node *array;
    int capacity;
    int size;
} PriorityQueue;

// Function to initialize a priority queue
PriorityQueue* initializePriorityQueue(int capacity) {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->array = (Node*)malloc(capacity * sizeof(Node));
    pq->capacity = capacity;
    pq->size = 0;
    return pq;
}

// Function to swap two nodes in the priority queue
void swap(Node* a, Node* b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree with the root at given index
void heapify(PriorityQueue* pq, int index) {
    int smallest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < pq->size && pq->array[leftChild].priority < pq->array[smallest].priority) {
        smallest = leftChild;
    }

    if (rightChild < pq->size && pq->array[rightChild].priority < pq->array[smallest].priority) {
        smallest = rightChild;
    }

    if (smallest != index) {
        swap(&pq->array[index], &pq->array[smallest]);
        heapify(pq, smallest);
    }
}

// Function to insert a new node into the priority queue
void insert(PriorityQueue* pq, int data, int priority) {
    if (pq->size == pq->capacity) {
        printf("Priority Queue is full. Cannot insert more elements.\n");
        return;
    }

    // Create a new node
    Node newNode;
    newNode.data = data;
    newNode.priority = priority;

    // Insert the new node at the end of the array
    int index = pq->size;
    pq->array[index] = newNode;

    // Fix the min-heap property
    while (index > 0 && pq->array[(index - 1) / 2].priority > pq->array[index].priority) {
        swap(&pq->array[index], &pq->array[(index - 1) / 2]);
        index = (index - 1) / 2;
    }

    // Increase the size of the priority queue
    pq->size++;
}

// Function to extract the node with the highest priority
Node extractMin(PriorityQueue* pq) {
    if (pq->size <= 0) {
        printf("Priority Queue is empty.\n");
        exit(1);
    }

    // The root of the heap has the minimum priority
    Node minNode = pq->array[0];

    // Replace the root with the last node
    pq->array[0] = pq->array[pq->size - 1];
    pq->size--;

    // Fix the min-heap property
    heapify(pq, 0);

    return minNode;
}

// Function to print the elements of the priority queue
void printPriorityQueue(PriorityQueue* pq) {
    printf("Priority Queue: ");
    for (int i = 0; i < pq->size; i++) {
        printf("(%d, %d) ", pq->array[i].data, pq->array[i].priority);
    }
    printf("\n");
}

// Function to check if the priority queue is empty
int isEmpty(PriorityQueue* pq) {
    return pq->size == 0;
}

// Driver program
int main() {
    // Initialize a priority queue with a capacity of 10
    PriorityQueue* pq = initializePriorityQueue(10);

    // Insert elements into the priority queue with associated priorities
    insert(pq, 10, 3);
    insert(pq, 20, 2);
    insert(pq, 15, 5);
    insert(pq, 25, 1);

    // Print the elements of the priority queue
    printPriorityQueue(pq);

    // Extract and print elements with the highest priority
    while (!isEmpty(pq)) {
        Node minNode = extractMin(pq);
        printf("Extracted: (%d, %d)\n", minNode.data, minNode.priority);
    }

    // Free the memory allocated for the priority queue
    free(pq->array);
    free(pq);

    return 0;
}
