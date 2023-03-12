#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *left, *right;
};
// Function to create a new node with the given data
struct Node *newNode(int data) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
// Function to insert a new node with the given data into the binary tree
struct Node *insert(struct Node *root, int data) {
    // If the tree is empty, return a new node
    if (root == NULL)
        return newNode(data);
    // Otherwise, move down the tree recursively
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    // Return the (unchanged) node pointer
    return root;
}
// Inorder traversal of the binary tree
void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
// Driver code to test the insertion
int main() {
    struct Node *root = NULL;
    // Insert nodes into the binary tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    // Print the inorder traversal of the binary tree
    printf("Inorder traversal: ");
    inorder(root);
    return 0;
}
