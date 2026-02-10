#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end of the list
void insertEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Function to split the linked list into two halves
void splitList(struct Node* head, struct Node** head1_ref, struct Node** head2_ref) {
    struct Node* fast_ptr = head;
    struct Node* slow_ptr = head;
    struct Node* prev_slow = NULL; // Pointer to the node before slow_ptr

    if (head == NULL || head->next == NULL) {
        *head1_ref = head;
        *head2_ref = NULL;
        return;
    }

    // Traverse the list: fast_ptr moves twice as fast as slow_ptr
    while (fast_ptr != NULL && fast_ptr->next != NULL) {
        prev_slow = slow_ptr;
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }

    // slow_ptr is now at the middle. Break the link to split the list.
    *head1_ref = head;
    *head2_ref = slow_ptr;
    
    // The previous node to slow_ptr points to NULL now
    if (prev_slow != NULL) {
        prev_slow->next = NULL;
    }
}

// Main function to test the program
int main() {
    struct Node* head = NULL;
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    // Build the list
    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 4);
    insertEnd(&head, 5);
    insertEnd(&head, 6);
    // Add another node for an odd-length list test
    // insertEnd(&head, 7); 

    printf("Original linked list: ");
    printList(head);

    // Split the list
    splitList(head, &head1, &head2);

    printf("First half linked list: ");
    printList(head1);

    printf("Second half linked list: ");
    printList(head2);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end of the list
void insertEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Function to split the linked list into two halves
void splitList(struct Node* head, struct Node** head1_ref, struct Node** head2_ref) {
    struct Node* fast_ptr = head;
    struct Node* slow_ptr = head;
    struct Node* prev_slow = NULL; // Pointer to the node before slow_ptr

    if (head == NULL || head->next == NULL) {
        *head1_ref = head;
        *head2_ref = NULL;
        return;
    }

    // Traverse the list: fast_ptr moves twice as fast as slow_ptr
    while (fast_ptr != NULL && fast_ptr->next != NULL) {
        prev_slow = slow_ptr;
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }

    // slow_ptr is now at the middle. Break the link to split the list.
    *head1_ref = head;
    *head2_ref = slow_ptr;
    
    // The previous node to slow_ptr points to NULL now
    if (prev_slow != NULL) {
        prev_slow->next = NULL;
    }
}

// Main function to test the program
int main() {
    struct Node* head = NULL;
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    // Build the list
    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 4);
    insertEnd(&head, 5);
    insertEnd(&head, 6);
    // Add another node for an odd-length list test
    // insertEnd(&head, 7); 

    printf("Original linked list: ");
    printList(head);

    // Split the list
    splitList(head, &head1, &head2);

    printf("First half linked list: ");
    printList(head1);

    printf("Second half linked list: ");
    printList(head2);

    return 0;
}
