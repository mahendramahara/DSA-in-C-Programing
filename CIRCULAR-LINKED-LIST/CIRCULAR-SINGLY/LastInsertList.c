#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node *next;
};

// Function to insert a node at the end of a circular linked list
struct Node *insertAtEnd(struct Node *last, int data) {
    // Create a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    // If the list is empty
    if (last == NULL) {
        newNode->next = newNode; // Point to itself
        last = newNode; // Make it the last node
    } else {
        newNode->next = last->next; // New node points to the current first node
        last->next = newNode; // Last node now points to the new first node
        last = newNode; // Update the last node to the newly added node
    }

    return last; // Return the updated last node
}

// Function to display the circular linked list
void displayList(struct Node *last) {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *current = last->next;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != last->next);
    printf("\n");
}

int main() {
	int i;
    struct Node *last = NULL; // Initialize an empty circular linked list
    int numNodes, nodeData;

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    for (i = 0; i < numNodes; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &nodeData);
        last = insertAtEnd(last, nodeData);
    }

    // Display the list
    printf("Circular Linked List: ");
    displayList(last);

    return 0;
}

