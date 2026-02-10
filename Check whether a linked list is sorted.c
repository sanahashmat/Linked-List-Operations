#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a structure for the linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to check if the linked list is sorted in ascending order
bool isSorted(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        // An empty list or a list with a single node is always sorted
        return true;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        // Compare the current node's data with the next node's data
        if (current->data > current->next->data) {
            // If the current node is greater than the next, it's not sorted
            return false;
        }
        current = current->next;
    }

    // If the loop completes without returning false, the list is sorted
    return true;
}

// Function to print the linked list (for verification)
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate the logic
int main() {
    // --- Example 1: Sorted list ---
    struct Node* head1 = createNode(10);
    head1->next = createNode(20);
    head1->next->next = createNode(30);
    head1->next->next->next = createNode(40);

    printf("List 1: ");
    printList(head1);
    if (isSorted(head1)) {
        printf("List 1 is sorted.\n");
    } else {
        printf("List 1 is not sorted.\n");
    }

    printf("\n");

    // --- Example 2: Unsorted list ---
    struct Node* head2 = createNode(15);
    head2->next = createNode(25);
    head2->next->next = createNode(10); // Out of order
    head2->next->next->next = createNode(30);

    printf("List 2: ");
    printList(head2);
    if (isSorted(head2)) {
        printf("List 2 is sorted.\n");
    } else {
        printf("List 2 is not sorted.\n");
    }

    // Free the allocated memory (important for good practice)
    free(head1->next->next->next);
    free(head1->next->next);
    free(head1->next);
    free(head1);

    free(head2->next->next->next);
    free(head2->next->next);
    free(head2->next);
    free(head2);

    return 0;
}
