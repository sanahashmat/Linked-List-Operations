#include <stdio.h>
#include <stdlib.h>

// Structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to concatenate two linked lists
struct Node* concatenate(struct Node* head1, struct Node* head2) {
    // If the first list is empty, return the second list
    if (head1 == NULL) {
        return head2;
    }
    // If the second list is empty, return the first list
    if (head2 == NULL) {
        return head1;
    }

    // Traverse the first list to find the last node
    struct Node* current = head1;
    while (current->next != NULL) {
        current = current->next;
    }

    // Link the last node of the first list to the head of the second list
    current->next = head2;

    // Return the head of the combined list (which is still head1)
    return head1;
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to test the concatenation
int main() {
    // Create first linked list: 1 -> 3 -> 5 -> NULL
    struct Node* head1 = createNode(1);
    head1->next = createNode(3);
    head1->next->next = createNode(5);

    // Create second linked list: 2 -> 4 -> 6 -> NULL
    struct Node* head2 = createNode(2);
    head2->next = createNode(4);
    head2->next->next = createNode(6);

    printf("First List: ");
    displayList(head1);

    printf("Second List: ");
    displayList(head2);

    // Concatenate the two lists
    head1 = concatenate(head1, head2);

    printf("\nConcatenated List: ");
    displayList(head1);

    // Free allocated memory (omitted for brevity in this example but important for real applications)
    
    return 0;
}
