#include <stdio.h>
#include <stdlib.h>
// Structure for a binary tree node
struct Node
 {
    int data;
    struct Node *left, *right;
};
// Function to create a new node with the given data
struct Node *newNode(int data)
 {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
// Function to insert a new node with the given data into the binary tree
struct Node *insert(struct Node *root, int data)
 {
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
// Function to delete a node with the given key from the binary tree
struct Node *deleteNode(struct Node *root, int key) {
    if (root == NULL)
        return root;
    // Recur down the tree
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        // Node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct Node *temp = root->right;
        while (temp->left != NULL)
            temp = temp->left;
        // Copy the inorder successor's data to this node
        root->data = temp->data;
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
// Inorder traversal of the binary tree
void inorder(struct Node *root) 
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
// Driver code to test the deletion
int main() 
{
    struct Node *root = NULL;
    // Insert nodes into the binary tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    // Print the inorder traversal of the binary tree before deletion
    printf("Inorder traversal before deletion: ");
    inorder(root);
    // Delete a node (e.g., node with key 20)
    int keyToDelete = 20;
    root = deleteNode(root, keyToDelete);
    // Print the inorder traversal of the binary tree after deletion
    printf("\nInorder traversal after deletion of %d: ", keyToDelete);
    inorder(root);

    return 0;
}
