#include<stdio.h>
#include<stdlib.h>

// Structure defining a node in a singly linked list
struct Node {
    int data;           // Data stored in the node
    struct Node* next;  // Pointer to the next node
};

// Function to create a new node with given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));  // Allocate memory for a new node
    node->data = data;  // Assign data to the new node
    node->next = NULL;  // Set the next pointer to NULL
    return node;  // Return the newly created node
}

// Function to remove duplicates from a sorted linked list
void remove_Duplicates(struct Node* head) {
    if (head == NULL) {
        return;  // If the list is empty, return
    }

    struct Node* curr = head;  // Current pointer initialized to the head

    while (curr->next != NULL) {  // Traverse the list until the end
        if (curr->data == curr->next->data) {  // Check if current node's data is the same as the next node's data
            struct Node* temp = curr->next;  // Store the duplicate node in a temporary pointer
            curr->next = curr->next->next;  // Remove the duplicate node by skipping it
            free(temp);  // Free the memory occupied by the duplicate node
        } else {
            curr = curr->next;  // Move to the next node if there are no duplicates
        }
    }
}

// Function to print the elements of a linked list
void displayList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);  // Print the data of the current node
        head = head->next;  // Move to the next node
    }
    printf("\n");
}

// Main function to demonstrate removing duplicates from a sorted linked list
int main() {
    struct Node* head = newNode(1);  // Create a linked list with sample data
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(3);
    head->next->next->next->next = newNode(5);
    head->next->next->next->next->next = newNode(6);
    head->next->next->next->next->next->next = newNode(6);

    printf("Original sorted singly linked list:\n");
    displayList(head);  // Display the original list

    printf("\nAfter removing duplicates from the said sorted linked list:\n");
    remove_Duplicates(head);  // Remove duplicates
    displayList(head);  // Display the list after removing duplicates

    return 0;
}
