#include <stdio.h>
#include <stdlib.h>

// Structure for the stack node
typedef struct node {
    int data;
    struct node* next;
} Node;

Node* top = NULL;

// Push operation
void push(Node** top_ref, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory allocation failed!\n");
        return;
    }
    new_node->data = data;
    new_node->next = *top_ref;
    *top_ref = new_node;
}

// Pop operation
void pop(Node** top_ref) {
    if (*top_ref == NULL) {
        printf("Stack Underflow\n");
    } else {
        Node* temp = *top_ref;
        *top_ref = (*top_ref)->next;
        printf("Popped: %d\n", temp->data);
        free(temp);
    }
}

// Display stack
void display(Node* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements:\n");
        Node* temp = top;
        while (temp != NULL) {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

int main() {
    int choice, value;
    
    while (1) {
        printf("\n========== Stack Menu ==========");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\n\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&top, value);
                break;
            case 2:
                pop(&top);
                break;
            case 3:
                display(top);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
