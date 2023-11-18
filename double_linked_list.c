#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};


struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}


void displayList(struct Node* head) {
    if (head == NULL) {
        printf("Doubly linked list is empty.\n");
        return;
    }

    printf("NULL <-> ");
    struct Node* current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}


struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        return newNode;
    }

    newNode->next = head;
    head->prev = newNode;
    return newNode;
}


struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        return newNode;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
    return head;
}


struct Node* insertBeforeNode(struct Node* head, int value, int target) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        return newNode;
    }

    if (head->data == target) {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }

    struct Node* current = head;
    while (current != NULL && current->data != target) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Target node not found.\n");
        free(newNode);
        return head;
    }

    newNode->prev = current->prev;
    newNode->next = current;
    current->prev->next = newNode;
    current->prev = newNode;

    return head;
}


struct Node* insertAfterNode(struct Node* head, int value, int target) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        return newNode;
    }

    struct Node* current = head;
    while (current != NULL && current->data != target) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Target node not found.\n");
        free(newNode);
        return head;
    }

    newNode->prev = current;
    newNode->next = current->next;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;

    return head;
}


struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("Doubly linked list is empty. Nothing to delete.\n");
        return NULL;
    }

    struct Node* newHead = head->next;
    if (newHead != NULL) {
        newHead->prev = NULL;
    }
    free(head);
    return newHead;
}


struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("Doubly linked list is empty. Nothing to delete.\n");
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->prev->next = NULL;
    free(current);

    return head;
}


struct Node* deleteAfterNode(struct Node* head, int target) {
    if (head == NULL) {
        printf("Doubly linked list is empty. Nothing to delete.\n");
        return NULL;
    }

    struct Node* current = head;
    while (current != NULL && current->data != target) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Target node not found in the doubly linked list. Nothing to delete.\n");
        return head;
    }

    if (current->next != NULL) {
        struct Node* temp = current->next;
        current->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = current;
        }
        free(temp);
    } else {
        printf("No node after the target node to delete.\n");
    }

    return head;
}


void deleteList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    int choice, value, target;

    do {
      
        printf("\n---- Menu ----\n");
        printf("1. Create a doubly linked list\n");
        printf("2. Display the elements of the doubly linked list\n");
        printf("3. Insert a node at the beginning\n");
        printf("4. Insert a node at the end\n");
        printf("5. Insert a node before a given node\n");
        printf("6. Insert a node after a given node\n");
        printf("7. Delete a node from the beginning\n");
        printf("8. Delete a node from the end\n");
        printf("9. Delete a node after a given node\n");
        printf("10. Delete the entire doubly linked list\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
              
                printf("Enter the number of elements: ");
                scanf("%d", &value);
                for (int i = 0; i < value; i++) {
                    printf("Enter element %d: ", i + 1);
                    scanf("%d", &target);
                    head = insertAtEnd(head, target);
                }
                break;

            case 2:
         
                displayList(head);
                break;

            case 3:
          
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                head = insertAtBeginning(head, value);
                break;

            case 4:
             
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                head = insertAtEnd(head, value);
                break;

            case 5:
             
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the target value: ");
                scanf("%d", &target);
                head = insertBeforeNode(head, value, target);
                break;

            case 6:
            
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the target value: ");
                scanf("%d", &target);
                head = insertAfterNode(head, value, target);
                break;

            case 7:
            
                head = deleteFromBeginning(head);
                break;

            case 8:
             
                head = deleteFromEnd(head);
                break;

            case 9:
           
                printf("Enter the target value: ");
                scanf("%d", &target);
                head = deleteAfterNode(head, target);
                break;

            case 10:
           
                deleteList(head);
                head = NULL;
                break;

            case 0:
             
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    // Free any remaining memory before exiting
    deleteList(head);

    return 0;
}
