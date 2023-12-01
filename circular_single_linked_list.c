#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}


void displayList(struct Node* head) {
    if (head == NULL) {
        printf("Circular linked list is empty.\n");
        return;
    }

    struct Node* current = head;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf(" (Head)\n");
}


struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

  
    struct Node* current = head;
    while (current->next != head) {
        current = current->next;
    }

   
    newNode->next = head;
    current->next = newNode;

    return newNode; 
}


struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        newNode->next = newNode; 
        return newNode;
    }

 
    struct Node* current = head;
    while (current->next != head) {
        current = current->next;
    }

  
    current->next = newNode;
    newNode->next = head; 

    return head; // Head remains unchanged
}


struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("Circular linked list is empty. Nothing to delete.\n");
        return NULL;
    }

    if (head->next == head) {
     
        free(head);
        return NULL;
    }

  
    struct Node* last = head;
    while (last->next != head) {
        last = last->next;
    }

   
    struct Node* newHead = head->next;
    last->next = newHead;
    free(head);

    return newHead; // New head after deletion
}


struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("Circular linked list is empty. Nothing to delete.\n");
        return NULL;
    }

    if (head->next == head) {
      
        free(head);
        return NULL;
    }

   
    struct Node* last = head;
    struct Node* secondLast = NULL;

    while (last->next != head) {
        secondLast = last;
        last = last->next;
    }

   
    secondLast->next = head;
    free(last);

    return head;
}
struct Node* deleteAfterNode(struct Node* head, int target) {
    if (head == NULL) {
        printf("Circular linked list is empty. Nothing to delete.\n");
        return NULL;
    }
  
    struct Node* current = head;
 
  do {
        if (current->data == target) 
            break;
            current = current->next;
    } while (current != head);

     if (current == head && current->data!=target) {
        printf("Target node not found in the circular doubly linked list. Nothing to delete.\n");
        return head;
    }
    if(current->next==current && current->data==target)
    {
        free(head);
        return NULL;
    }

	
	struct Node* temp = current->next;
    current->next = current->next->next;
    free(temp);
	
	if(current->next ==current)
     head = current;
	return head;
}
void deleteList(struct Node* head) {
    if (head == NULL) {
        return;
    }

    struct Node* current = head;
    struct Node* nextNode;

    do {
        nextNode = current->next;
        free(current);
        current = nextNode;
    } while (current != head);
}

int main() {
    struct Node* head = NULL;
    int choice, value, target;

    do {
      
        printf("\n---- Menu ----\n");
        printf("1. Create a circular linked list\n");
        printf("2. Display the elements of the circular linked list\n");
        printf("3. Insert a node at the beginning\n");
        printf("4. Insert a node at the end\n");
        printf("5. Delete a node from the beginning\n");
        printf("6. Delete a node from the end\n");
        printf("7. Delete a node after a given node\n");
        printf("8. Delete the entire circular linked list\n");
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
            
                head = deleteFromBeginning(head);
                break;

            case 6:
               
                head = deleteFromEnd(head);
                break;

            case 7:
              
                printf("Enter the target value: ");
                scanf("%d", &target);
                head = deleteAfterNode(head, target);
                break;

            case 8:
              
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
