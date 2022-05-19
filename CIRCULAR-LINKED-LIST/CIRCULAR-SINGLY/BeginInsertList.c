#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *insertAtBeginning(struct Node *last, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    if (last == NULL) {
        newNode->next = newNode;
        last = newNode;
    } else {
        newNode->next = last->next;
        last->next = newNode;
    }

    return last;
}

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
    struct Node *last = NULL;
    int nodeData, numNodes;

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    for (i = 0; i < numNodes; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &nodeData);
        last = insertAtBeginning(last, nodeData);
    }

    printf("Circular Linked List: ");
    displayList(last);

    return 0;
}

